/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:07:05 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 07:40:47 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	exit builtin
*/

void		env_del(void *env, size_t size)
{
	t_env		cont;

	cont = *(t_env*)env;
	ft_strdel(&(cont.var));
	ft_strdel(&(cont.val));
	ft_memdel(&env);
	size = 0;
	(void)size;
}

void		exit_builtin(t_data *data, char **args, char ***r)
{
	ft_deltab(r);
	ft_deltab(&args);
	ft_lstdel(&(data->env), env_del);
	ft_strdel(&(data->ctrim));
	ft_strdel(&(data->atrim));
	ft_printf("Please use me...\n");
	exit(0);
}
