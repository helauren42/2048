#include "2048.h"
#include <stdlib.h>

void	freeGrid(int **arr, int size)
{
	for(int i = 0; i < size; i++)
		if(arr[i])
			free(arr[i]);
	if(arr)
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

void	free_list(t_li *li)
{
	t_li	*prev;

	while(li)
	{
		prev = li;
		li = li->next;
		free(prev);
	}
}
