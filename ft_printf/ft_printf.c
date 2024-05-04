/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:39:36 by helauren          #+#    #+#             */
/*   Updated: 2023/07/11 12:39:36 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	validrchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	percentage(va_list args, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_putchar(va_arg(args, int));
	if (format == 's' )
		count = ft_putstr(va_arg(args, char *));
	if (format == 'p')
		count = ft_print_pointer(va_arg(args, void *), "0x0");
	if (format == 'd' || format == 'i')
		count = ft_int(va_arg(args, int));
	if (format == 'u')
		count = un_int(va_arg(args, unsigned int));
	if (format == 'x')
		count = ft_hex(va_arg(args, int), "0123456789abcdef");
	if (format == 'X')
		count = ft_hex(va_arg(args, int), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	char	a;
	int		count;
	va_list	args;

	a = 37;
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (validrchr("cspdiuxX", format[i + 1]) != 0)
				count += percentage(args, format[i + 1]);
			else if (format[i + 1] == '%')
				count += write (1, &a, 1);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// int main (void)
// {
// 	int	a;

// 	a = 1;
// 	ft_printf("ft_prinft = %x\n", a);
// 	printf("prinft = %x\n", a);
// }

// int	main(void)	
// {
// 	int i;

// 	i = ft_printf("%p\n", 0);
// 	ft_putstr("here is i = ");
// 	all_putnbr(i);
// 	printf ("\nprintf = %p\n", -1);
// 	i = ft_printf("%p\n", INT_MIN);
// 	ft_putstr("here is i = ");
// 	all_putnbr(i);
// 	printf ("\nprintf = %p\n", INT_MIN);

// 	return (0);
// }

// int main()
// {
//     // Test %c: Prints a single character
//     ft_printf("Testing %%c: %c\n", 'A');
//     ft_printf("Testing %%c: %c\n", '\0'); // Null character
//     ft_printf("Testing %%c: %c\n", 255);  // Extended ASCII character

//     // Test %s: Prints a string
//     ft_printf("Testing %%s: %s\n", "Hello, World!");
//     ft_printf("Testing %%s: %s\n", NULL); // Null string

//     // Test %p: Prints a void pointer in hexadecimal format
//     int x = 42;
//     ft_printf("Testing %%p: %p\n", &x);
//     ft_printf("Testing %%p: %p\n", NULL); // Null pointer

//     // Test %d: Prints a decimal number
//     ft_printf("Testing %%d: %d\n", 12345);
//     ft_printf("Testing %%d: %d\n", -12345);
//     ft_printf("Testing %%d: %d\n", 0);

//     // Test %i: Prints an integer in base 10
//     ft_printf("Testing %%i: %i\n", 6789);
//     ft_printf("Testing %%i: %i\n", -6789);
//     ft_printf("Testing %%i: %i\n", 0);

//     // Test %u: Prints an unsigned decimal number
//     ft_printf("Testing %%u: %u\n", 54321);
//     ft_printf("Testing %%u: %u\n", 0);

//     // Test %x: Prints a number in hexadecimal lowercase format
//     ft_printf("Testing %%x: %x\n", 255);
//     ft_printf("Testing %%x: %x\n", 0);

//     // Test %X: Prints a number in hexadecimal uppercase format
//     ft_printf("Testing %%X: %X\n", 255);
//     ft_printf("Testing %%X: %X\n", 0);

//     // Test %%: Prints a percent sign
//     ft_printf("Testing %%%%: %%\n");

//     return 0;
// }

// int	main(void)
// {
// 	// int		num = -5;
// 	// double	pi = 3.14159;
// 	// char	a = 'A';
// 	// char	*n = NULL;
// 	char	*str = "Hello, world!";
// 	// int len;

// 	// ft_printf("Testing ft_printf:\n");
// 	// ft_printf("\nNumber: %d here %d wtrtr\n\n", num, num);
// 	// printf("Number: %d\n here %d wtrtr", num, num);
// 	// ft_printf("Pi: %.2f\n", pi);
// 	// ft_printf("Character: %c\n", ch);
// 	// ft_printf("String: %s\n", str);
// 	// len = ft_printf ("un = %u, ag%%ain = %u\n", num, num);
// 	// ft_printf ("len = %d\n", len);
// 	// ft_printf ("hex = %x\n", num);
// 	ft_printf ("address = %p\n", str);
// 	printf ("address = %p\n", str);
// 	return 0;
// }
