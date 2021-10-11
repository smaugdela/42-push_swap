# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 18:52:14 by smagdela          #+#    #+#              #
#    Updated: 2021/10/11 12:12:48 by smagdela         ###   ########.fr        #
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
BONUSSD	=	${BONUS}sources/
BONUSOD	=	${BONUS}objects/

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
NC		=	\033[0m

#############
#	RULES	#
#############

${NAME}:	${LIBFT} ${OBJS}
	${CC} ${CFLAG} ${OBJS} ${LIBFT} -o $@

	@echo "\n${GREEN}       :::"
	@echo "${GREEN}     ___:____     |^\/^|"
	@echo "${GREEN}   ,'        '.    \  /"
	@echo "${GREEN}   |  O        \___/  |"
	@echo "${GREEN} ~^~^~^~^~^~^~^~^~^~^~^~^~\n"
	@echo "${GREEN}Project Compilation Success!	${NC}\n"

${OBJD}%.o:	${SRCD}%.c ${LIBFT}
	mkdir -p ${OBJD}
	${CC} -c -o $@ ${CFLAGS} -I${INCD} -I${LIBFTD} $<

${LIBFT}:
	${LIBFTMK} bonus

all:	${NAME}

bonus:	${LIBFT} ${OBJS} ${BONUSO}
	${CC} ${CFLAG} ${BONUSO} ${LIBFT} -o checker

	@echo "\n${GREEN}       :::"
	@echo "${GREEN}     ___:____     |^\/^|"
	@echo "${GREEN}   ,'        '.    \  /"
	@echo "${GREEN}   |  O        \___/  |"
	@echo "${GREEN} ~^~^~^~^~^~^~^~^~^~^~^~^~\n"
	@echo "${GREEN}Bonus Compilation Success!	${NC}\n"

${BONUSOD}%.o:	${BONUSSD}%.c ${LIBFT}
	mkdir -p ${BONUSOD}
	${CC} -c -o $@ ${CFLAGS} -I${INCD} -I${LIBFTD} $<

clean:
	-rm -rf ${OBJD} ${BONUSOD}
	${LIBFTMK} clean

fclean:	clean
	-rm ${NAME} ${BONUS_NAME}
	${LIBFTMK} fclean

re:		fclean all

.PHONY : re all bonus clean fclean
