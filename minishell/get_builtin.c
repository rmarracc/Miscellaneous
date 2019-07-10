/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:08:32 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 07:44:46 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Execute builtin or commands
*/

int			tab_len(char **grid)
{
	int			i;

	i = 0;
	if (!grid)
		return (0);
	while (grid[i])
		i++;
	return (i);
}

int			get_builtin2(t_data *data, char **args, int tl, char ***r)
{
	if (!ft_strcmp(args[0], "exit"))
	{
		if (tl != 1)
			return (ft_printf("usage: exit\n"));
		else
			exit_builtin(data, args, r);
	}
	else if (!ft_strcmp(args[0], "unsetenv"))
	{
		if (tl != 2)
			return (ft_printf("usage: unsetenv [var]\n"));
		else
			ft_unset_env(&(data->env), args[1]);
	}
	else if (!ft_strcmp(args[0], "cd"))
	{
		if (tl > 2 || tl < 1)
			return (ft_printf("usage: cd (path)\n"));
		else
			ft_cd_builtin(&(data->env), args[1], tl);
	}
	return (1);
}

int			get_builtin(t_data *data, char **args, int tl, char ***r)
{
	if (ft_strcmp(args[0], "echo") && ft_strcmp(args[0], "env")
		&& ft_strcmp(args[0], "setenv") && ft_strcmp(args[0], "cd")
		&& ft_strcmp(args[0], "unsetenv") && ft_strcmp(args[0], "exit"))
		return (0);
	else if (!ft_strcmp(args[0], "echo"))
		echo_builtin(&(data->env), args);
	else if (!ft_strcmp(args[0], "env"))
	{
		if (tl != 1)
			return (ft_printf("usage: env\n"));
		else
			ft_print_env(data->env);
	}
	else if (!ft_strcmp(args[0], "setenv"))
	{
		if (tl != 3)
			return (ft_printf("usage: setenv [var] [val]\n"));
		else
			ft_set_env(&(data->env), args[1], args[2]);
	}
	return (get_builtin2(data, args, tl, r));
}

void		process_cmd(t_data *data, char *command, char ***r)
{
	char		**args;
	int			tl;
	int			ret;

	if (!(args = ft_strsplit(command, ' ')))
		return ;
	if (!(tl = tab_len(args)))
	{
		ft_deltab(&args);
		return ;
	}
	ret = get_builtin(data, args, tl, r);
	if (!ret)
		ret = exec_bins(data, args);
	ft_deltab(&args);
}
