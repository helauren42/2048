/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/05/05 16:36:38 by helauren          #+#    #+#             */
/*   Updated: 2023/05/05 16:36:38 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len;

	if (src == NULL || src[0] == 0)
		return (NULL);
	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

// int main(void)
// {
//     printf("'Hello World'= %s\n", ft_strdup("Hello World"));
//     printf("' ' = %s\n", ft_strdup(" "));
//     printf("'uàv'ta[{||[`|`{+*-zauei' = %s\n",
// ft_strdup("uàv'ta[{||[`|`{+*-zauei"));
//     return (0);
// }
