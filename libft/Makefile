CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror
NAME        =   libft.a
SRCS        =   ./ft_lstadd_front.c \
                ./ft_isdigit.c \
                ./ft_isspace.c \
                ./ft_lstnew.c \
                ./ft_putnbr_fd.c \
                ./ft_bzero.c \
                ./ft_split.c \
                ./free_double_str.c \
                ./ft_tolower.c \
                ./ft_lstlast.c \
                ./ft_substr.c \
                ./ft_isprint.c \
                ./free_triple_str.c \
                ./ft_strchr.c \
                ./ft_memcmp.c \
                ./ft_strtrim.c \
                ./ft_strdup.c \
                ./ft_lstmap.c \
                ./ft_lstiter.c \
                ./ft_lstadd_back.c \
                ./ft_lstclear.c \
                ./arr_dup.c \
                ./ft_toupper.c \
                ./ft_putendl_fd.c \
                ./ft_strmapi.c \
                ./ft_strjoin.c \
                ./ft_strjoin_nofree.c \
                ./ft_strnstr.c \
                ./output_arr.c \
                ./ft_putchar_fd.c \
                ./ft_isascii.c \
                ./ft_striteri.c \
                ./ft_memcpy.c \
                ./ft_itoa.c \
                ./ft_strlen.c \
                ./ft_isalpha.c \
                ./ft_strlcat.c \
                ./ft_lstdelone.c \
                ./ft_strrchr.c \
                ./ft_putstr_fd.c \
                ./ft_lstsize.c \
                ./ft_isalnum.c \
                ./ft_memchr.c \
                ./ft_memmove.c \
                ./ft_strcmp.c \
                ./ft_strncmp.c \
                ./ft_atoi.c \
                ./ft_strlcpy.c \
                ./ft_memset.c \
                ./ft_calloc.c \
                ./ft_strjoin_free2.c \
                ./ft_strcat.c \
                ./ft_strcpy.c \
                ./ft_strlen2d.c \
                ft_strjoin_free_both.c \
                ft_strjoin_char.c \
                ft_ltoa.c

OBJS        =   ${SRCS:.c=.o}

BONUS_SRCS  =   ft_lstnew.c \
                ft_lstadd_front.c \
                ft_lstsize.c \
                ft_lstlast.c \
                ft_lstadd_back.c \
                ft_lstdelone.c \
                ft_lstclear.c \
                ft_lstiter.c \
                ft_lstmap.c
BONUS_OBJS  =   ${BONUS_SRCS:.c=.o}

PUMPKIN_EMOJI = 🎃
SKELETON = 💀
GHOST_EMOJI = 👻
SPIDER = 🕷️

all:	${NAME}
${NAME}:	${OBJS}
	@ar rcs ${NAME} ${OBJS}

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJS}

fclean:	clean
	@rm -f ${NAME}

bonus:	${BONUS_OBJS}
	@ar rcs ${NAME} ${BONUS_OBJS}

re:	fclean all

.PHONY: all clean fclean re bonus
