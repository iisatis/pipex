# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 15:49:50 by pflorent          #+#    #+#              #
#    Updated: 2021/12/08 19:32:24 by pflorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS_P	=./sources/

SRCS_F	= main.c ft_split.c utils.c

SRCS	= $(addprefix $(SRCS_P), $(SRCS_F))

OBJS	= $(SRCS:.c=.o)

HEAD	= -Iincludes

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		$(NAME)

${NAME}:	$(SRCS)
			$(CC) $(CFLAGS) $(HEAD) $(SRCS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
