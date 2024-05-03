/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:15:56 by helauren          #+#    #+#             */
/*   Updated: 2023/05/05 17:15:56 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (start >= (size_t)ft_strlen((char *)s))
		len = 0;
	else if (len > (size_t)ft_strlen((char *)s) - start)
		len = (size_t)ft_strlen((char *)s) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (j < len && (start + j) < (size_t) ft_strlen((char *)s))
	{
		str[i] = s[start + j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*output;
// 	char	*output_ptr;

// 	if (start >= ft_strlen(s))
// 	{
// 		output = malloc(1 * sizeof(char));
// 		if (output == NULL)
// 			return (NULL);
// 		*output = '\0';
// 		return (output);
// 	}
// 	if (len > ft_strlen(s) - start)
// 		len = ft_strlen(s) - start;
// 	output = malloc((len + 1) * sizeof(char));
// 	if (output == NULL)
// 		return (NULL);
// 	output_ptr = output;
// 	s += start;
// 	while (*s && len--)
// 		*output_ptr++ = *s++;
// 	*output_ptr = '\0';
// 	return (output);
// }

// int main()
// {
//     char *str = "hola";
//      char *substr;
//      substr = ft_substr(str, 0, 18446744073709551615);
//      printf("Test 1: ft_substr(\"%s\", 0, 4) = \"%s\"\n", str, substr);
//      free(substr);

//      return 0;
// }

// int main()
// {
//     char *str = "This is a test string.";
//     char *substr;

//     substr = ft_substr(str, 0, 4);
//     printf("Test 1: ft_substr(\"%s\", 0, 4) = \"%s\"\n", str, substr);
//     free(substr);

//     substr = ft_substr(str, 8, 6);
//     printf("Test 2: ft_substr(\"%s\", 8, 6) = \"%s\"\n", str, substr);
//     free(substr);

//     substr = ft_substr(str, 4, 20);
//     printf("Test 3: ft_substr(\"%s\", 4, 20) = \"%s\"\n", str, substr);
//     free(substr);

//     substr = ft_substr(str, 10, 0);
//     printf("Test 4: ft_substr(\"%s\", 10, 0) = \"%s\"\n", str, substr);
//     free(substr);

//     substr = ft_substr(str, 20, 5);
//     printf("Test 5: ft_substr(\"%s\", 20, 5) = \"%s\"\n", str, substr);
//     free(substr);

//     return 0;
// }
