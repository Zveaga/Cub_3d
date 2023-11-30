# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ibehluli <ibehluli@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/16 12:06:14 by ibehluli      #+#    #+#                  #
#    Updated: 2023/11/30 12:53:43 by raanghel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/bash

CC = gcc
SRC_DIR = src
SOURCE = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/map_parsing.c \
	$(SRC_DIR)/map_parsing1.c \
	$(SRC_DIR)/freeing.c \
	$(SRC_DIR)/render.c \

CFLAGS = -Wall -Wextra -Werror
RM = -rf

NAME = cub3D
HEADER = include/cube3d.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX42 = MLX42
INCLUDE = -Iinclude -I$(MLX42)/include -I$(LIBFT_DIR)/headers
MLX42AR = $(MLX42)/build/libmlx42.a
MLX_L_FLAG = -L$(MLX42)/build -lmlx42 -L$(LIBFT_DIR) -lft
ifeq ($(shell uname -s),Darwin)			# Mac
	MLX_L_FLAG += -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
else ifeq ($(shell uname -s),Linux)		# Linux
	MLX_L_FLAG += -lglfw -ldl -pthread -lm
endif

ODIR = obj

OBJECTS = $(patsubst $(SRC_DIR)%,$(ODIR)%,$(SOURCE:.c=.o))

GREEN = \033[32;01m
RED = \033[31;01m
BLUE = \033[34;01m
RESET = \033[0m
YELLOW = \033[33;01m

all: $(MLX42AR) $(LIBFT) $(NAME)

$(MLX42AR):
	git submodule update --init
	@cmake $(MLX42) -B $(MLX42)/build
	@$(MAKE) -C $(MLX42)/build -j4 --quiet
	
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)  --quiet
	@printf "$(GREEN)Libft compiled\n$(RESET)"

# $(NAME): $(ODIR) $(OBJECTS)
# 	@$(CC) -fsanitize=address $(OBJECTS) $(MLX_L_FLAG) -o $(NAME) 
# 	@printf "$(GREEN)Created program $(NAME)$(RESET)\n"

$(NAME): $(ODIR) $(OBJECTS)
	@$(CC) $(OBJECTS) $(MLX_L_FLAG) -o $(NAME) 
	@printf "$(GREEN)Created program $(NAME)$(RESET)\n"

$(ODIR):
	@mkdir -p $(ODIR)

$(ODIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(ODIR)
	@$(MAKE) clean -C $(MLX42)/build -j4 --quiet
	@make clean -C $(LIBFT_DIR) --quiet

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) --quiet

re: fclean all

.PHONY: all clean fclean re