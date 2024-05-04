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
#include "../libft/libft.h"

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
