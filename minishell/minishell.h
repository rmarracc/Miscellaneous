/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:17:42 by rmarracc          #+#    #+#             */
/*   Updated: 2019/02/07 11:54:11 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>

# define PROMPT "\033[95m$\033[96m>\033[0m "
# define SIZEPATH 4096

typedef struct		s_env
{
	char			*var;
	char			*val;
}					t_env;

typedef struct		s_data
{
	t_list			*env;
	char			*ctrim;
	char			*atrim;
}					t_data;

char				*ft_strreplace(char *s, char c1, char c2);
void				ft_get_env(char **envp, t_list **addr);
void				ft_print_env(t_list *env);
int					seek_env(t_list **aenv, t_env *curr);
void				ft_set_env(t_list **aenv, char *var, char *val);
void				echo_builtin(t_list **aenv, char **args);
void				env_del(void *env, size_t size);
void				exit_builtin(t_data *data, char **args, char ***r);
int					tab_len(char **grid);
int					get_builtin2(t_data *data, char **args, int tl, char ***r);
int					get_builtin(t_data *data, char **args, int tl, char ***r);
void				process_cmd(t_data *data, char *command, char ***r);
void				print_header(void);
char				*ft_strtrimfree(char *s);
void				array_tabtospace(char ***arr);
void				process_input(t_data *data, char *command);
void				read_input(t_data *data);
int					exec_bins(t_data *data, char **args);
void				ft_unset_env(t_list **aenv, char *var);
int					ft_cd_builtin(t_list **aenv, char *path, int tl);
int					ft_cd(t_list **aenv, char *pathd, int prev);
char				*search_env(t_list **aenv, char *seek);
char				*get_env_string(t_list *env);
char				*expand_env(t_list **aenv, char *path);
int					expand_home(t_list **aenv, char *path);
void				ft_error(char *str, int eno);
char				*process_path(t_list **aenv, char *path);
char				**flush_args(t_list **aenv, char **args);

#endif
