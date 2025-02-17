/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:35:59 by lbrylins          #+#    #+#             */
/*   Updated: 2025/02/17 19:42:28 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_put_hexa_lower(unsigned int number);
int	ft_put_hexa_upper(unsigned int number);
int	ft_put_ptr(void *ptr);
int	switch_function(char c, va_list args);
int			ft_printf(const char *str, ...);
int			ft_putchar_printf(char c);
int			ft_pustr_printf(char *str);
int			ft_putnbr_printf(int n);
int			ft_put_un_nbr_printf(unsigned int n);

#endif