/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:39:47 by helauren          #+#    #+#             */
/*   Updated: 2023/07/11 12:39:47 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_rev(char *str, int len)
{
	int		i;
	int		j;
	char	*rev;

	rev = malloc (sizeof(char) * (len + 1));
	if (!rev)
		return (NULL);
	i = 0;
	j = len - 1;
	while (j >= 0)
	{
		rev[i] = str[j];
		i++;
		j--;
	}
	rev[i] = 0;
	free (str);
	return (rev);
}

int	tohexlen(unsigned long long nb)
{
	int	len;

	if (nb < 0)
		return (8);
	len = 1;
	while (nb > 15)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

char	*ft_tohex(unsigned long long nb, char *base)
{
	char	*str;
	int		i;
	int		len2;
	int		len;

	len = tohexlen(nb);
	i = 0;
	str = malloc (sizeof(char) * (1 + len));
	if (!str)
		return (NULL);
	len2 = len;
	while (len2 != 0)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
		len2--;
	}
	str[i] = 0;
	str = str_rev(str, len);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_ntohex(unsigned long long nb, char *base)
{
	char	*str;
	int		i;
	int		len2;
	int		len;

	len = 8;
	i = 0;
	str = malloc (sizeof(char) * (1 + 8));
	if (!str)
		return (NULL);
	len2 = len;
	while (len2 != 0)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
		len2--;
	}
	str[i] = 0;
	str = str_rev(str, len);
	if (!str)
		return (NULL);
	return (str);
}

int	ft_hex(int nb, char *base)
{
	int		len;
	char	*str;

	if (nb < 0)
		str = ft_ntohex(nb, base);
	else
		str = ft_tohex(nb, base);
	if (!str)
		return (0);
	ft_putstr (str);
	len = ft_strlen(str);
	free (str);
	return (len);
}
