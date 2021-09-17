# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 18:52:14 by smagdela          #+#    #+#              #
#    Updated: 2021/09/16 14:51:56 by smagdela         ###   ########.fr        #
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
SRCS	=	push_swap.c ft_errors.c
OBJS	:=	${addprefix ${OBJD},${SRCS:.c=.o}}
SRCS	:=	${addprefix ${SRCD},${SRCS}}

CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror
LIBFTMK	=	make -C ${LIBFTD}

#############
#	RULES	#
#############

${NAME}:	${LIBFT} ${OBJS}
	${CC} ${CFLAG} ${OBJS} ${LIBFT} -o $@

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
