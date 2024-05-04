# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helauren <helauren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 12:06:13 by helauren          #+#    #+#              #
#    Updated: 2023/07/11 12:06:13 by helauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS = ft_printf.c \
		ft_print_int.c \
		ft_print_pointer.c \
		ft_tohex.c \
		ft_print_char.c \

OBJS	= $(SRCS:%.c=%.o)

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	libft $(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS) ../libft/libft.a

libft:
	$(MAKE) -C ../libft

$(OBJS):	
			${CC} ${CFLAGS} -c ${SRCS}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re libft