/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:39:38 by helauren          #+#    #+#             */
/*   Updated: 2023/05/16 15:22:42 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

// int main(void)
// {
//     printf("%d\n", ft_isalpha(99));
//     printf("%d\n", ft_isalpha('b'));
//     printf("%d\n", ft_isalpha('2'));
// }
