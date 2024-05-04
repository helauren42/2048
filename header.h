#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <time.h>
# include <ncurses.h>
# include <stdbool.h>

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_data
{
	int	gridSize;
	int	**theGrid;
	int	zeroAmount;
}				t_data;

void	launch_arrows(t_data *data, int key);
bool	noMovePossible(t_data *data);
void	freeGrid(int **arr, int size);

#endif