#include "header.h"

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
	int	*temp = malloc(sizeof(int) * size);
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
}

void	doubleItUp(int *colum, t_data *data)
{
	int	i = 0;

	while(i +1 < data->gridSize)
	{
		if(colum[i] == colum[i +1])
		{
			colum[i] = colum[i] + colum[i];
			colum[i +1] = 0;
			trimArrZeros(colum, data->gridSize);
		}
		i++;
	}
}

void	launch_left(t_data* data)
{
	int	*colum = malloc(sizeof(int) * data->gridSize);
	int	in;

	for(int x = 0; x < data->gridSize; x++)
	{
		in = 0;
		zeroedColum(colum, data->gridSize);
		for(int y = 0; y < data->gridSize; y++)
		{
			if(data->theGrid[x][y] != 0)
			{
				colum[in] = data->theGrid[x][y];
				in++;
			}
		}
		doubleItUp(colum, data);
		// update the grid
		for(int y = 0; y < data->gridSize; y++)
			data->theGrid[x][y] = colum[y];
	}
	free(colum);
}

void	launch_right(t_data* data)
{
	int	*colum = malloc(sizeof(int) * data->gridSize);
	int	in;

	for(int x = 0; x < data->gridSize; x++)
	{
		in = 0;
		zeroedColum(colum, data->gridSize);
		for(int y = data->gridSize -1; y >= 0; y--)
		{
			if(data->theGrid[x][y] != 0)
			{
				colum[in] = data->theGrid[x][y];
				in++;
			}
		}
		doubleItUp(colum, data);
		in = 0;
		for(int y = data->gridSize -1; y >= 0; y--, in++)
			data->theGrid[x][y] = colum[in];
	}
	free(colum);
}

void	launch_up(t_data* data)
{
	int	*colum = malloc(sizeof(int) * data->gridSize);
	int	in;

	for(int y = 0; y < data->gridSize; y++)
	{
		in = 0;
		zeroedColum(colum, data->gridSize);
		for(int x = 0; x < data->gridSize; x++)
		{
			if(data->theGrid[x][y] != 0)
			{
				colum[in] = data->theGrid[x][y];
				in++;
			}
		}
		doubleItUp(colum, data);
		// update the grid
		for(int x = 0; x < data->gridSize; x++)
			data->theGrid[x][y] = colum[x];
	}
	free(colum);
}

void	launch_down(t_data* data)
{
	int	*colum = malloc(sizeof(int) * data->gridSize);
	int	in;

	for(int y = 0; y < data->gridSize; y++)
	{
		in = 0;
		zeroedColum(colum, data->gridSize);
		for(int x = data->gridSize -1; x >= 0; x--)
		{
			if(data->theGrid[x][y] != 0)
			{
				colum[in] = data->theGrid[x][y];
				in++;
			}
		}
		doubleItUp(colum, data);
		in = 0;
		for(int x = data->gridSize -1; x >= 0; x--, in++)
			data->theGrid[x][y] = colum[in];
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

void	launch_arrows(t_data *data, int key)
{
	int	**cpy = malloc(sizeof(int *) * data->gridSize);
	for(int i = 0; i < data->gridSize; i++)
	{
		cpy[i] = malloc(sizeof(int) * data->gridSize);
		zeroedColum(cpy[i], data->gridSize);
	}
	copyGrid(cpy, data->theGrid, data->gridSize);
	while(gridCompare(cpy, data->theGrid, data->gridSize) == true)
	{
		copyGrid(cpy, data->theGrid, data->gridSize);
		if(key == KEY_UP)
			launch_up(data);
		else if(key == KEY_DOWN)
			launch_down(data);
		else if(key == KEY_RIGHT)
			launch_right(data);
		else if(key == KEY_LEFT)
			launch_left(data);
	}
	freeGrid(cpy, data->gridSize);
}

void	resetGrid(t_data *data, int **temp)
{
	copyGrid(data->theGrid, temp, data->gridSize);
	freeGrid(temp, data->gridSize);
}

bool	noMovePossible(t_data *data)
{
	int	**temp = malloc(sizeof(int *) * data->gridSize);
	for(int i = 0; i < data->gridSize; i++)
	{
		temp[i] = malloc(sizeof(int ) * data->gridSize);
		zeroedColum(temp[i], data->gridSize);
	}
	copyGrid(temp, data->theGrid, data->gridSize);
	launch_up(data);
	if(gridCompare(temp, data->theGrid, data->gridSize) == false)
		return (resetGrid(data, temp), false);
	launch_down(data);
	if(gridCompare(temp, data->theGrid, data->gridSize) == false)
		return (resetGrid(data, temp), false);
	launch_right(data);
	if(gridCompare(temp, data->theGrid, data->gridSize) == false)
		return (resetGrid(data, temp), false);
	launch_left(data);
	if(gridCompare(temp, data->theGrid, data->gridSize) == false)
		return (resetGrid(data, temp), false);
	return(true);
}
