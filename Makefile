# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anoury <anoury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 14:27:50 by anoury            #+#    #+#              #
#    Updated: 2022/09/17 19:32:01 by anoury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#export LD_LIBRARY_PATH=/usr/lib/swift/

# NAMES

NAME = so_long
TEST = test
NAME_BONUS = ./bonus/so_long_bonus

# Paths

SRC_PATH = ./srcs/
SRC_PATH_BONUS = ./bonus/srcs/

OBJ_PATH = ./objs/
OBJ_PATH_BONUS = ./bonus/objs/

WFLAGS = -I./includes/
WFLAGSBONUS = -I./bonus/includes/

HEADER = ./includes/so_long.h
HEADER_BONUS = ./bonus/includes/so_long.h

LIBFT_PATH	= ./libs/libft/libft.a

GNL_PATH = ./libs/gnl/gnl.a
EXP = LD_LIBRARY_PATH=/usr/lib/swift/

# SRCS

SRC_NAME =	ini_png.c			\
			parsing.c			\
			error.c				\
			open_file.c			\
			utils.c				\
			trace_img_logic.c	\
			hook_manager.c		\
			patch_mlx.c			\
			check_map.c			\
			main.c

SRC_BONUS =	ini_png_bonus.c			\
			parsing_bonus.c			\
			error_bonus.c				\
			open_file_bonus.c			\
			utils_bonus.c				\
			trace_img_logic_bonus.c	\
			hook_manager_bonus.c		\
			hook_key.c				\
			patch_mlx_bonus.c			\
			check_map_bonus.c			\
			check_map2_bonus.c			\
			main_bonus.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME_BONUS = $(SRC_BONUS:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

OBJ_BONUS = $(addprefix $(OBJ_PATH_BONUS), $(OBJ_NAME_BONUS))

MAIN = main.c

MAIN_BONUS = ./bonus/main.c

# Flags

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror 

FS = #-fsanitize=address -g3

MLX = -L./libs/mlx -lmlx -framework OpenGL -framework AppKit -lz 

TST = ./srcs/test.c

# Rules 

all : gnl lib mlx $(NAME) 

$(TEST) : $(HEADER) ./Makefile
	@echo "\033[34mCreation of $(TEST) ...\033[0m"
	@$(CC) $(TST) -o $@ $(MLX)
	@echo "\033[32m$(NAME) created\n\033[0m"


$(NAME): $(OBJ) $(HEADER) ./Makefile
#		$(OBJ) $(LIBFT_PATH) $(GNL_PATH) $(HEADER) ./Makefile
	@@echo "\033[33m-------------------- Compiling ... --------------------"
	@$(CC) $(FS) $(LIBFT_PATH) $(GNL_PATH) $(OBJ) -o $@ $(MLX)
	@export LD_LIBRARY_PATH=/usr/lib/swift/
	@echo "\033[31m༺ (\033[32mSo_Long Compiled!\033[31m)༻\n"

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_PATH) $(GNL_PATH) ./Makefile
	@echo "\033[33m-------------------- Compiling BONUS... --------------------"
	@$(CC) $(FS) $(LIBFT_PATH) $(GNL_PATH) $(OBJ_BONUS) -o $(NAME_BONUS) $(MLX)
	@cp ./libs/mlx/libmlx.dylib ./bonus/libmlx.dylib
	@echo "\033[31m༺ (\033[31m\033[32mSo_Long~BONUS Compiled!\033[31m)༻\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(WFLAGS) -o $@ -c $<

$(OBJ_PATH_BONUS)%.o: $(SRC_PATH_BONUS)%.c
	@mkdir $(OBJ_PATH_BONUS) 2> /dev/null || true
	@$(CC) $(WFLAGSBONUS) -o $@ -c $<

lib:
	@make -C./libs/libft/

add :
	export $(EXP)

gnl:
	@make -C ./libs/gnl

mlx:
	@make -C./libs/mlx/
	@cp ./libs/mlx/libmlx.dylib ./libmlx.dylib

bonus: gnl lib mlx $(NAME_BONUS)

clean: cleanbonus
	@make clean -C ./libs/libft/
	@make clean -C./libs/gnl/
	@make clean -C./libs/mlx/
	@-rm -f $(OBJ)
	@-rmdir $(OBJ_PATH) 
	@echo "\033[33m     Clean  ALL ..."

cleanbonus:
	@-rm -f $(OBJ_BONUS)
	@-rmdir $(OBJ_PATH_BONUS) 

fclean: clean
	@make fclean -C ./libs/libft/
	@make fclean -C ./libs/gnl/
	@-rm -f $(NAME) $(NAME_BONUS) ./libmlx.dylib ./bonus/libmlx.dylib .vsvcode ./test
	@-rm -d -rf .vsvcode
	@echo "\033[36mEverything is cleaned! \033[32m✓\n"

re: fclean all

reb: fclean all bonus

.PHONY: all, clean, fclean, re
