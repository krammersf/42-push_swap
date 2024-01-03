# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 12:14:59 by fde-carv          #+#    #+#              #
#    Updated: 2023/07/25 17:37:06 by fde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR 	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

# Defining the MAKEFLAGS variable
#MAKEFLAGS += --silent

NAME		=	push_swap
ARCHIVE		=	push_swap.a
HEADER		=	push_swap.h
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g
MAKE_LIB	=	ar -rcs

SRCS	 	= 	srcs/error_free.c \
				srcs/main.c \
				srcs/push_command.c \
				srcs/push_swap_command.c \
				srcs/push_swap_init.c \
				srcs/reverse_rotate_command.c \
				srcs/rotate_command.c \
				srcs/split.c \
				srcs/stack_init.c \
				srcs/stack_utils.c \
				srcs/stack_utils2.c \
				srcs/tiny_sort.c \
				srcs/swap_command.c

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(ARCHIVE)
	@ $(CC) $(CFLAGS) $< -o $@ > /dev/null 2>&1
	@ echo "$(BLUE)\n*** >>> Compiled $(NAME) with sucess! <<< ***\n$(DEF_COLOR)"
	@ echo "$(GREEN)        PUSH_SWAP is ready to use!$(DEF_COLOR)"
	@ echo "$(CYAN)\n        Run$(YELLOW) ./$(NAME) <numeric argument/s>$(CYAN) to start\n$(DEF_COLOR)"

$(ARCHIVE)	:	$(OBJS)
	@ $(MAKE_LIB) $(ARCHIVE) $^ > /dev/null 2>&1

%.o 		:	%.c $(HEADER)
	@ $(CC) $(CFLAGS) -s -c $< -o $@ > /dev/null 2>&1

bonus 		: 
	@ cd srcs_checker && make
	 
clean 		:
	@ rm -f $(OBJS) $(ARCHIVE) > /dev/null 2>&1
	@ echo "$(RED)\n*** >>>  OBJS FILES Deleted  <<< ***\n$(DEF_COLOR)"
	@ cd srcs_checker && make clean > /dev/null 2>&1

fclean		:	clean
	@ rm -f $(NAME) > /dev/null 2>&1
	@ echo "$(RED)\n*** >>>  EVERYTHING DELETED  <<< ***\n$(DEF_COLOR)"
	@ cd srcs_checker && make fclean > /dev/null 2>&1

re 			:	fclean all

rebonus		:	fclean bonus	

norm		:
				@norminette -R CheckForbiddenSourceHeader > /dev/null 2>&1
				@norminette -R CheckDefine includes > /dev/null 2>&1
				@norminette -R . > /dev/null 2>&1
				@echo "$(GREEN)\n*** >>>  NORMINETTE is OK  <<< ***\n"

norm2		:
				@norminette -R CheckForbiddenSourceHeader
				@norminette -R CheckDefine
				@norminette -R .
				@echo "$(GREEN)\n*** >>>  NORMINETTE is OK  <<< ***\n"	

.PHONY		:	all clean fclean re rebonus bonus norm norm2
