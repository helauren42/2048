/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:08 by helauren          #+#    #+#             */
/*   Updated: 2023/05/16 20:17:29 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
	{
		return (1);
	}
	return (0);
}

// int main(void)
// {
// printf("%d\n", ft_isalnum('a'));
// printf("%d\n", ft_isalnum('!'));
//  printf("%d\n", ft_isalnum('2'));
// }
