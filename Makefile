# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 18:52:14 by smagdela          #+#    #+#              #
#    Updated: 2021/10/11 13:52:29 by smagdela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
#	VARIABLES	#
#################

NAME	=	push_swap
BONUS_NAME	=	checker

LIBFTD	=	libft/
INCD	=	includes/
SRCD	=	sources/
OBJD	=	objects/
BONUSD	=	bonus/
BONUSSD	:=	${BONUSD}sources/
BONUSOD	:=	${BONUSD}objects/

LIBFT	:=	${addprefix ${LIBFTD},libft.a}
SRCS	=	push_swap.c ft_errors.c ft_utils.c ft_utils_2.c ft_operations.c backtracking.c backtracking_2.c backtracking_constraints.c quicksort.c quicksort_2.c quicksort_optimizer.c
BONUS 	=	checker.c get_next_line.c get_next_line_utils.c
OBJS	:=	${addprefix ${OBJD},${SRCS:.c=.o}}
SRCS	:=	${addprefix ${SRCD},${SRCS}}
BONUSO	:=	${addprefix ${BONUSOD},${BONUS:.c=.o}}
BONUS	:=	${addprefix ${BONUSSD},${BONUS}}

CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror
LIBFTMK	=	make -C ${LIBFTD}

#	COLORS

GREEN	=	\033[0;32m
RED		=	\033[1;31m
NC		=	\033[0m

WHALE	=	"\n${GREEN}       ::: \n     ___:____     |^\/^| \n   ,'        '.    \  / \n   |  O        \___/  | \n ~^~^~^~^~^~^~^~^~^~^~^~^~\n \n Compilation Successful!	${NC}\n"
NUKE	=	"\n${RED}     _.-^^---....,,--       \n _--                  --_  \n<                        >)\n|                         | \n \._                   _./  \n    '''--. . , ; .--'''       \n          | |   |             \n       .-=||  | |=-.   \n       '-=£€%&%€£=-'   \n          | ;  :|     \n _____.,-£%&€@%£&£~,._____${NC}\n\n"

#############
#	RULES	#
#############

all:	${NAME}

${NAME}:	${LIBFT} ${OBJS}
	${CC} ${CFLAG} ${OBJS} ${LIBFT} -o $@
	@echo ${WHALE}

${OBJD}%.o:	${SRCD}%.c
	mkdir -p ${OBJD}
	${CC} -c -o $@ ${CFLAGS} -I${INCD} -I${LIBFTD} $<

${LIBFT}:
	${LIBFTMK} bonus

test:
	@echo "${BONUSOD}"

${BONUSOD}%.o:	${BONUSSD}%.c
	mkdir -p ${BONUSOD}
	${CC} -c -o $@ ${CFLAGS} -I${INCD} -I${LIBFTD} $<

bonus: ${LIBFT} ${OBJS} ${BONUSO}
	${CC} ${CFLAG} ${BONUSO} ${LIBFT} -o ${BONUS_NAME}
	@echo ${WHALE}

clean:
	-rm -rf ${OBJD} ${BONUSOD}
	${LIBFTMK} clean

fclean:	clean
	-rm ${NAME} ${BONUS_NAME}
	${LIBFTMK} fclean
	@echo ${NUKE}

re:		fclean all

.PHONY : re all bonus clean fclean
