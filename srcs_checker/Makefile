# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 20:42:33 by fde-carv          #+#    #+#              #
#    Updated: 2023/07/24 13:22:00 by fde-carv         ###   ########.fr        #
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

NAME 				=	checker
CC 					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -g
PUSH_SWAP_ARCHIVE	=	../push_swap.a

SRCS	 	= 	checker_bonus.c \
				get_next_line_utils_bonus.c \
				get_next_line_bonus.c \
				help_bonus.c

OBJS = $(SRCS:.c=.o)

%.o 		: 	%.c 
	@ $(CC) -c $(CFLAGS) $< -o $@ > /dev/null 2>&1

all 		:	$(NAME)

$(NAME)		:	$(OBJS) $(PUSH_SWAP_ARCHIVE) 
	@ $(CC) $^ -o $(NAME) > /dev/null 2>&1
	@ echo "$(BLUE)\n*** >>> Compiled $(NAME) with sucess! <<< ***\n$(DEF_COLOR)"
	@ echo "$(GREEN)        BONUS is ready to use!$(DEF_COLOR)"
	@ echo "$(CYAN)\n        Run$(YELLOW) ./$(NAME) <numeric argument/s>$(CYAN) to start$(DEF_COLOR)"
	@ echo "$(YELLOW)        <set instruction/s>$(DEF_COLOR)"
	@ echo "$(RED)        EXIT $(CYAN) --> control 'd'\n$(DEF_COLOR)"
	@ cp $(NAME) ../ > /dev/null 2>&1

$(PUSH_SWAP_ARCHIVE) :
	@ cd ../ && make

clean 		:
				rm -f $(OBJS)

fclean 		:	clean 
				rm -f $(NAME)
				cd ../srcs && rm -f $(NAME)
				cd ../ && rm -f $(NAME)

re 			:	fclean all

.PHONY		:	all clean fclean re

# No contexto de um makefile, $^ e -o são parâmetros especiais usados pelo make
# para representar os arquivos de origem e o arquivo de saída de uma regra de compilação.
# $^ representa todos os pré-requisitos (arquivos de origem) listados na regra de
# compilação. No caso do código fornecido, $(OBJS) e $(PUSH_SWAP_ARCHIVE) são os
# pré-requisitos, ou seja, os arquivos de origem que serão compilados.
# -o é uma opção do compilador que indica o arquivo de saída desejado. Nesse caso,
# $(NAME) é o nome do arquivo de saída especificado no makefile.
# Portanto, a linha $(CC) $^ -o $(NAME) pode ser interpretada como a invocação do
# compilador ($(CC)) para compilar todos os arquivos de origem ($^) e gerar o arquivo de
# saída ($(NAME)). O compilador será responsável por processar os arquivos de origem e
# gerar o executável com o nome especificado.	
