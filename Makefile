# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 14:35:07 by tpierre           #+#    #+#              #
#    Updated: 2021/06/30 11:21:21 by tpierre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

##################################### DIRS #####################################

LFT_DIR		=	../libft_update

INC_DIR		=	./includes

SRC_DIR		=	./srcs

OBJ_DIR		=	./objs

##################################### SRCS #####################################

# **************************************************************************** #
# push_swap :

PS_FILES	=	ft_check_input.c ft_check_is_sorted.c ft_get.c ft_operations.c \
				ft_sort_five.c ft_sort_stack.c ft_sort_three.c ft_verif_pos.c \
				main.c

##################################### OBJS #####################################

PS_OBJS		=	$(PS_FILES:.c=.o)

PS_OBJ		=	$(addprefix $(OBJ_DIR)/, $(PS_OBJS))

##################################### INCS #####################################

LFT			=	$(addprefix $(LFT_DIR)/, libft.a)

LFT_INC_DIR	=	$(addprefix $(LFT_DIR)/, $(INC_DIR))

LFT_INC		=	$(addprefix $(LFT_DIR)/, $(INC_DIR)/libft.h)

PS_INC		=	$(addprefix $(INC_DIR)/, push_swap.h)

HEADERS		=	$(PS_INC) $(LFT_INC)

INCS		=	$(addprefix -I,$(INC_DIR) $(LFT_INC_DIR))

##################################### COMP #####################################

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

##################################### RULE #####################################

all:			$(NAME)

$(NAME):		$(LFT) $(PS_OBJ)
				@$(CC) $(CFLAGS) -o $(NAME) $(PS_OBJ) $(LFT) $(INCS)
				@$(IF_CMP)
				@echo $(BG)[$(BLB)Push_swap $(BG)COMPILED$(BG)]$(X)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
				@$(CMP)
				@$(MKOBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
				@$(CLR)
				@echo -n $@

$(LFT):
				@$(MAKE) -C $(LFT_DIR)

clean:
				@$(MAKE) clean -C $(LFT_DIR)
				@/bin/rm -rf $(OBJ_DIR)
				@echo $(BG)[$(BLB)PUSH_SWAP $(BG)CLEANED$(BG)]$(X)

fclean:			clean
				@/bin/rm -f $(LFT)
				@/bin/rm -f $(NAME)

re:
				@$(MAKE) fclean
				@$(MAKE) all

##################################### UTIL #####################################

MKOBJ_DIR 		=	if [ ! -d $(OBJ_DIR) ]; then \
			/bin/mkdir -p $(OBJ_DIR); \
			/bin/mkdir -p $(OBJ_DIR)/push_swap; fi

CMP			=	if [ ! -e .cmp ]; then \
				echo $(BY)Compiling $(B)Project $(X)files...$(BY); \
				touch .cmp; fi

IF_CMP		=	if [ -e .cmp ]; then \
				$(CLR); \
				echo $(UP) $(CUT) $(UP); \
				/bin/rm -f .cmp; fi

################################### DISPLAY ####################################

BY			=	"\033[1;33m"
BR			=	"\033[1;31m"
BG			=	"\033[1;32m"
BLB			=	"\033[1;36m"
BP			=	"\033[1;35m"
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[0;32m"
B			=	"\033[34m"
P			=	"\033[35m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"
CLR			=	printf "\r%40c\r" " "
CUT_UP		=	$(UP)$(CUT)$(UP)

#################################### OTHER #####################################

.PHONY:			all clean fclean re
