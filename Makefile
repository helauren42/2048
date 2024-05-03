NAME = FABOLOUS

SRCS = main.c

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g

# LIBFLAGS = -Lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	$(MAKE) -C minilibx-linux
	$(CC) $(OBJS) ./ft_printf/libftprintf.a ./libft/libft.a ./minilibx-linux/libmlx.a  -o $@

.c.o:
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean all