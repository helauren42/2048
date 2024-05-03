/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:00 by helauren          #+#    #+#             */
/*   Updated: 2023/11/07 20:47:54 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	test(const char *nptr, int *i, long *sign)
{
	if (nptr[*i] == '+')
		(*i)++;
	if (nptr[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	n;
	long	sign;
	long	value;

	i = 0;
	sign = 1;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' && nptr[i + 1] == '-')
		return (0);
	test(nptr, &i, &sign);
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		value = nptr[i] - '0';
		n = n * 10 + value;
		i++;
	}
	return (sign * n);
}
