#include "header.h"

void	freeGrid(int **arr, int size)
{
	for(int i = 0; i < size; i++)
		free(arr[i]);
	free(arr);
}