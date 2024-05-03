/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:39:50 by helauren          #+#    #+#             */
/*   Updated: 2023/05/16 15:42:53 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}

// static void	f(unsigned int i, char *c)
// {
// 	if (i % 2 == 0)
// 		*c = *c + 1;
// 	else
// 		*c = *c - 1;
// }

// int main(void)
// {
//     char s[50] = "abcdefgh";

//     printf("Before = %s\n", s);
//     ft_striteri(s, &f);
//     printf("AFTER = %s\n", s);

//     return (0);
// }