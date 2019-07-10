/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 08:55:23 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 11:54:58 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*process_path(t_list **aenv, char *path)
{
	char		*home;
	char		*var;

	home = search_env(aenv, "HOME");
	if (!path)
		return (NULL);
	if (!ft_strlen(path) || (path[0] != '~' && path[0] != '$'))
		return (ft_strdup(path));
	else if (path[0] == '$')
	{
		var = search_env(aenv, path + 1);
		if (var)
			return (ft_strdup(var));
		return (NULL);
	}
	else if (path[0] == '~')
	{
		if (home)
			return (ft_strjoin(home, path + 1));
		return (NULL);
	}
	return (NULL);
}

char		**flush_args(t_list **aenv, char **args)
{
	int			i;
	char		*tmp;

	i = 0;
	if (!args)
		return (NULL);
	while (args[i])
	{
		tmp = process_path(aenv, args[i]);
		if (tmp)
		{
			ft_strdel(&args[i]);
			args[i] = tmp;
		}
		i++;
	}
	return (args);
}
