/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_nofree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:05:20 by helauren          #+#    #+#             */
/*   Updated: 2023/10/24 10:31:12 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_nofree(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2)
				+ 1));
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = 0;
	return (str);
}
