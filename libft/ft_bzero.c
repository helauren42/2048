/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:05 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 14:56:39 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero( void *dst, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = 0;
		i++;
	}
}

// int main(void)
// {
//     char str[] = "Hello, world!";

//     ft_bzero(str, 20);
//     printf("Modified string: %s\n", str);

//     return (0);
// }