/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:54 by helauren          #+#    #+#             */
/*   Updated: 2023/05/16 16:48:05 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	car;

	car = (unsigned char) c;
	if (c >= 'a' && c <= 'z')
		car -= 32;
	return (car);
}

// int main(void)
// {
//     printf("%c", ft_toupper('a'));
//     return (0);
// }