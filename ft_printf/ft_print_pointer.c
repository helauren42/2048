/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:39:23 by helauren          #+#    #+#             */
/*   Updated: 2023/07/11 12:39:23 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strcmp(char *str, char *nil)
{
	int	i;

	i = 0;
	while (str[i] && nil[i])
	{
		if (str[i] != nil[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_print_pointer(void *value, char *nil)
{
	unsigned long long	address;
	char				*str;
	int					len;

	address = (unsigned long long) value;
	str = ft_tohex(address, "0123456789abcdef");
	if (ft_strcmp(str, nil) == 0)
	{
		free(str);
		ft_putstr("(nil)");
		return (5);
	}
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr("0x");
	ft_putstr(str);
	len = 2 + ft_strlen (str);
	free (str);
	return (len);
}
