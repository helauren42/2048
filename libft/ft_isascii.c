/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:15 by helauren          #+#    #+#             */
/*   Updated: 2023/05/16 20:17:01 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

// int main(void)
// {
//     printf("%d\n", ft_isascii("ergui615561rei"));
//     printf("%d\n", ft_isascii("erguir 6654165e rnnrei"));
//     printf("%d\n", ft_isascii("ergu2irernnrei"));
// }
