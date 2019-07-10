/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:21:58 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 11:54:29 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**env_to_tab(t_list **aenv)
{
	char			**ret;
	t_list			*tmp;
	int				len;
	int				i;

	len = 0;
	i = 0;
	tmp = *aenv;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	if (len < 1 || !(ret = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
		return (NULL);
	tmp = *aenv;
	while (tmp)
	{
		ret[i] = get_env_string(tmp);
		tmp = tmp->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int			exec_cmd(t_data *data, char *path, char **args)
{
	pid_t	pid;
	char	**envp;
	int		status;

	envp = env_to_tab(&(data->env));
	args = flush_args(&(data->env), args);
	pid = fork();
	if (pid == 0)
	{
		execve(path, args, envp);
		exit(0);
	}
	else if (pid < 0)
	{
		ft_strdel(&path);
		ft_printf("fork() failed\n");
		return (1);
	}
	wait(&status);
	ft_strdel(&path);
	ft_deltab(&envp);
	return (1);
}

int			exec_check(t_data *data, char *path, struct stat l, char **args)
{
	if (l.st_mode & S_IFREG)
	{
		if (l.st_mode & S_IXUSR)
			return (exec_cmd(data, path, args));
		else
			ft_error(path, 0);
		ft_strdel(&path);
		return (1);
	}
	ft_strdel(&path);
	ft_error(args[0], 1);
	return (0);
}

char		*ft_get_path(char **arr, char **args, int i)
{
	char			*path;

	if (!args[0])
		return (NULL);
	if (ft_strchr(args[0], '/'))
		path = ft_strdup(args[0]);
	else
	{
		if (!(path = ft_strjoin(arr[i], "/")))
			return (NULL);
		path = ft_strjoinf(path, args[0]);
	}
	return (path);
}

int			exec_bins(t_data *data, char **args)
{
	char			**arr;
	char			*path;
	struct stat		l;
	int				i;

	arr = ft_strsplit(search_env(&(data->env), "PATH"), ':');
	i = 0;
	if (!arr && lstat(args[0], &l) != -1)
		return (exec_check(data, ft_strdup(args[0]), l, args));
	while (arr && arr[i])
	{
		path = ft_get_path(arr, args, i);
		if (lstat(path, &l) != -1)
		{
			ft_deltab(&arr);
			return (exec_check(data, path, l, args));
		}
		ft_strdel(&path);
		i++;
	}
	ft_deltab(&arr);
	ft_error(args[0], 2);
	return (0);
}
