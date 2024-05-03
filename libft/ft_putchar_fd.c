/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:49:30 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 15:50:53 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int main(void)
// {
//     int fd = open("fd/putchar.txt", O_WRONLY |
//  O_CREAT, 0644); // open file for writing
//     if (fd == - 1)
//     {
//         return 1;
//     }

//     ft_putchar_fd('H', fd);
//     ft_putchar_fd('e', fd);
//     ft_putchar_fd('l', fd);
//     ft_putchar_fd('l', fd);
//     ft_putchar_fd('o', fd);
//     ft_putchar_fd('\n', fd);

//     close(fd);

//     return 0;
// }