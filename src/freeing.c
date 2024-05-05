#include "2048.h"
#include <stdlib.h>

void	freeGrid(int **arr, int size)
{
	for(int i = 0; i < size; i++)
		free(arr[i]);
	free(arr);
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