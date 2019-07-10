#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 09:56:48 by rmarracc          #+#    #+#              #
#    Updated: 2019/02/07 11:40:45 by rmarracc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell
SRC = main.c get_env.c builtin_env.c builtin_cd.c builtin_setenv.c builtin_unsetenv.c builtin_echo.c builtin_exit.c get_builtin.c parse_input.c exec_command.c fct_annexe.c expansions.c
OBJ = $(SRC:.c=.o)
CC = gcc
SANITIZE = -fsanitize=address
DEBUG = 0
ifeq ($(DEBUG), 1)
	CFLAGS = -Wall -Wextra -I. -g3
else
	CFLAGS = -Wall -Wextra -Werror -I.
endif

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

clean :
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean : clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
