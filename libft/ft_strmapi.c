/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:51:51 by helauren          #+#    #+#             */
/*   Updated: 2023/05/22 23:14:13 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*ss;
	char			value;

	i = 0;
	len = ft_strlen((char *)s);
	ss = malloc (sizeof(char) * (len + 1));
	if (!s || !ss)
		return (NULL);
	while (i < len)
	{
		value = f(i, s[i]);
		ss[i] = value;
		i++;
	}
	ss[i] = 0;
	return ((char *)ss);
}

// char test_func(unsigned int i, char c)
// {
//     if (i % 2 == 0)
//         return (c + 1);
//     else
//         return (c - 1);
// }

// int main(void)
// {
//     char *result = NULL;

//     // Test case 1: Test with empty string
//     result = ft_strmapi("", &test_func);
//     if (strcmp(result, "") == 0)
//         printf("Test case 1 passed\n");
//     else
//         printf("Test case 1 failed\n");
//     // Test case 2: Test with non-empty string
//     result = ft_strmapi("Hello, world", &test_func);
//     if (strcmp(result, "Idmkp+!vpqmc") == 0)
//         printf("Test case 2 passed\n");
//     else
//         printf("Test case 2 failed\n");
//     printf ("%s\n", result);
//     free(result);

//     return 0;
// }