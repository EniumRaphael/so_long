# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 11:05:05 by rparodi           #+#    #+#              #
#    Updated: 2024/03/08 14:28:29 by rparodi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Variables

# Name
NAME = so_long
LIBDIRNAME = libft
SRCDIRNAME = sources

# Commands
CC = cc
RM = rm -rf

# Flags
CFLAGS = -Werror -Wextra -Wall -Wno-unused-command-line-argument -g3 -MMD
MINILIBX = make -C ./minilibx-linux/
MLXFLAGS = -Lmlx_linux -L/usr/lib -lXext -lX11 -lm -lz

# Sources
LIB =	./libft/ft_printf.c \
		./libft/ft_put.c \
		./libft/ft_reverse_split.c \
		./libft/ft_split.c \
		./libft/ft_strdup.c \
		./libft/ft_strlcpy.c \
		./libft/get_next_line.c \
		./libft/get_next_line_utils.c

SRC =	./sources/ft_check_map.c \
		./sources/ft_exit.c \
		./sources/ft_init.c \
		./sources/ft_map.c \
		./sources/ft_move.c \
		./sources/ft_parse_map.c \
		./sources/ft_value.c \
		./sources/main.c

# Objects
MLXDIRNAME = ./minilibx-linux
MLX = $(MLXDIRNAME)/libmlx.a
OBJDIRNAME = ./object
OBJ = $(addprefix $(OBJDIRNAME)/,$(SRC:.c=.o))
LIB_OBJ = $(addprefix $(OBJDIRNAME)/,$(LIB:.c=.o))

# Colors
GREEN = \033[32m
GREY = \033[0;90m
RED = \033[0;31m
GOLD = \033[38;5;220m
END = \033[0m

# Rules

# All (make all)
all: header $(NAME) bonus footer

# Bonus (make bonus)
bonus: $(OBJ) $(LIB_OBJ)
	@make -C ./minilibx-linux >/dev/null 2>&1
	@cc $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIB_OBJ) ./minilibx-linux/libmlx.a

# Clean (make clean)
clean:
	@printf '$(GREY) Removing $(END)$(RED)Objects Folder$(END)\n'
	@$(RM) $(OBJDIRNAME)
	@printf '$(GREY) Removing $(END)$(RED)Object$(END)\n'
	

# Clean (make fclean)
fclean: clean
	@printf '$(GREY) Removing $(END)$(RED)Program$(END)\n'
	@$(RM) $(NAME)
	@printf '$(GREY) Removing $(END)$(RED)Program MLX$(END)\n'
	@$(RM) $(MLX)
	@echo ""

# Restart (make re)
re: header fclean bonus all

# Dependences for all
$(NAME): $(OBJ) $(LIB_OBJ)
	@mkdir -p $(OBJDIRNAME)
	@mkdir -p $(OBJDIRNAME)/$(LIBDIRNAME)
	@mkdir -p $(OBJDIRNAME)/$(SRCDIRNAME)
	@make -C ./minilibx-linux > /dev/null 2>&1
	@printf '$(GREY) Creating $(END)$(GREEN)$(OBJDIRNAME)$(END)\n'
	@cc $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIB_OBJ) ./minilibx-linux/libmlx.a

# Creating the objects
$(OBJDIRNAME)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf '$(GREY) Compiling $(END)$(GREEN)$<$(END)\n'
	@cc $(CFLAGS) -o $@ -c $<

#	Header
header:
		@clear
		@printf '\n\n'
		@printf '$(GOLD)            *******     ****** ******* $(END)\n'
		@printf '$(GOLD)          ******        ***    ******* $(END)\n'
		@printf '$(GOLD)      *******           *      ******* $(END)\n'
		@printf '$(GOLD)     ******                  ******* $(END)\n'
		@printf '$(GOLD)  *******                  ******* $(END)\n'
		@printf '$(GOLD) *******************    *******      * $(END)\n'
		@printf '$(GOLD) *******************    *******    *** $(END)\n'
		@printf '$(GOLD)              ******    ******* ****** $(END)\n'
		@printf '$(GOLD)              ******  $(END)\n'
		@printf '$(GOLD)              ******  $(END)\n'
		@printf '$(GREY)                                      Made by rparodi$(END)\n\n'

#	Footer
footer:
		@printf "\n"
		@printf "$(GOLD)                   ,_     _,$(END)\n"
		@printf "$(GOLD)                   | \\___//|$(END)\n"
		@printf "$(GOLD)                   |=6   6=|$(END)\n"
		@printf "$(GOLD)                   \\=._Y_.=/$(END)\n"
		@printf "$(GOLD)                    )  \`  (    ,$(END)\n"
		@printf "$(GOLD)                   /       \\  (('$(END)\n"
		@printf "$(GOLD)                   |       |   ))$(END)\n"
		@printf "$(GOLD)                  /| |   | |\\_//$(END)\n"
		@printf "$(GOLD)                  \\| |._.| |/-\`$(END)\n"
		@printf "$(GOLD)                   '\"'   '\"'$(END)\n"
		@printf '              $(GREY)The compilation is$(END) $(GOLD)finish$(END)\n               $(GREY)Have a good $(END)$(GOLD)correction !$(END)\n'

#	Phony
.PHONY: all bonus clean fclean re

-include	${OBJ:.o=.d}
