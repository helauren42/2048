#include "2048.h"
#include <curses.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <locale.h>
#include <limits.h>

#define BOX_DRAWING_VERTICAL "│"
#define BOX_DRAWING_HORIZONTAL "─"
#define BOX_DRAWING_TOP_LEFT "┌"
#define BOX_DRAWING_TOP_RIGHT "┐"
#define BOX_DRAWING_BOTTOM_LEFT "└"
#define BOX_DRAWING_BOTTOM_RIGHT "┘"

#define FONT_ASPECT_RATIO 2
#define DIMENSION 4

#define BRIGHT 1000

typedef struct s_board
{
	int	dim;
	int	**cells;
}	t_board;

t_board	*init_board(void)
{
	t_board	*board;
	int		i;
	int		j;
	int		v;

	board = malloc(sizeof(*board));
	board->dim = DIMENSION;
	board->cells = malloc(sizeof(*board->cells) * (size_t)board->dim);
	i = -1;
	v = 1;
	while (++i < board->dim)
	{
		board->cells[i] = malloc(sizeof(*board->cells[i]) * (size_t)board->dim);
		j = -1;
		while (++j < board->dim)
			board->cells[i][j] = 1 << v++;
	}
	return (board);
}

void	destroy_board(t_board *board)
{
	int	i;

	i = -1;
	while (++i < board->dim)
		free(board->cells[i]);
	free(board->cells);
	free(board);
}

void	print_border_top(int x, int y, int cell_dim)
{
	int	d;

	mvprintw(y, x, BOX_DRAWING_TOP_LEFT);
	d = 0;
	while (++d < 2 * cell_dim - 1)
		mvprintw(y, x + d, BOX_DRAWING_HORIZONTAL);
	mvprintw(y, x + 2 * cell_dim - 1, BOX_DRAWING_TOP_RIGHT);
}

void	print_border_middle(int x, int y, int cell_dim)
{
	int	d;

	d = 0;
	while (++d < cell_dim - 1)
	{
		mvprintw(y + d, x, BOX_DRAWING_VERTICAL);
		mvprintw(y + d, x + 2 * cell_dim - 1, BOX_DRAWING_VERTICAL);
	}
}

void	print_border_bottom(int x, int y, int cell_dim)
{
	int	d;

	mvprintw(y + cell_dim - 1, x, BOX_DRAWING_BOTTOM_LEFT);
	d = 0;
	while (++d < 2 * cell_dim - 1)
		mvprintw(y + cell_dim - 1, x + d, BOX_DRAWING_HORIZONTAL);
	mvprintw(y + cell_dim - 1, x + 2 * cell_dim - 1, BOX_DRAWING_BOTTOM_RIGHT);
}

void	print_border(t_board *board, int i, int j, int cell_dim)
{
	int	x;
	int	y;

	y = i * cell_dim;
	x = j * 2 * cell_dim + COLS / 2 - board->dim * cell_dim;
	attron(COLOR_PAIR(1));
	print_border_top(x, y, cell_dim);
	print_border_middle(x, y, cell_dim);
	print_border_bottom(x, y, cell_dim);
	attroff(COLOR_PAIR(1));
}

unsigned int	ft_abs(int n)
{
	if (n > 0)
		return ((unsigned int)n);
	else
		return (-(unsigned int) n);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			n_len;
	unsigned int	n_cpy;
	int				is_neg;

	is_neg = n < 0;
	n_len = 0;
	n_cpy = ft_abs(n) + !n;
	while (n_cpy * ++n_len != 0)
		n_cpy /= 10;
	--n_len;
	str = malloc(sizeof(*str) * (n_len + (size_t)is_neg + 1));
	if (!str)
		return (NULL);
	str += (int)n_len + is_neg;
	n_cpy = ft_abs(n);
	*str-- = 0;
	while (n_len--)
	{
		*str-- = (char)(n_cpy % 10 + '0');
		n_cpy /= 10;
	}
	if (is_neg)
		*str-- = '-';
	return (++str);
}

/* count utf-8 code points in byte stream */
size_t	ft_utf_8_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
		count += (*s++ & 0xc0) != 0x80;
	return (count);
}

size_t	ft_strlen(char const *s)
{
	size_t	length;

	length = 0;
	while (*s++)
		length++;
	return (length);
}

int	ft_char_in_charset(char c, char const *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

static size_t	len_after_trim(char const *s1, char const *set)
{
	size_t	idx;
	size_t	start;
	size_t	end;

	idx = 0;
	while (ft_char_in_charset(s1[idx], set))
		++idx;
	if (!s1[idx])
		return (0);
	start = idx;
	while (s1[idx])
		++idx;
	--idx;
	while (ft_char_in_charset(s1[idx], set))
		--idx;
	end = idx;
	return (end - start + 1);
}

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t	len;

	len = 0;
	while (len + 1 < size && src[len])
		*dst++ = src[len++];
	if (size)
		*dst = 0;
	while (src[len])
		len++;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_len;
	char	*trimmed_str;

	trimmed_len = len_after_trim(s1, set);
	trimmed_str = malloc(sizeof(*trimmed_str) * (trimmed_len + 1));
	if (!trimmed_str)
		return (NULL);
	while (ft_char_in_charset(*s1, set))
		++s1;
	ft_strlcpy(trimmed_str, s1, trimmed_len + 1);
	return (trimmed_str);
}

char	*ft_strrchr(char const *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
		if (*s++ == (char) c)
			last = (char *)(s - 1);
	if (*s == (char) c)
		return ((char *) s);
	return (last);
}

int	ft_strcmp(char const *s1, char const *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (*us1 && *us2 && *us1 == *us2)
	{
		++us1;
		++us2;
	}
	return (*us1 - *us2);
}

int	ft_strncmp(char const *s1, char const *s2, size_t len)
{
	unsigned char	*us1;
	unsigned char	*us2;

	if (!len)
		return (0);
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (*us1 && *us2 && *us1 == *us2 && --len)
	{
		us1++;
		us2++;
	}
	if (*us1 != *us2)
		return ((*us1 - *us2 != 0)
			* (-2 * (*us1 - *us2 < 0) + 1));
	return (0);
}

size_t	ft_count_all(
	const char str[static 1],
	const char pattern[static 1])
{
	size_t	pattern_len;
	size_t	pattern_count;

	pattern_len = ft_strlen(pattern);
	pattern_count = 0;
	while (*str)
	{
		if (!ft_strncmp(str, pattern, pattern_len))
		{
			pattern_count += 1;
			str += pattern_len;
			if (!pattern_len)
				++str;
		}
		else
			++str;
	}
	if (!pattern_len)
		pattern_count += 1;
	return (pattern_count);
}

char	*ft_replace_all(
	const char str[static 1],
	const char pattern[static 1],
	const char replacement[static 1])
{
	size_t	pattern_len;
	size_t	replacement_len;
	size_t	str_idx;
	size_t	new_str_idx;
	char	*new_str;

	pattern_len = ft_strlen(pattern);
	replacement_len = ft_strlen(replacement);
	new_str = malloc(sizeof(*new_str) * (1 + ft_strlen(str)
				+ (replacement_len - pattern_len) * ft_count_all(str, pattern)));
	str_idx = 0;
	new_str_idx = 0;
	while (str[str_idx])
	{
		if (!ft_strncmp(str + str_idx, pattern, pattern_len))
		{
			ft_strlcpy(new_str + new_str_idx, replacement, replacement_len + 1);
			str_idx += pattern_len;
			new_str_idx += replacement_len;
			if (!pattern_len)
				new_str[new_str_idx++] = str[str_idx++];
		}
		else
			new_str[new_str_idx++] = str[str_idx++];
	}
	if (!pattern_len)
	{
		ft_strlcpy(new_str + new_str_idx, replacement, replacement_len + 1);
		new_str_idx += replacement_len;
	}
	new_str[new_str_idx] = 0;
	return (new_str);
}

static size_t	split_arr_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	if (*s == 0)
		return (1);
	while (*s)
	{
		while (*s == c)
			++s;
		if (!*s)
			return (len);
		++len;
		while (*s != c && *s)
			++s;
	}
	return (len);
}

static int	save_strlcpy(char **arr, size_t len, char const *src, size_t size)
{
	if (!arr[len - 1])
		return (0);
	ft_strlcpy(arr[len - 1], src, size);
	return (1);
}

char	*ft_strdup(char const *s)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s);
	s2 = malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, (char *) s, len + 1);
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	size_t		arr_len;
	size_t		idx;
	char		**arr;
	char const	*start;

	arr_len = split_arr_len(s, c);
	arr = malloc(sizeof(*arr) * (arr_len + 1));
	idx = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (!*s)
			break ;
		start = s;
		while (*s != c && *s)
			++s;
		arr[idx] = malloc(sizeof(**arr) * (size_t)(s - start + 1));
		if (!save_strlcpy(arr, ++idx, start, (size_t)(s - start + 1)))
			return (NULL);
	}
	if (idx == 0)
		arr[idx++] = ft_strdup("");
	arr[idx] = NULL;
	return (arr);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	max_width(char *lines_str)
{
	char	**lines;
	int		max_width = 0;

	lines = ft_split(lines_str, '\n');
	while (*lines)
		max_width = ft_max(max_width, (int)ft_utf_8_strlen(*lines++));
	return (max_width);
}

int	print_number_char(int num, int x, int y, int cell_dim, int num_len)
{
	if (num_len > FONT_ASPECT_RATIO * cell_dim - 1 || cell_dim - 2 < 0)
		return (0);
	mvprintw(y + cell_dim / 2, x + FONT_ASPECT_RATIO * cell_dim / 2 - num_len / 2, "%d", num);
	return (1);
}

int	print_numbers_height_n(int num, int x, int y, int cell_dim, int height, char *powers)
{
	char	**small_numbers;
	char	*tmp;
	int		lb = 1;
	int		num_len;
	char	**lines;
	int		line_idx = -1;

	if (cell_dim - 2 < height || num > 2147483647) /* ascii art only until 2^30. 2^31-1 will be rounded to 2^30. */
		return (0);
	tmp = ft_replace_all(powers, "NEWLINE\n", "X");
	small_numbers = ft_split(tmp, 'X');
	free(tmp);
	while (num >>= 1)
		++lb;
	num_len = max_width(small_numbers[lb]);
	if (num_len > FONT_ASPECT_RATIO * cell_dim - 2)
		return (0);
	lines = ft_split(small_numbers[lb], '\n');
	while (++line_idx < height)
		mvprintw(y + cell_dim / 2 - height / 2 + line_idx, x + FONT_ASPECT_RATIO * cell_dim / 2 - num_len / 2, "%s", lines[line_idx]);
	return (1);

}

void	fill_inside_cell(int x, int y, int cell_dim)
{
	int	i;
	int	j;

	i = 0;
	while (++i < cell_dim - 1)
	{
		j = 0;
		while (++j < cell_dim * FONT_ASPECT_RATIO - 1)
			mvprintw(y + i, x + j, " ");
	}
}

/* ret == 0 == no error */
int	print_number(t_board *board, int i, int j, int cell_dim)
{
	int	x;
	int	y;
	int	num;
	int	num_len;
	int	color;
	int	ret;

	y = i * cell_dim;
	x = j * FONT_ASPECT_RATIO * cell_dim + COLS / 2 - board->dim * cell_dim;
	num = board->cells[i][j];
	if (num < 2) /* simplify! */
		color = 2;
	else if (num < 4)
		color = 3;
	else if (num < 8)
		color = 4;
	else if (num < 16)
		color = 5;
	else if (num < 32)
		color = 6;
	else if (num < 64)
		color = 7;
	else if (num < 128)
		color = 8;
	else if (num < 256)
		color = 9;
	else if (num < 512)
		color = 10;
	else if (num < 1024)
		color = 11;
	else if (num < 2048)
		color = 12;
	else if (num < 4096)
		color = 13;
	else
		color = 14;
	attron(COLOR_PAIR(color));
	fill_inside_cell(x, y, cell_dim);
	num_len = (int)ft_strlen(ft_itoa(num));
	ret = 1;
	if (print_numbers_height_n(num, x, y, cell_dim, 16, DOH_NUMBERS))
		ret = 0;
	else if (print_numbers_height_n(num, x, y, cell_dim, 8, DOSREBEL_NUMBERS))
		ret = 0;
	else if (print_numbers_height_n(num, x, y, cell_dim, 6, SHADOW_NUMBERS))
		ret = 0;
	else if (print_numbers_height_n(num, x, y, cell_dim, 4, SMALL_NUMBERS))
		ret = 0;
	else if (print_numbers_height_n(num, x, y, cell_dim, 3, MINI_NUMBERS))
		ret = 0;
	else if (print_number_char(num, x, y, cell_dim, num_len))
		ret = 0;
	attroff(COLOR_PAIR(color));
	return (ret);
}

int	print_cell(t_board *board, int i, int j, int cell_dim)
{
	int	ret;

	print_border(board, i, j, cell_dim);
	ret = print_number(board, i, j, cell_dim);
	return (ret);
}

void	print_tty_too_small(void)
{
	clear();
	mvprintw(0, 0, "Terminal too small!\nResize it or zoom out!");
	refresh();
}

int	print_board(t_board *board)
{
	int	i;
	int	j;
	int	cell_dim;

	if (LINES * FONT_ASPECT_RATIO > COLS)
		cell_dim = COLS / (FONT_ASPECT_RATIO * board->dim);
	else
		cell_dim = LINES / board->dim;
	i = -1;
	while (++i < board->dim)
	{
		j = -1;
		while (++j < board->dim)
			if (print_cell(board, i, j, cell_dim))
				return (print_tty_too_small(), 1);
	}
	return (0);
}

void	right(t_board *board)
{
	int	i;
	int	j;

	i = -1;
	while (++i < board->dim)
	{
		j = -1;
		while (++j < board->dim)
			board->cells[i][j]++;
	}
}

void	left(t_board *board)
{
	int	i;
	int	j;

	i = -1;
	while (++i < board->dim)
	{
		j = -1;
		while (++j < board->dim)
			board->cells[i][j]--;
	}
}

/* 0 <= BRIGHT <= 1000 */
int	my_init_color(short color, int r, int g, int b)
{
	return (init_color(
		color,
		(short)(r * BRIGHT / 256),
		(short)(g * BRIGHT / 256),
		(short)(b * BRIGHT / 256)
	));
}

void	ft_bzero(void *ptr, size_t n)
{
	char	*p;

	p = (char *)ptr;
	while (n--)
		*p++ = (unsigned char) 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	void	*empty;

	if (nmemb * size == 0)
	{
		empty = malloc(0);
		if (!empty)
			return (NULL);
		return (empty);
	}
	if (UINT_MAX / nmemb < size)
		return (NULL);
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	idx;
	size_t	sidx;
	size_t	slen;
	size_t	dlen;

	slen = 0;
	while (src[slen])
		++slen;
	idx = 0;
	while (dst[idx] && idx < size)
		++idx;
	dlen = idx;
	if (dlen == size)
		return (slen + size);
	sidx = 0;
	size -= dlen;
	while (size-- > 1 && src[sidx])
		dst[idx++] = src[sidx++];
	dst[idx] = 0;
	return (dlen + slen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*joined_str;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined_str = ft_calloc(total_len + 1, sizeof(*joined_str));
	if (!joined_str)
		return (NULL);
	ft_strlcat(joined_str, s1, total_len + 1);
	ft_strlcat(joined_str, s2, total_len + 1);
	return (joined_str);
}

void	ft_setenv(char **envp, const char *name, const char *value)
{
	char	**parts;

	while (*envp)
	{
		parts = ft_split(*envp, '=');
		if (!ft_strcmp(parts[0], name))
		{
			*envp = ft_strjoin(name, ft_strjoin("=", value));
			break ;
		}
		++envp;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int			key;
	t_board		*board;

	(void)argc;
	(void)argv;
	(void)envp;
	ft_setenv(envp, "TERM", "xterm-256color");
	setlocale(LC_ALL, "");
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	curs_set(0);
	start_color();

	my_init_color(10, 187,173,160); /* border */
	my_init_color(11, 205,192,181); /* bg */
	my_init_color(12, 119,110,101); /* 2 fg */
	my_init_color(13, 238,229,219); /* 2 bg */
	my_init_color(14, 119,110,101); /* 4 fg */
	my_init_color(15, 236,224,201); /* 4 bg */
	my_init_color(16, 249,247,243); /* 8 fg */
	my_init_color(17, 242,177,121); /* 8 bg */
	my_init_color(18, 249,247,243); /* 16 fg */
	my_init_color(19, 244,149,98); /* 16 bg */
	my_init_color(20, 249,247,243); /* 32 fg */
	my_init_color(21, 247,125,96); /* 32 bg */
	my_init_color(22, 249,247,243); /* 64 fg */
	my_init_color(23, 246,94,59); /* 64 bg */
	my_init_color(24, 249,247,243); /* 128 fg */
	my_init_color(25, 236,206,115); /* 128 bg */
	my_init_color(26, 249,247,243); /* 256 fg */
	my_init_color(27, 236,205,98); /* 256 bg */
	my_init_color(28, 249,247,243); /* 512 fg */
	my_init_color(29, 237,200,80); /* 512 bg */
	my_init_color(30, 249,247,243); /* 1024 fg */
	my_init_color(31, 236,196,63); /* 1024 bg */
	my_init_color(32, 249,247,243); /* 2048 fg */
	my_init_color(33, 236,195,45); /* 2048 bg */

	init_pair(1, 10, 10); /* border */
	init_pair(2, 11, 11); /* bg */
	init_pair(3, 12, 13); /* 2 */
	init_pair(4, 14, 15); /* 4 */
	init_pair(5, 16, 17); /* 8 */
	init_pair(6, 18, 19); /* 16 */
	init_pair(7, 20, 21); /* 32 */
	init_pair(8, 22, 23); /* 64 */
	init_pair(9, 24, 25); /* 128 */
	init_pair(10, 26, 27); /* 256 */
	init_pair(11, 28, 29); /* 512 */
	init_pair(12, 30, 31); /* 1024 */
	init_pair(13, 32, 33); /* 2048 */
	// init_pair(14, 32, COLOR_YELLOW); /* >= 4096 */
	init_pair(14, COLOR_BLACK, COLOR_CYAN); /* >= 4096 */

	// init_pair(1, 10, 10); /* border */
	// init_pair(2, 11, 11); /* bg */
	// init_pair(3, COLOR_BLACK, 13); /* 2 */
	// init_pair(4, COLOR_BLACK, 15); /* 4 */
	// init_pair(5, COLOR_BLACK, 17); /* 8 */
	// init_pair(6, COLOR_BLACK, 19); /* 16 */
	// init_pair(7, COLOR_BLACK, 21); /* 32 */
	// init_pair(8, COLOR_BLACK, 23); /* 64 */
	// init_pair(9, COLOR_BLACK, 25); /* 128 */
	// init_pair(10, COLOR_BLACK, 27); /* 256 */
	// init_pair(11, COLOR_BLACK, 29); /* 512 */
	// init_pair(12, COLOR_BLACK, 31); /* 1024 */
	// init_pair(13, COLOR_BLACK, 33); /* 2048 */

	board = init_board();
	board->cells[2][2] = 32768;
	board->cells[3][2] = 2048;
	print_board(board);
	while ((key = getch()))
	{
		if (key == KEY_RIGHT)
			right(board);
		else if (key == KEY_LEFT)
			left(board);
		else if (key == KEY_UP)
			right(board);
		else if (key == KEY_DOWN)
			left(board);
		else if (key == 'q')
			break ;
		else if (key == 27)
			break ;
		clear();
		print_board(board);
		refresh();
	}

	destroy_board(board);
	endwin();
	return (0);
}
