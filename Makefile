# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 06:16:18 by lucasdebarn       #+#    #+#              #
#    Updated: 2025/11/12 06:49:47 by lucasdebarn      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

#library
LIBFT = ../libft/libft.a
PRINTF = ../ft_printf/ft_printf.a

#Directory
OBJ_DIR = object
SRC_DIR = src

#Files src
SRCS =	$(SRC_DIR)/ft_error.c \
		$(SRC_DIR)/pipex.c \
		$(SRC_DIR)/pipex_utils.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

#Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I ./

#Custom
COMPILE_MSG = @printf "."

#creations .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(COMPILE_MSG)

#Compilation
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "\n✅ Compilation terminée !"

$(LIBFT):
	@$(MAKE) -C ../libft
$(PRINTF):
	@(MAKE) -C ../ft_printf

all: $(LIBFT) $(PRINTF) $(NAME)

#Cleaning
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C ../libft clean
	@$(MAKE) -C ../printf clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ../libft fclean
	@$(MAKE) -C ../printf fclean

re: fclean all

.PHONY: all clean fclean re
