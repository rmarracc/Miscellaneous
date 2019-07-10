/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:04:00 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 11:38:25 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	setenv builtin
*/

int			seek_env(t_list **aenv, t_env *curr)
{
	t_list		*tmp;
	t_env		*cont;

	tmp = *aenv;
	if (!(curr->val))
		return (1);
	while (tmp)
	{
		cont = (t_env*)tmp->content;
		if (!ft_strcmp(cont->var, curr->var))
		{
			ft_strdel(&(cont->val));
			cont->val = curr->val;
			ft_strdel(&(curr->var));
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		ft_set_env(t_list **aenv, char *var, char *val)
{
	t_env		curr;
	t_list		*tmp;

	if (!val || !var)
		return ;
	if (ft_strchr(var, '='))
	{
		ft_putstr_fd("setenv: var can't contain '='\n", 2);
		return ;
	}
	tmp = *aenv;
	curr.val = ft_strdup(val);
	if (!(curr.var = process_path(aenv, var)))
		ft_strdel(&(curr.val));
	if (seek_env(aenv, &curr))
		return ;
	if (!(tmp = ft_lstnew(&curr, sizeof(curr))))
	{
		ft_strdel(&(curr.val));
		ft_strdel(&(curr.var));
	}
	if (!(*aenv) && tmp)
		*aenv = tmp;
	else if (tmp)
		ft_bs_lstpushback(aenv, tmp);
}
