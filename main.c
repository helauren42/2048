#include "header.h"

void	outputGrid(t_data *data)
{
	ft_printf("GRID:\n");
	for(int i = 0; i < data->gridSize; i++)
	{
		for(int j = 0; j < data->gridSize; j++)
			ft_printf("%d |", data->theGrid[i][j]);
		ft_printf("\n");
	}
}

void	outputPos(char *str, t_pos pos)
{
	ft_printf("%s", str);
	ft_printf("x = %d, y = %d\n", pos.x, pos.y);
}

int	two_or_four(void)
{
	srand(time(NULL));
	unsigned int two_or_four = rand();
	if(two_or_four % 5 == 0)
		two_or_four = 4;
	else
		two_or_four = 2;
	return (two_or_four);
}

void	setZeroAmount(t_data *data)
{
	data->zeroAmount = 0;
	for(int i = 0; i < data->gridSize; i++)
	{
		for(int j = 0; j < data->gridSize; j++)
		{
			if(data->theGrid[i][j] == 0)
				data->zeroAmount++;
		}
	}
}

t_pos	findFirstZero(t_data *data, t_pos start)
{
	t_pos	found;
	int	i = start.x;
	int j;

	while(i < data->gridSize)
	{
		if(i == start.x)
			j = start.y;
		else
			j = 0;
		while(j < data->gridSize)
		{
			if(data->theGrid[i][j] == 0)
				return(found.x = i, found.y = j, found);
			j++;
		}
		i++;
	}
	return(found.x = -1, found.y = -1, found);
}

t_pos	incrementPosition(t_data *data, t_pos pos)
{
	if(pos.y < data->gridSize -1)
		return (pos.y++, pos);
	pos.x++;
	if(pos.x >= data->gridSize)
		return(pos.x = 0, pos.y = 0, pos);
	pos.y = 0;
	return(pos);
}

t_pos	getRandomZeroPos(t_data *data)
{
	t_pos	ret;
	ret.x = 0;
	ret.y = 0;
	unsigned int	randomNum = rand();

	setZeroAmount(data);
	if(data->zeroAmount <= 0)
		return (ret.x = -1, ret.y = -1, ret);
	unsigned int pos = randomNum % (data->zeroAmount) +1;
	for (int i = 0; i < (int)pos; i++)
	{
		ret = findFirstZero(data, ret);
		if(i == (int)pos -1)
			break;
		ret = incrementPosition(data, ret);
	}
	return (ret);
}

void initPosition(t_data *data, t_pos pos)
{
	data->theGrid[pos.x][pos.y] = two_or_four();
}

void	playing(t_data *data)
{
	while(1)
	{
		// TIMO's turn display GRID

		// retrieve key move and update GRID
		int	key = KEY_RIGHT;
		launch_arrows(data, key);
		// add new position to the board
		srand(time(NULL));
		ft_printf("\n");
		outputGrid(data);
		t_pos pos1 = getRandomZeroPos(data);
		outputPos("pos1: ", pos1);
		initPosition(data, pos1);
		outputGrid(data);
		setZeroAmount(data);
		if(data->zeroAmount <= 0 && noMovePossible(data) == true)
		{
			ft_printf("GAME OVER\n");
			return ;
		}
	}
}

int	main(int ac, char **av)
{
	if(ac > 2)
	{
		ft_printf("Bruh what is this ?!\nexecute the thing and valid format is either a 4 or 5 as argument nothing else\n");
		return (1);
	}
	t_data *data = malloc(sizeof(t_data));
	if(ac == 2)
	{
		if(ft_strcmp(av[1], "4") && ft_strcmp(av[1], "5"))
		{
			ft_printf("Bruh what is this ?!\nexecute the thing and valid format is either a 4 or 5 as argument nothing else\n");
			free(data);
			return (1);
		}
		data->gridSize = atoi(av[1]);
	}
	else
		data->gridSize = 4;
	data->theGrid = malloc(sizeof(int *) * data->gridSize);
	for(int b = 0; b < data->gridSize; b++)
	{
		data->theGrid[b] = malloc(sizeof(int) * data->gridSize);
		for(int a = 0; a < data->gridSize; a++)
			data->theGrid[b][a] = 0;
	}
	srand(time(NULL));
	t_pos pos1 = getRandomZeroPos(data);
	srand(time(NULL) / 3);
	t_pos pos2 = getRandomZeroPos(data);
	while(pos1.x == pos2.x && pos1.y == pos2.y)
		pos2 = getRandomZeroPos(data);
	initPosition(data, pos1);
	initPosition(data, pos2);
	ft_printf("STARTING POSITIONS:\n");
	outputGrid(data);
	ft_printf("\n");
	playing(data);
	return (0);
}
