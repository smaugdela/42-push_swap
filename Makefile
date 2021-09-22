# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 18:52:14 by smagdela          #+#    #+#              #
#    Updated: 2021/09/22 15:08:46 by smagdela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
#	VARIABLES	#
#################

NAME	=	push_swap

LIBFTD	=	libft/
INCD	=	includes/
SRCD	=	sources/
OBJD	=	objects/

LIBFT	:=	${addprefix ${LIBFTD},libft.a}
SRCS	=	push_swap.c ft_errors.c ft_utils.c ft_operations.c 
OBJS	:=	${addprefix ${OBJD},${SRCS:.c=.o}}
SRCS	:=	${addprefix ${SRCD},${SRCS}}

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
	@echo "${GREEN}Project Compilation Success!	\n"

${OBJD}%.o:	${SRCD}%.c ${LIBFT}
	mkdir -p ${OBJD}
	${CC} -c -o $@ ${CFLAGS} -I${INCD} -I${LIBFTD} $<

${LIBFT}:
	${LIBFTMK} bonus

all:	${NAME}

clean:
	-rm -rf ${OBJD}
	${LIBFTMK} clean

fclean:	clean
	-rm ${NAME}
	${LIBFTMK} fclean

re:		fclean all
	
.PHONY : re all clean fclean
