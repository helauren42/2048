NAME     := 2048
CC       := cc
CFLAGS   := -g3 -Wall -Wextra -Werror -Wconversion 
CPPFLAGS := -MMD
LDFLAGS  := -g3
LDLIBS   := -lncursesw
RM       := /bin/rm -f

SRC      := 2048.c launch_arrows.c freeing.c tischmid_libft.c list.c
OBJ      := $(SRC:.c=.o)
DEPS     := $(OBJ:.o=.d)

.DEFAULT_GOAL = all

-include $(DEPS)

all: libft ft_printf $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) ./ft_printf/libftprintf.a ./libft/libft.a $(LDLIBS) -o $@

libft:
	$(MAKE) -C libft
ft_printf:
	$(MAKE) -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(RM) $(OBJ)
	$(RM) $(DEPS)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all libft ft_printf
