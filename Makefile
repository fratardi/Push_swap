# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fratardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 13:58:39 by fratardi          #+#    #+#              #
#    Updated: 2019/11/04 13:58:41 by fratardi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = ./checker

LIB = ./libft/libft.a

LIB_PATH = ./libft/

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC_PATH = includes

INC_NAME = ft_printf.h

OBJ_DIR = ./objects

OBJ_PUSHSWAP = ./objects

SRC_DIR = ./push_swap_srcs

CHECKER_DIR = ./checker_srcs

CHECKER_OBJ = ./objects


C = $(SRC_DIR)/annex_sort.c \
	$(SRC_DIR)/sort.c \
	$(SRC_DIR)/p_moves.c \
	$(SRC_DIR)/s_moves.c \
	$(SRC_DIR)/r_moves.c \
	$(SRC_DIR)/rr_moves.c \
	$(SRC_DIR)/rot_moves.c \
	$(SRC_DIR)/fold_a.c \
	$(SRC_DIR)/fold_b.c \
	$(SRC_DIR)/fold_utils.c \
	$(SRC_DIR)/is_sorted.c \
	$(SRC_DIR)/median.c \
	$(SRC_DIR)/utils_pivots.c \
	$(SRC_DIR)/parsing.c \
	$(SRC_DIR)/print_stack.c \
	$(SRC_DIR)/no_val_below_stack.c \
	$(SRC_DIR)/debug.c \
	$(SRC_DIR)/pivots.c

C_PUSHSWAP =	$(SRC_DIR)/main.c

C_CHECKER = $(CHECKER_DIR)/checker.c

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

O = $(C:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

O_PUSHSWAP = $(C_PUSHSWAP:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#pour les fichiers objets du checker 
O_CHECKER = $(C_CHECKER:$(CHECKER_DIR)/%.c=$(CHECKER_OBJ)/%.o)

$(CHECKER_OBJ)/%.o : $(CHECKER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(if $(findstring checker, $@),@echo "\n--- Making \033[31mchecker\033[00m ---")
	@$(CC) $(FLAGS) -c $< -o $@
	@echo ">>> Making $@"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(if $(findstring main, $@),@echo "\n--- Making \033[31mpush_swap\033[00m ---")
	$(if $(findstring annex_sort, $@),@echo "\n--- Making \033[35mutils\033[00m ---")
	@$(CC) $(FLAGS) -c $< -o $@
	@echo ">>> Making $@"

all : lib $(NAME) $(CHECKER)

$(NAME) : $(O) $(O_PUSHSWAP)
	@make -C ./libft
	@echo ">>> Making ./pushswap binary"
	@$(CC) $(FLAGS) $(LIB) $(O) $(O_PUSHSWAP) -o $(NAME)

$(CHECKER) : $(O_CHECKER) $(O)
	@make -C ./libft
	@echo ">>> Making ./checker binary"
	@$(CC) $(FLAGS) $(O_CHECKER) $(O) $(LIB) -o $(CHECKER)

lib :
	@make -C ./libft

#$(NAME): $(O) $(INC)
#	@echo ""
#	@ar rc $(NAME) $(O) $(O_LIB)
#	@echo "ar rc of" $(NAME) "is done"
#	@ranlib $(NAME)
#	@echo "Ranlib of" $(NAME) "is done"
clean :
	@rm -rf $(O) $(O_CHECKER) $(O_PUSHSWAP)
	@make clean -C $(LIB_PATH)
	@echo "Cleaning Done (Removed .o)"

fclean : clean
	@rm -rf $(NAME) $(CHECKER) $(OBJ_DIR)
	@echo $(NAME) " Removed"
	@make fclean -C $(LIB_PATH)
	@echo "libft.a Removed"

re : fclean all

.PHONY : all lib clean flean re

