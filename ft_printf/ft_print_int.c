/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 06:22:00 by helauren          #+#    #+#             */
/*   Updated: 2023/07/11 14:49:53 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	all_putnbr(long nb)
{
	char	mod;

	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		all_putnbr(nb / 10);
	mod = nb % 10 + '0';
	write (1, &mod, 1);
}

int	nbr_len(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len ++;
	}
	return (len);
}

int	ft_int(int n)
{
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	all_putnbr(n);
	return (nbr_len(n));
}

int	un_int(unsigned int n)
{
	int				count;

	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	count = nbr_len(n);
	all_putnbr(n);
	return (count);
}
