/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:16:30 by lbrylins          #+#    #+#             */
/*   Updated: 2025/02/02 21:33:30 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_printf(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_pustr_printf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_printf(int n)
{
	int		num;

	num = 0;
	if (n <= -2147483648)
	{
		num += write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			num += write(1, "-", 1);
			n *= -1;
			ft_putnbr_printf(n);
		}
		else if (n > 9)
		{
			ft_putnbr_printf(n / 10);
			ft_putnbr_printf(n % 10);
		}
		else if (n <= 9)
			num += write(1, &((char[]){num + '0'}), 1);
	}
	return (num);
}

int	ft_put_un_nbr_printf(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
	{
		ft_putnbr_un_printf(n / 10);
		ft_putnbr_un_printf(n % 10);
	}
	else if (n <= 9)
		count += write(1, &((char[]){count + '0'}), 1);

	return (count);
}

int	ft_put_hexa_lower(int number)
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

int	ft_puthexa_upper(int number)
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
	count += write(1, "Ox", 2);
	count += ft_puthexa_lower((unsigned long) ptr);
	return (count);
}
