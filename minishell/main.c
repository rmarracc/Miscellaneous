/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:19:52 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/05 09:10:52 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	main
*/

int			main(int argc, char **argv, char **envp)
{
	t_data		data;

	(void)argc;
	(void)argv;
	print_header();
	data.env = NULL;
	ft_get_env(envp, &(data.env));
	read_input(&data);
	return (0);
}
