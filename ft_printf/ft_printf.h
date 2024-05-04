/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:39:43 by helauren          #+#    #+#             */
/*   Updated: 2023/07/11 12:39:43 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
void	all_putnbr(long nb);
int		un_int(unsigned int n);
int		ft_int(int n);
int		nbr_len(long nb);
int		ft_hex(int nb, char *base);
int		tohexlen(unsigned long long nb);
int		ft_strcmp(char *str, char *nil);
int		ft_print_pointer(void *value, char *nil);
int		ft_strlen(char *str);
char	*ft_tohex(unsigned long long nb, char *base);
char	*ft_ntohex(unsigned long long nb, char *base);
int		ft_putstr(char *s);

#endif