/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:28:23 by helauren          #+#    #+#             */
/*   Updated: 2023/11/27 17:24:56 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		towrite;

	nb = (long)n;
	if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	towrite = nb % 10 + '0';
	write(fd, &towrite, 1);
}

// int main(void)
// {
//     int fd;

//     fd = open("fd/putnbr.txt", O_WRONLY | O_CREAT, 0644);
//     ft_putnbr_fd(-555, fd);
//     write (fd, "\n", 1);
//     ft_putnbr_fd(INT_MIN, fd);
//     return (0);
// }