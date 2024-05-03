/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:36:21 by helauren          #+#    #+#             */
/*   Updated: 2023/10/24 10:31:32 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*destination;
	size_t	i;
	size_t	n;

	if (!src || !dst)
		return (NULL);
	source = (char *)src;
	destination = (char *)dst;
	i = 0;
	n = len;
	if (destination > source)
	{
		while (n-- > 0)
			destination[n] = source[n];
	}
	else
	{
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (destination);
}
