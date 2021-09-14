# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 18:52:14 by smagdela          #+#    #+#              #
#    Updated: 2021/09/14 19:07:20 by smagdela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	VARIABLES	#

NAME	=	push_swap

CC	=	gcc

LIBFTD	=	libft/
INCD	=	includes/
SRCD	=	sources/
OBJD	=	objs/

SRCS	=	push_swap.c
OBJS	=	${SRCS:.c=.o}
SRCS	=	${addprefix ${SRCD},${SRCS}}
OBJS	=	${addprefix ${OBJD},${OBJS}}

CFLAGS	=	-Wall -Wextra -Werror

#	RULES	#

${NAME}:
	make -C ${LIBFTD} all

all:	${NAME}

clean:

fclean:	clean

re:		fclean all

.PHONY : re all clean fclean