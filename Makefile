# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 18:52:14 by smagdela          #+#    #+#              #
#    Updated: 2021/09/15 12:34:36 by smagdela         ###   ########.fr        #
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

LIBFT	=	${addprefix ${LIBFTD},libft.a}
SRCS	=	push_swap.c \

SRCS	=	${addprefix ${SRCD},${SRCS}}
OBJS	=	${addprefix ${OBJD},${SRCS:.c=.o}}

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBFTMK	=	make -C ${LIBFTD}

#############
#	RULES	#
#############

${NAME}:	${LIBFT} ${OBJS}
	${CC} ${CFLAG} ${OBJS} -o $@

${OBJD}%.o:	${SRCD}%.c ${LIBFT}
	mkdir -p ${OBJD}
	${CC} -c $@ ${CFLAGS} -I${INCD} $<

${LIBFT}:
	${LIBFTMK} all
	${LIBFTMK} bonus

all:	${NAME}

clean:
	rm -rf ${OBJD}
	${LIBFTMK} clean

fclean:	clean
	rm ${NAME}
	${LIBFTMK} fclean

re:		fclean all
	
.PHONY : re all clean fclean
