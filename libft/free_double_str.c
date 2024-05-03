/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:52:05 by helauren          #+#    #+#             */
/*   Updated: 2023/11/04 14:19:26 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_double_str(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s && s[i])
	{
		if (s[i] != NULL)
		{
			free(s[i]);
			s[i] = NULL;
		}
		i++;
	}
	if (s != NULL)
		free(s);
	s = NULL;
}
