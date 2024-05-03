/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:14:55 by helauren          #+#    #+#             */
/*   Updated: 2023/05/05 17:14:55 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	len_int(long int n)
{
	int			i;
	long int	div;

	i = 0;
	div = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while ((n / div) > 0)
	{
		div = div * 10;
		i++;
	}
	return (i);
}

static void	ft_reverse_str(char *str)
{
	int		i;
	int		len;
	int		max;
	char	swap;

	i = 0;
	len = 0;
	while (str[len] != 0)
		len++;
	if (str[i] == '-')
		i = 1;
	max = len - 1;
	while (i < len / 2 + 1)
	{
		swap = str[i];
		str[i] = str[max];
		str[max] = swap;
		i++;
		max--;
	}
	str[len] = 0;
}

static void	this_reverse(char *str)
{
	int		i;
	int		len;
	int		max;
	char	swap;

	i = 0;
	len = 0;
	while (str[len] != 0)
		len++;
	max = len - 1;
	while (i < len / 2)
	{
		swap = str[i];
		str[i] = str[max];
		str[max] = swap;
		i++;
		max--;
	}
	str[len] = 0;
}

static void	itoa_core(long int n, char *str)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;

	i = 0;
	str = malloc(sizeof(char) * len_int(n) + 1);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[i] = '0';
		str[1] = 0;
		return (str);
	}
	itoa_core(n, str);
	if (n > 0 && len_int(n) % 2 == 0)
		this_reverse(str);
	else
		ft_reverse_str(str);
	return (str);
}

// int main(void)
// {
//     char *str;

//     // str = ft_itoa(123844);
//     // printf("output = %s\n\n", str);
// 	// str = ft_itoa(-123844);
//     // printf("output = %s\n\n", str);
// 	// str = ft_itoa(-1523844);
//     // printf("output = %s\n\n", str);
// 	str = ft_itoa(INT_MAX);
//     printf("output = %s\n", str);
//     // str = ft_itoa(48);
//     // printf("output = %s\n\n", str);
//     // str = ft_itoa(INT_MIN);
//     // printf("output = %s\n\n", str);
//     // str = ft_itoa(0);
//     // printf("output = %s\n\n", str);
//     // str = ft_itoa(-2347854);
//     // printf("output = %s\n\n", str);

//     free (str);
//     return (0);
// }
