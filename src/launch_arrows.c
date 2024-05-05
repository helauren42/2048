#include "2048.h"
#include <ncurses.h>
#include "../ft_printf/ft_printf.h"

void	outputArray(int *arr, int size)
{
	for(int i = 0; i < size; i++)
		ft_printf("col[%d] = %d\n", i, arr[i]);
}

void	zeroedColum(int *colum, int size)
{
	for(int i = 0; i < size; i++)
		colum[i] = 0;
}

void	trimArrZeros(int *arr, int size)
{
	int	*temp = malloc(sizeof(int) * (size_t)size);
	int	in = 0;
	
	zeroedColum(temp, size);
	for(int i = 0; i < size; i++)
	{
		if(arr[i] != 0)
		{
			temp[in] = arr[i];
			in++;
		}
	}
	for(int i = 0; i < size; i++)
		arr[i] = temp[i];
	free(temp);
}

void	doubleItUp(int *colum, t_board *board)
{
	int	i = 0;

	while(i +1 < board->dim)
	{
		if(colum[i] == colum[i +1])
		{
			colum[i] = colum[i] + colum[i];
			colum[i+1] = 0;
			trimArrZeros(colum, board->dim);
		}
		i++;
	}
}

void	launch_left(t_board* board)
{
	int	*colum = malloc(sizeof(int) * (size_t)board->dim);
	int	in;

	for(int x = 0; x < board->dim; x++)
	{
		in = 0;
		zeroedColum(colum, board->dim);
		for(int y = 0; y < board->dim; y++)
		{
			if(board->cells[x][y] != 0)
			{
				colum[in] = board->cells[x][y];
				in++;
			}
		}
		doubleItUp(colum, board);
		// update the grid
		for(int y = 0; y < board->dim; y++)
			board->cells[x][y] = colum[y];
	}
	free(colum);
}

void	launch_right(t_board* board)
{
	int	*colum = malloc(sizeof(int) * (size_t)board->dim);
	int	in;

	for(int x = 0; x < board->dim; x++)
	{
		in = 0;
		zeroedColum(colum, board->dim);
		for(int y = board->dim -1; y >= 0; y--)
		{
			if(board->cells[x][y] != 0)
			{
				colum[in] = board->cells[x][y];
				in++;
			}
		}
		doubleItUp(colum, board);
		in = 0;
		for(int y = board->dim -1; y >= 0; y--, in++)
			board->cells[x][y] = colum[in];
	}
	free(colum);
}

void	launch_up(t_board* board)
{
	int	*colum = malloc(sizeof(int) * (size_t)board->dim);
	int	in;

	for(int y = 0; y < board->dim; y++)
	{
		in = 0;
		zeroedColum(colum, board->dim);
		for(int x = 0; x < board->dim; x++)
		{
			if(board->cells[x][y] != 0)
			{
				colum[in] = board->cells[x][y];
				in++;
			}
		}
		doubleItUp(colum, board);
		// update the grid
		for(int x = 0; x < board->dim; x++)
			board->cells[x][y] = colum[x];
	}
	free(colum);
}

void	launch_down(t_board* board)
{
	int	*colum = malloc(sizeof(int) * (size_t)board->dim);
	int	in;

	for(int y = 0; y < board->dim; y++)
	{
		in = 0;
		zeroedColum(colum, board->dim);
		for(int x = board->dim -1; x >= 0; x--)
		{
			if(board->cells[x][y] != 0)
			{
				colum[in] = board->cells[x][y];
				in++;
			}
		}
		doubleItUp(colum, board);
		in = 0;
		for(int x = board->dim -1; x >= 0; x--, in++)
			board->cells[x][y] = colum[in];
	}
	free(colum);
}

void	copyGrid(int **cpy, int **arr, int size)
{
	for(int x = 0; x < size; x++)
	{
		for(int y = 0; y < size; y++)
			cpy[x][y] = arr[x][y];
	}
}

bool	gridCompare(int **cpy, int **arr, int size)
{
	for(int x = 0; x < size; x++)
	{
		for(int y = 0; y < size; y++)
		{
			if(cpy[x][y] != arr[x][y])
				return (false);
		}
	}
	return (true);
}

bool	launch_arrows(t_board *board, int key)
{
	bool	ret;

	int	**cpy = malloc(sizeof(int *) * (size_t)board->dim);
	for(int i = 0; i < board->dim; i++)
	{
		cpy[i] = malloc(sizeof(int) * (size_t)board->dim);
		zeroedColum(cpy[i], board->dim);
	}
	copyGrid(cpy, board->cells, board->dim);
	board->move_failed = false;
	if(key == KEY_UP || key == 'k')
		launch_up(board);
	else if(key == KEY_DOWN || key == 'j')
		launch_down(board);
	else if(key == KEY_RIGHT || key == 'l')
		launch_right(board);
	else if(key == KEY_LEFT || key == 'h')
		launch_left(board);
	else
		ret = false;
	if (gridCompare(cpy, board->cells, board->dim) == true)
	{
		ret = false;
		board->move_failed = true;
	}
	else
		ret = true;
	freeGrid(cpy, board->dim);
	return (ret);
}

void	resetGrid(t_board *board, int **temp)
{
	copyGrid(board->cells, temp, board->dim);
	freeGrid(temp, board->dim);
}

bool	noMovePossible(t_board *board)
{
	int	**temp = malloc(sizeof(int *) * (size_t)board->dim);
	for(int i = 0; i < board->dim; i++)
	{
		temp[i] = malloc(sizeof(int) * (size_t)board->dim);
		zeroedColum(temp[i], board->dim);
	}
	copyGrid(temp, board->cells, board->dim);
	launch_up(board);
	if(gridCompare(temp, board->cells, board->dim) == false)
		return (resetGrid(board, temp), false);
	launch_down(board);
	if(gridCompare(temp, board->cells, board->dim) == false)
		return (resetGrid(board, temp), false);
	launch_right(board);
	if(gridCompare(temp, board->cells, board->dim) == false)
		return (resetGrid(board, temp), false);
	launch_left(board);
	if(gridCompare(temp, board->cells, board->dim) == false)
		return (resetGrid(board, temp), false);
	for(int i = 0; i < board->dim; i++)
		free(temp[i]);
	free(temp);
	return(true);
}
