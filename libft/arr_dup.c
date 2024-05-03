/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:40:41 by helauren          #+#    #+#             */
/*   Updated: 2023/10/24 10:33:46 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	*arr_dup(int *stack, int len)
{
	int	i;
	int	*dup;

	i = 0;
	dup = malloc(sizeof(int) * len);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = stack[i];
		i++;
	}
	return (dup);
}
