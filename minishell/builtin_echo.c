/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:05:59 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 07:56:57 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	echo builtin
*/

void		echo_builtin(t_list **aenv, char **args)
{
	int			i;
	int			off;

	i = 0;
	while (args && args[i])
	{
		if (i > 1)
			ft_printf(" ");
		if (i > 0)
		{
			off = expand_home(aenv, args[i]);
			ft_printf("%s", expand_env(aenv, args[i] + off));
		}
		i++;
	}
	ft_printf("\n");
}
