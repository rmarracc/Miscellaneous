/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:04:00 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/05 09:04:22 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	unsetenv builtin
*/

void		ft_unset_env(t_list **aenv, char *var)
{
	t_list		*tmp;
	t_list		*prev;
	t_list		*next;
	t_env		*cont;

	tmp = *aenv;
	prev = NULL;
	while (var && tmp)
	{
		next = tmp->next;
		cont = (t_env*)tmp->content;
		if (!ft_strcmp(cont->var, var))
		{
			ft_lstdelone(&tmp, env_del);
			if (prev)
				prev->next = next;
			else
				*aenv = next;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	ft_printf("unsetenv: var '%s' doesn't exist\n", var);
}
