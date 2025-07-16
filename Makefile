# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 10:00:00 by sabejaou          #+#    #+#              #
#    Updated: 2024/05/30 10:00:00 by sabejaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft

# Sources pour la version normale
SRCS = $(wildcard $(SRC_DIR)/core/*.c)

# Sources pour la version bonus
SRCS_BONUS = $(wildcard $(SRC_DIR)/bonus/*.c)

# Sources libft
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:$(LIBFT_DIR)/%.c=$(OBJ_DIR)/libft/%.o)

# Objets pour la version normale
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Objets pour la version bonus
OBJS_BONUS = $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	@echo "Edition des liens pour $(NAME)..."
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT_OBJS)
	@echo "Binaire $(NAME) créé avec succès !"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_OBJS)
	@echo "Edition des liens pour $(NAME_BONUS)..."
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT_OBJS)
	@echo "Binaire $(NAME_BONUS) créé avec succès !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "Compilation de $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/libft/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)/libft
	@mkdir -p $(dir $@)
	@echo "Compilation de $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/libft:
	@mkdir -p $(OBJ_DIR)/libft

clean:
	@echo "Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR)
	@echo "Nettoyage terminé !"

fclean: clean
	@echo "Nettoyage complet..."
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "Nettoyage complet terminé !"

re: fclean all

test: all
	@echo "Test de compilation terminé !"

.PHONY: all bonus clean fclean re test 