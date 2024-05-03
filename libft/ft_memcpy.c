/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:28 by helauren          #+#    #+#             */
/*   Updated: 2023/05/22 23:26:20 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*udst;
	unsigned char	*usrc;

	i = 0;
	udst = (unsigned char *)dst;
	usrc = (unsigned char *) src;
	if (!usrc)
		return (udst);
	if (!udst)
		return (NULL);
	if (n == 0)
		return (dst);
	while (i < n)
	{
		udst[i] = usrc[i];
		i++;
	}
	return (udst);
}

// int main(void)
// {
//     char src[] = "Hello, world!";
//     char dst[20];

//     // Copy the string from src to dst using ft_memcpy
//     ft_memcpy(dst, src, strlen(src) + 1);

//     // Print the copied string
//     printf("Copied string: '%s'\n", dst);

//     return 0;
// }