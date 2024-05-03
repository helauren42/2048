/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:03:31 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 15:51:13 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}

// int main(void)
// {
//     int fd;

//     char s[50] = "wueihfgreig";
//     fd = open ("fd/putendl.txt", O_WRONLY | O_CREAT, 0644);
//     ft_putendl_fd(s, fd);
// }
