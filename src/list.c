#include "2048.h"
#include <time.h>
#include <stdlib.h>

t_li *cleanUpOldOnes(t_li *list)
{
	t_li			*first = list;
	unsigned int	curr_time = (unsigned int)time(NULL);

	t_li	*prev = NULL;
	while(list && list->next)
	{
		if(curr_time - list->time > 2)
		{
			t_li	*temp = list;
			list = list->next;
			if(prev == NULL)
				first = list;
			else
				prev->next = list;
			free(temp);
		}
		else
		{
			prev = list;
			list = list->next;
		}
	}
	return(first);
}

void	addCurrTimeStampAndLength(t_board *board)
{
	t_li	*curr = board->list;
	board->list_length = 1;

	while(curr && curr->next)
	{
		curr = curr->next;
		board->list_length++;
	}

	t_li	*new = malloc(sizeof(t_li));
	new->next = NULL;
	new->time = (unsigned int) time(NULL);
	if(curr == NULL)
		board->list = new;
	else
		curr->next = new;
}

t_li	*updateList(t_board *board)
{
	board->list = cleanUpOldOnes(board->list);
	addCurrTimeStampAndLength(board);
	if(board->list_length > 10)
		board->div = 10;
	else if(board->list_length > 5)
		board->div = 7;
	else if(board->list_length >= 3)
		board->div = 3.5;
	else if(board->list_length >= 2)
		board->div = 1.8;
	return (board->list);
}