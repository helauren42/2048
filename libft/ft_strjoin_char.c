/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:21:07 by helauren          #+#    #+#             */
/*   Updated: 2023/11/07 12:15:05 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		s[0] = '\0';
	}
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[++i] = 0;
	free(s);
	return (str);
}

// int main() {
//     char *input_string = "Hello, world!";
//     char character_to_add = 'A';

//     char *result = ft_strjoin_char(input_string, character_to_add);

//     if (result) {
//         printf("Original string: %s\n", input_string);
//         printf("Result string: %s\n", result);
//         free(result);
	// Remember to free the memory allocated by ft_strjoin_char
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return (0);
// }
