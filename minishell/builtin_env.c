/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:02:16 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/05 09:02:34 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	env builtin
*/

void		ft_print_env(t_list *env)
{
	t_list		*tmp;
	t_env		set;

	tmp = env;
	while (tmp)
	{
		set = *(t_env*)tmp->content;
		ft_printf("%s=%s\n", set.var, set.val);
		tmp = tmp->next;
	}
}
