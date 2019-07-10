/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:10:34 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 09:35:45 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	welcome header and instruction parsing
*/

void		print_header(void)
{
	char		c;

	ft_printf("\033[94mWelcome to rmarracc's minishell\033[0m\n");
	if (read(0, &c, 0) < 0)
	{
		ft_printf("\033[91mError : Can't read STDIN\033[0m\n");
		exit(0);
	}
}

char		*ft_strtrimfree(char *s)
{
	char		*ret;

	ret = ft_strtrim(s);
	ft_strdel(&s);
	return (ret);
}

void		array_tabtospace(char ***arr)
{
	int			i;
	char		**tmp;

	i = 0;
	tmp = *arr;
	while (tmp[i])
	{
		tmp[i] = ft_strreplace(tmp[i], '\t', ' ');
		i++;
	}
}

void		process_input(t_data *data, char *command)
{
	char		**cmds;
	int			i;

	i = 0;
	data->atrim = NULL;
	cmds = ft_strsplit(command, ';');
	if (!cmds)
		return ;
	array_tabtospace(&cmds);
	while (cmds[i])
	{
		data->atrim = ft_strtrim(cmds[i]);
		if (!(data->atrim == NULL || ft_strlen(data->atrim) == 0))
			process_cmd(data, data->atrim, &cmds);
		ft_strdel(&(data->atrim));
		i++;
	}
	ft_deltab(&cmds);
}

void		read_input(t_data *data)
{
	char		*input;
	int			ret;

	input = NULL;
	data->ctrim = NULL;
	while (69)
	{
		ft_printf("%s", PROMPT);
		ret = sget_next_line(0, &input);
		if (ret <= 0)
		{
			ft_lstdel(&(data->env), env_del);
			exit(0);
		}
		if ((data->ctrim = ft_strtrimfree(input)) == NULL
			|| ft_strlen(data->ctrim) == 0)
		{
			ft_strdel(&(data->ctrim));
			continue ;
		}
		process_input(data, data->ctrim);
		ft_strdel(&(data->ctrim));
	}
}
