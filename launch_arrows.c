#include "header.h"

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
		// update the grid
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
		// update the grid
		for(int x = data->gridSize -1; x >= 0; x--)
			data->theGrid[x][y] = colum[in];
	}
	free(colum);
}

void	launch_arrows(t_data *data, int key)
{
	if(key == KEY_UP)
		launch_up(data);
	else if(key == KEY_DOWN)
		launch_down(data);
	else if(key == KEY_RIGHT)
		launch_right(data);
	else if(key == KEY_LEFT)
		launch_left(data);
}
