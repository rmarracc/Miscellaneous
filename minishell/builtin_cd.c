/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:04:00 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 11:42:09 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	cd builtin
*/

int		ft_cd(t_list **aenv, char *pathd, int prev)
{
	char	*old;
	char	*path;
	char	buf[SIZEPATH + 1];

	ft_bzero(buf, SIZEPATH + 1);
	old = getcwd(buf, SIZEPATH);
	path = process_path(aenv, pathd);
	if (path && chdir(path) != -1)
	{
		if (prev)
			ft_printf("%s\n", path);
		ft_set_env(aenv, "OLDPWD", old);
		old = getcwd(buf, SIZEPATH);
		ft_set_env(aenv, "PWD", old);
		ft_strdel(&path);
		return (0);
	}
	if (path && access(path, F_OK) < 0)
		ft_error(path, 4);
	else if (path && access(path, R_OK) < 0)
		ft_error(path, 0);
	else if (path)
		ft_error(path, 3);
	ft_strdel(&path);
	return (1);
}

int		ft_cd_builtin(t_list **aenv, char *path, int tl)
{
	char	*home;
	char	*old;

	old = search_env(aenv, "OLDPWD");
	if (tl == 2 && ft_strcmp(path, "-") && ft_strcmp(path, "--"))
		return (ft_cd(aenv, path, 0));
	else if (tl == 2 && !ft_strcmp(path, "-") && old)
		return (ft_cd(aenv, old, 1));
	else if (tl == 2 && !ft_strcmp(path, "-") && !old)
		return (-1);
	home = search_env(aenv, "HOME");
	if (!home)
		return (-1);
	else if (tl < 2 || !ft_strcmp(path, "--"))
		return (ft_cd(aenv, home, 0));
	return (-1);
}
