/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 14:24:14 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/03/07 18:35:53 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printf_flags(char input, va_list args)
{
	if (input == 's')
		return (ft_putstring(va_arg(args, char *)));
	else if (input == '%')
		return (ft_putchar(37));
	else if (input == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (input == 'p')
		return (ft_putpointer(va_arg(args, unsigned long)));
	else if (input == 'd' || input == 'i')
		return (ft_putnumber(va_arg(args, int)));
	else if (input == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (input == 'x' || input == 'X')
	{
		if (input == 'x')
			return (ft_puthexa(va_arg(args, unsigned int), 'x'));
		else
			return (ft_puthexa(va_arg(args, unsigned int), 'X'));
	}
	else
		return (0);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		e;
	va_list	args;

	i = -1;
	e = 0;
	va_start(args, input);
	while (input[++i] != '\0')
	{
		if (input[i] == '%')
		{
			if (input[++i] == '\0')
				break ;
			else if (!ft_strchr("cspdiuxX%", input[i]))
				e += ft_putchar(input[i]);
			else
				e += ft_printf_flags(input[i], args);
		}
		else
			e += ft_putchar(input[i]);
		if (e < 0)
			return (-1);
	}
	va_end(args);
	return (e);
}
