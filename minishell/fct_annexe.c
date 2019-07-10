/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_annexe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 07:29:54 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 08:38:40 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*search_env(t_list **aenv, char *seek)
{
	t_list			*tmp;
	t_env			*cont;

	tmp = *aenv;
	if (!seek)
		return (NULL);
	while (tmp)
	{
		cont = (t_env*)tmp->content;
		if (!ft_strcmp(cont->var, seek))
			return (cont->val);
		tmp = tmp->next;
	}
	return (NULL);
}

char		*get_env_string(t_list *env)
{
	char			*ret;
	t_env			cont;

	cont = *(t_env*)env->content;
	ret = ft_strjoin(cont.var, "=");
	if (!ret)
		return (NULL);
	ret = ft_strjoinf(ret, cont.val);
	return (ret);
}

char		*expand_env(t_list **aenv, char *path)
{
	char			*ret;

	if (!path)
		return (NULL);
	else if (ft_strlen(path) < 2 || path[0] != '$')
		return (path);
	else
		ret = search_env(aenv, path + 1);
	if (!ret)
		return ("");
	else
		return (ret);
}

int			expand_home(t_list **aenv, char *path)
{
	char			*ret;

	if (!path)
		return (0);
	else if (ft_strlen(path) < 1 || path[0] != '~')
		return (0);
	else
		ret = search_env(aenv, "HOME");
	if (ft_strlen(path) >= 2 && path[1] == '~')
		return (0);
	else if (!ret)
		return (0);
	ft_putstr(ret);
	return (1);
}

void		ft_error(char *str, int eno)
{
	ft_putstr_fd(str, 2);
	if (eno == 0)
		ft_putstr_fd(": permission denied\n", 2);
	else if (eno == 1)
		ft_putstr_fd(": is a directory\n", 2);
	else if (eno == 2)
		ft_putstr_fd(": command not found\n", 2);
	else if (eno == 3)
		ft_putstr_fd(": not a directory\n", 2);
	else if (eno == 4)
		ft_putstr_fd(": no such file or directory\n", 2);
}
