# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enikel <enikel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 11:24:40 by enikel            #+#    #+#              #
#    Updated: 2018/09/27 09:03:49 by enikel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

INC_DIR := inc

SRC_DIR := src

OBJ_DIR := obj

LIB_DIR := lib

SRC := minishell.c ft_printcolour.c ms_printprompt.c ms_cmd_all.c ms_cmd_echo.c \
ms_get_av.c ms_err.c ms_arg_split.c ms_cmd_env.c ms_env_mlc.c ms_free_tab.c \
ms_sub_var.c ms_argscnt.c ms_cmd_setenv.c ms_env_size.c ms_new_env.c \
ft_strjoin_mult.c ms_find_env.c ms_cmd_unsetenv.c

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

LIBFT_DIR := $(LIB_DIR)/libft

CFLAGS := -Wall -Werror -Wextra

CC := @gcc $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	@make all -C $(LIBFT_DIR)/
	@ar rcs $(NAME).a $(OBJ) $(LIBFT_DIR)/*.o

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I $(INC_DIR) -o $@ -c $<

shell: re
	@$(CC) $(NAME).a -o $(NAME)

clean: cleanlib
	@rm -rf $(OBJ_DIR)

cleanlib:
	@make clean -C $(LIBFT_DIR)/

fclean: clean fcleanlib
	@rm -f $(NAME).a
	@rm -f $(NAME)

fcleanlib:
	@make fclean -C $(LIBFT_DIR)/

re: fclean all

.PHONEY := all clean fclean re

.PRECIOUS := author
