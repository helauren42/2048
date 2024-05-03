/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:36 by helauren          #+#    #+#             */
/*   Updated: 2024/04/05 23:05:46 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// char	*ft_strchr(const char *str, int c)
// {
// 	int				i;
// 	unsigned char	cc;

// 	cc = (unsigned char) c;
// 	i = 0;
// 	if ((char *)str == NULL)
// 		return (NULL);
// 	while ((unsigned char) str[i])
// 	{
// 		if ((unsigned char)str[i] == cc)
// 			return ((char *) &str[i]);
// 		i++;
// 	}
// 	if (str[i] == (unsigned char) c)
// 		return ((char *) &str[i]);
// 	return (NULL);
// }

// int main(void)
// {
//     const char str[20] = "fkewlnkewfeew"; 
//     printf("%s", strchr (str, 'l'));
//     return (0);
// }