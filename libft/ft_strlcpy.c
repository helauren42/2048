/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:45:32 by helauren          #+#    #+#             */
/*   Updated: 2023/05/23 00:55:24 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (src[i] != 0 && i < size - 1 && size > 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != 0)
		i++;
	return (i);
}

// int main(void)
// {
// 	char src[] = "Hello, world!";
// 	char dest[20];

// 	unsigned int len = ft_strlcpy(dest, src, 0);
// 	printf("Copied string length: %u\n", len);

// 	printf("Copied string: %s\n", dest);

// 	char src2[] = "Hello, world!";
// 	char dest2[4];

// 	unsigned int len2 = ft_strlcpy(dest2, src2, sizeof(dest2));
// 	printf("Copied string length: %u\n", len2);

// 	printf("Copied string: %s\n", dest2);

// 	return 0;
// }