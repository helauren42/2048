/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:43 by helauren          #+#    #+#             */
/*   Updated: 2023/10/07 18:50:58 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (ss1[i] == ss2[i] && (ss1[i] != 0 && ss2[i] != 0) && i < n -1)
		i++;
	return (ss1[i] - ss2[i]);
}

// int main(void)
// {
//     printf("%d\n", ft_strncmp("hellooo", "aello", 0));
//     printf("%d\n", ft_strncmp("hellooo", "hello", 5));
//     printf("%d\n", ft_strncmp("hellooo", "hello", 8));
//     printf("%d\n", ft_strncmp("hellooo", "helfwelfeooo", 2));
//     printf("%d\n\n", ft_strncmp("hellooo", "helfwelfeooo", 15));

//     printf("%d\n", strncmp("hellooo", "aello", 0));
//     printf("%d\n", strncmp("hellooo", "hello", 5));
//     printf("%d\n", strncmp("hellooo", "hello", 8));
//     printf("%d\n", strncmp("hellooo", "helfwelfeooo", 2));
//     printf("%d\n", strncmp("hellooo", "helfwelfeooo", 15));
//     return (0);
// }
