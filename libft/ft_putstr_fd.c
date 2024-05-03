/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:27:17 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 15:52:01 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		write (fd, &s[i], 1);
		i++;
	}
}

// int main(void)
// {
//     int fd;
//     char s[50] = "wejfneewnfe";

//     fd = open("fd/putstr.txt", O_WRONLY | O_CREAT, 0644);
//     printf("%d\n", fd);
//     ft_putstr_fd(s, fd);
// }