# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 06:16:18 by lucasdebarn       #+#    #+#              #
#    Updated: 2025/11/18 17:38:00 by ludebarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

#library
LIBFT = ../libft
PRINTF = ../printf

#Directory
OBJ_DIR = object
SRC_DIR = src
GNL_DIR = GNL

#Files src
SRCS =	$(SRC_DIR)/ft_error.c \
		$(SRC_DIR)/pipex.c \
		$(SRC_DIR)/pipex_utils.c \
		$(SRC_DIR)/crea_process2.c \
		$(SRC_DIR)/pipex_utils2.c \
		$(GNL_DIR)/get_next_line_utils.c \
		$(GNL_DIR)/get_next_line.c \

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

#Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I . -I $(LIBFT) -I $(PRINTF)/
LIBRARYPATH = -L$(LIBFT) -L$(PRINTF)
LIBRARIES = -lft

#Custom
COMPILE_MSG = @printf "."

#creations .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(COMPILE_MSG)

#Compilation
$(NAME): $(OBJS)

	@make -s -C $(LIBFT)
	@make -s -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARYPATH) $(LIBRARIES) -o $(NAME)
	@echo "\n✅ Compilation terminée !"


all: $(LIBFT) $(PRINTF) $(NAME)

#Cleaning
clean:
	@rm -rf $(OBJ_DIR)
	@make -C ../libft clean
	@make -C ../printf clean

fclean: clean
	@rm -f $(NAME)
	@make -C ../libft fclean
	@make -C ../printf fclean

re: fclean all

.PHONY: all clean fclean re
