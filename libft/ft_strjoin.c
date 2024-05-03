/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:00:31 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 15:00:31 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		s[0] = '\0';
	}
	if (!s || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			str[i] = s[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(s) + ft_strlen(buffer)] = '\0';
	free(s);
	return (str);
}

// int main(void)
// {
// 	char    *str1;
// 	char    *str2;
// 	char    *print;

// 	str1 = ft_strdup("Hello World ");
// 	str2 = ft_strdup("Hallo Welt");

// 	print = ft_strjoin(str1, str2);
// 	printf("result = %s", print);
// 	return (0);
// }