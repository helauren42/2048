/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:15:02 by helauren          #+#    #+#             */
/*   Updated: 2023/05/05 17:15:02 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numwords(char const *s, char c)
{
	int	cur;
	int	word_num;

	cur = 0;
	word_num = 0;
	while (s[cur] != 0)
	{
		if (s[cur] != c && (s[cur + 1] == c || s[cur + 1] == 0))
			word_num++;
		cur++;
	}
	return (word_num);
}

static int	split_words(char **result, char const *s, char c, int word)
{
	int		start_cur;
	int		end_cur;

	end_cur = 0;
	start_cur = 0;
	while (s[end_cur])
	{
		if (s[end_cur] == c || s[end_cur] == 0)
			start_cur = end_cur + 1;
		if (s[end_cur] != c && (s[end_cur + 1] == c || s[end_cur + 1] == 0))
		{
			result[word] = malloc(sizeof(char) * (end_cur - start_cur + 2));
			if (!result[word])
			{
				while (word++)
					free(result[word]);
				return (0);
			}
			ft_strlcpy(result[word], (s + start_cur), end_cur - start_cur + 2);
			word++;
		}
		end_cur++;
	}
	result[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (numwords(s, c) + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c, 0))
		return (NULL);
	return (result);
}

// static int	nbr_of_splits(char const *s, char c)
// {
// 	int	count;
// 	int	i;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			count++;
// 			while (s[i] && s[i] != c)
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (count);
// }

// static int	split_len(char const *s, char c, int i)
// {
// 	int	len;

// 	len = 0;
// 	while (s[i] && s[i] != c)
// 	{
// 		i++;
// 		len++;
// 	}
// 	return (len);
// }

// int	export(char **strs, char *s, int *j, int *i, char c)
// {
// 	int		k;

// 	k = 0;
// 	if (!strs[*j])
// 	{
// 		while (*j >= 0)
// 			free(strs[(*j)--]);
// 		free(strs);
// 		return (0);
// 	}
// 	k = 0;
// 	while (s[*i] && s[*i] != c)
// 		strs[*j][k++] = s[(*i)++];
// 	strs[*j][k] = '\0';
// 	(*j)++;
// 	return (1);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		j;
// 	char	**strs;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	strs = (char **)malloc(sizeof(char *) * (nbr_of_splits(s, c) + 1));
// 	if (!strs)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			strs[j] = (char *)malloc(sizeof(char) * (split_len(s, c, i) + 1));
// 			if (export(strs, (char *)s, &j, &i, c) == 0)
// 				return (NULL);
// 		}
// 		else
// 			i++;
// 	}
// 	strs[j] = NULL;
// 	return (strs);
// }

// void	print_result(char **result)
// {
// 	int	i = 0;
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	char *s1 = "Hello World";
// 	char c1 = ' ';
// 	char **result1 = ft_split(s1, c1);
// 	printf("Test 1:\n");
// 	print_result(result1);
// 	free(result1);

// 	char *s2 = "a,b,c,d,e";
// 	char c2 = ',';
// 	char **result2 = ft_split(s2, c2);
// 	printf("\nTest 2:\n");
// 	print_result(result2);
// 	free(result2);

// 	char *s3 = "One,Two,,Four,Five,";
// 	char c3 = ',';
// 	char **result3 = ft_split(s3, c3);
// 	printf("\nTest 3:\n");
// 	print_result(result3);
// 	free(result3);

// 	char *s4 = "This is a test string with multiple spaces";
// 	char c4 = ' ';
// 	char **result4 = ft_split(s4, c4);
// 	printf("\nTest 4:\n");
// 	print_result(result4);
// 	free(result4);

// 	char *s5 = "OnlyOneWord";
// 	char c5 = ' ';
// 	char **result5 = ft_split(s5, c5);
// 	printf("\nTest 5:\n");
// 	print_result(result5);
// 	free(result5);

// 	char *s6 = "";
// 	char c6 = ' ';
// 	char **result6 = ft_split(s6, c6);
// 	printf("\nTest 6:\n");
// 	print_result(result6);
// 	free(result6);
// 	return (0);
// }

// static void	assign_new(char *strstr, char *s, int *k, int *i)
// {
// 	strstr[*k] = s[*i];
// 	(*k)++;
// 	(*i)++;
// }

// static void	endsplit(char **strstr, int *j, int *k, int *i)
// {
// 	strstr[*j][*k] = 0;
// 	(*i)++;
// 	(*j)++;
// 	(*k) = 0;
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	**strstr;
// 	int		len;

// 	k = 0;
// 	i = 0;
// 	j = 0;
// 	strstr = malloc(sizeof(char *) * (nbr_of_splits(s, c) + 1));
// 	if (!strstr)
// 		return (NULL);
// 	while (j <= nbr_of_splits(s, c))
// 	{
// 		len = split_len(s, c, i);
// 		strstr[j] = malloc(sizeof(char) * (len + 1));
// 		if (!strstr[j])
// 			return (NULL);
// 		while (s[i] && s[i] != c)
// 			assign_new(strstr[j], (char *)s, &k, &i);
// 		endsplit(strstr, &j, &k, &i);
// 	}
// 	strstr[j] = NULL;
// 	return (strstr);
// }