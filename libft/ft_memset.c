/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:34 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 15:48:19 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

// int main()
// {
//     char str[] = "Hello, world!";

//     // Set the first 5 characters to 'X' using ft_memset
//     ft_memset(str, 'X', 15);

//     // Print the modified string
//     printf("Modified string: %s\n", str);

//     return 0;
// }