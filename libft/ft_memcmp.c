/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:25 by helauren          #+#    #+#             */
/*   Updated: 2023/05/23 00:15:52 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
//     printf("%d\n", ft_memcmp("hellooo", "hello", 5));
//     printf("%d\n", ft_memcmp("hellooo", "hello", 8));
//     printf("%d\n", ft_memcmp("hellooo", "helfwelfeooo", 2));
//     printf("%d\n\n", ft_memcmp("hellooo", "helfwelfeooo", 15));

//     printf("%d\n", memcmp("hellooo", "hello", 5));
//     printf("%d\n", memcmp("hellooo", "hello", 8));
//     printf("%d\n", memcmp("hellooo", "helfwelfeooo", 2));
//     printf("%d\n", memcmp("hellooo", "helfwelfeooo", 15));
//     return (0);
// }