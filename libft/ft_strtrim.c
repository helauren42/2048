/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:08:36 by helauren          #+#    #+#             */
/*   Updated: 2024/04/06 14:41:47 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkstart(char *s1, char *set)
{
	int	i;
	int	j;
	int	boul;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		boul = 1;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
				boul = 0;
			j++;
		}
		if (boul == 1)
			break ;
		i++;
	}
	return (i);
}

static int	checkend(char *s1, char *set, int len_s1, int len_set)
{
	int	i;
	int	j;
	int	boul;
	int	trim;

	trim = 0;
	i = len_s1 - 1;
	while (i >= 0)
	{
		j = 0;
		boul = 1;
		while (j < len_set && s1[i] != '\0')
		{
			if (set[j] == s1[i])
				boul = 0;
			j++;
		}
		if (boul == 1)
			break ;
		trim++;
		i--;
	}
	return (trim);
}

static char	*copying(char *cpy, char *s1, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		cpy[i] = s1[start];
		start++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		len_new;
	char	*cpy;
	int		len_s1;
	int		len_set;
	int		trim;

	len_new = 0;
	if (!s1 || !set)
		return (NULL);
	len_s1 = checkstart(s1, set);
	len_set = ft_strlen(set);
	trim = checkend(s1, set, ft_strlen(s1), len_set);
	len_new = ft_strlen(s1) - len_s1 - trim;
	if (len_new < 0)
		len_new = 0;
	cpy = (char *)malloc(sizeof(char) * (len_new + 1));
	if (!cpy)
		return (NULL);
	cpy = copying(cpy, s1, len_s1, len_s1 + len_new);
	return (cpy);
}

// int main (void)
// {
// 	char *s1 = "  \t \t \n   \n\n\n\t";
//     char *s2 = "";
//     char *s;
// 	s = malloc(sizeof(char) * 60);
// 	s = ft_strtrim(s1, " \n\t");
// 	printf("'%s'\n", s);
// }

// int main(void)
// {
//     char *str;
//     str = malloc(sizeof(char) * 60);
//     str = ft_strtrim(" . abcd", " ");
//     printf("'%s'\n", str);
//     str = ft_strtrim(" arsadfv  ea  sr flo a", "ar");
//     printf("'%s'\n", str);
//     str = ft_strtrim(" Helasrflo a", "o");
//     printf("'%s'\n", str);
//     str = ft_strtrim(" Helasrflo er", "re");
//     printf("'%s'\n", str);
//     free(str);
//     return (0);
// }
