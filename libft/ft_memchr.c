/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:22 by helauren          #+#    #+#             */
/*   Updated: 2023/05/23 02:01:42 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     char *print;

//     print = (char *) ft_memchr("fweifne", 'i', 5);
//     printf("%s\n", print);

//     print = (char *) ft_memchr("fweifne", 'a', 5);
//     printf("%s\n", print);

//     return (0);
// }