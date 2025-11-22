# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 06:16:18 by lucasdebarn       #+#    #+#              #
#    Updated: 2025/11/22 13:21:32 by ludebarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

# Library
LIBFT = ../libft
PRINTF = ../printf

# Directory
OBJ_DIR = object
OBJ_BONUS_DIR = object_bonus
SRC_DIR = src
SRC_BONUS_DIR = src_bonus

# Files src mandatory
SRCS = $(SRC_DIR)/ft_error.c \
       $(SRC_DIR)/pipex.c \
       $(SRC_DIR)/pipex_utils.c \
       $(SRC_DIR)/crea_process2.c \
       $(SRC_DIR)/pipex_utils2.c

# Files src bonus
BONUS = $(SRC_BONUS_DIR)/ft_error_bonus.c \
        $(SRC_BONUS_DIR)/pipex_bonus.c \
        $(SRC_BONUS_DIR)/pipex_utils_bonus.c \
        $(SRC_BONUS_DIR)/crea_process_bonus.c \
        $(SRC_BONUS_DIR)/pipex_utils_bonus2.c \
        $(SRC_BONUS_DIR)/get_next_line_utils.c \
        $(SRC_BONUS_DIR)/get_next_line.c

# Objects
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJS_BONUS = $(patsubst $(SRC_BONUS_DIR)/%.c,$(OBJ_BONUS_DIR)/%.o,$(BONUS))

# Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I . -I $(LIBFT) -I $(PRINTF)/
LIBRARYPATH = -L$(LIBFT) -L$(PRINTF)
LIBRARIES = -lft

# Custom
COMPILE_MSG = @printf "."

# Règles pour créer les .o mandatory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(COMPILE_MSG)

# Règles pour créer les .o bonus
$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(COMPILE_MSG)

# Compilation mandatory
$(NAME): $(OBJS)
	@make -s -C $(LIBFT)
	@make -s -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARYPATH) $(LIBRARIES) -o $(NAME)
	@echo "\n✅ Compilation mandatory terminée !"

# Compilation bonus
$(NAME_BONUS): $(OBJS_BONUS)
	@make -s -C $(LIBFT)
	@make -s -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBRARYPATH) $(LIBRARIES) -o $(NAME_BONUS)
	@echo "\n✅ Compilation bonus terminée !"

# Règles principales
all: $(NAME)

bonus: $(NAME_BONUS)

# Cleaning
clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make -C $(LIBFT) clean
	@make -C $(PRINTF) clean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT) fclean
	@make -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re bonus
