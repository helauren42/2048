/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:20 by helauren          #+#    #+#             */
/*   Updated: 2023/10/07 13:52:43 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int main(void)
// {
//     printf("%d\n", ft_isascii("ergui615561rei"));
//     printf("%d\n", ft_isascii("erguir 6654165e rnnrei"));
//     printf("%d\n", ft_isascii("ergu2irernnrei"));
// }
