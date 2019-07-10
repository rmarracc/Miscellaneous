/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:01:04 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 09:51:41 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	envp to chained list
*/

char		*ft_strreplace(char *s, char c1, char c2)
{
	int			j;

	j = 0;
	if (s)
	{
		while (s[j] != '\0')
		{
			if (s[j] == c1)
				s[j] = c2;
			j++;
		}
	}
	return (s);
}

void		ft_get_env(char **envp, t_list **addr)
{
	static int	i = 0;
	t_list		*elem;
	t_env		curr;

	while (envp[i] != NULL)
	{
		if (ft_strchr(envp[i], '='))
		{
			if (!(curr.val = ft_strdup(ft_strchr(envp[i], '=') + 1)))
				break ;
			envp[i] = ft_strreplace(envp[i], '=', '\0');
			if (!(curr.var = ft_strdup(envp[i])))
				ft_strdel(&(curr.val));
			if (!(elem = ft_lstnew(&curr, sizeof(curr))))
			{
				ft_strdel(&(curr.val));
				ft_strdel(&(curr.var));
			}
			if (!(*addr) && elem)
				*addr = elem;
			else if (elem)
				ft_lstadd(addr, elem);
		}
		i++;
	}
}
