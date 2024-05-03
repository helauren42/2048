/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_triple_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:53:10 by helauren          #+#    #+#             */
/*   Updated: 2023/10/24 10:32:17 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_triple_str(char ***s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i])
	{
		free_double_str(s[i]);
		s[i] = NULL;
		i++;
	}
	if (s != NULL)
		free(s);
	s = NULL;
}
