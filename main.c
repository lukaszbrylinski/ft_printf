/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:36:52 by lbrylins          #+#    #+#             */
/*   Updated: 2025/02/17 21:50:59 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_put_hexa_lower(unsigned int number)
{
	char	*base;
	char	buffer[16];
	int		i;
	int		count;
	int		num;

	count = 0;
	i = 0;
	base = "0123456789abcdef";
	num = (unsigned int) number;
	if (num == 0)
		buffer[i] = '0';
	else
	{
		while (num > 0)
		{
			buffer[i++] = base[num % 16];
			num /= 16;
		}
	}
	while (--i >= 0)
		count += write(1, &buffer[i], 1);
	return (count);
}

int	ft_put_hexa_upper(unsigned int number)
{
	char	*base;
	char	buffer[16];
	int		i;
	int		count;
	int		num;

	count = 0;
	i = 0;
	base = "0123456789ABCDEF";
	num = (unsigned int) number;
	if (num == 0)
		buffer[i] = '0';
	else
	{
		while (num > 0)
		{
			buffer[i++] = base[num % 16];
			num /= 16;
		}
	}
	while (--i >= 0)
		count += write(1, &buffer[i], 1);
	return (count);
}

int	ft_put_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		write (1, "(nil)", 5);
	else
	{
	count += write(1, "Ox", 2);
	count += ft_put_hexa_lower((unsigned long) ptr);
	}
	return (count);
}

int	switch_function(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_printf(va_arg(args, int));
	else if (c == 's')
		count += ft_pustr_printf(va_arg(args, char *));
	else if (c == 'p')
		count += ft_put_ptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_printf(va_arg(args, int));
	else if (c == 'u')
		count += ft_put_un_nbr_printf(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_put_hexa_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_put_hexa_upper(va_arg(args, unsigned int));
	else if (c == '%')
		count += ft_putchar_printf('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (str[count])
	{
		if (str[count] != '%')
			count += ft_putchar_printf(str[count]);
			//count += write(1, &str[count], 1);
		else
		{
			count++;
			count += switch_function(str[count], args);
			//count++;
		}
	}
	va_end(args);
	return (count);
}

int	main ()
{
	printf("Hello World%s\n", "Hello World");
	ft_printf("Hello World%s\n", "Hello World");
	return (0);
}
