/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:18 by helauren          #+#    #+#             */
/*   Updated: 2024/04/05 22:58:29 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
	{
		return (0);
	}
	return (1);
}

// int main(void)
// {
//     printf("%d\n", ft_isdigit('8'));
//     printf("%d\n", ft_isdigit('7'));
//    printf("%d\n", ft_isdigit('a'));
// }
