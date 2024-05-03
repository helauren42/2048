/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:46 by helauren          #+#    #+#             */
/*   Updated: 2023/05/23 01:41:49 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && big[i] == little[i] && little[i] != '\0')
		i++;
	if (little[i] == '\0')
		return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	if (big[i] == '\0')
		return (NULL);
	while (i < len && big[i] != '\0')
	{
		if (compare(&big[i], little, len - i) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     printf("%s\n", ft_strnstr("weewfe", "eew", 5));
//     printf("%s\n", ft_strnstr("weewfe", "eaw", 5));
//     printf("%s\n", ft_strnstr("weewfe", "eew", 1));
//     printf("%s\n", ft_strnstr("weawfe", "", 3));
//     printf("%s\n", ft_strnstr("", "eew", 4));

//     return (0);
// }