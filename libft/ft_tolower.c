/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:52 by helauren          #+#    #+#             */
/*   Updated: 2023/05/16 20:16:41 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	car;

	car = (unsigned char) c;
	if (c >= 'A' && c <= 'Z')
		car = car + 32;
	return (car);
}

// int main(void)
// {
//     printf("%c", ft_tolower('A'));
//     return (0);
// }