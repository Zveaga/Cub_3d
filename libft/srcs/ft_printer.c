/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 10:22:42 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/03/07 17:23:21 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstring(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		if (count < 0)
			return (-1);
		i++;
	}
	return (count);
}

int	ft_putpointer(size_t ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (count < 0)
		return (-1);
	count += ft_puthexa(ptr, 'x');
	return (count);
}

int	ft_putnumber(int number)
{
	int	count;

	count = 0;
	if (number == -2147483648)
		count += write(1, "-2147483648", 11);
	else if (number > 9)
	{
		count += ft_putnumber(number / 10);
		if (count < 0)
			return (-1);
		count += ft_putnumber(number % 10);
	}
	else if (number < 0)
	{
		count += ft_putchar('-');
		if (count < 0)
			return (-1);
		count += ft_putnumber(number * -1);
	}
	else
		count += ft_putchar(number + '0');
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_putunsigned(unsigned int number)
{
	int	count;
	int	unsigned_number_in_int;

	count = 0;
	if (number > 9)
		count += ft_putunsigned(number / 10);
	if (count < 0)
		return (-1);
	unsigned_number_in_int = number % 10 + '0';
	count += ft_putchar(unsigned_number_in_int);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_puthexa(size_t exa, char c)
{
	int		count;
	char	*buffer;

	count = 0;
	if (c == 'X')
		buffer = "0123456789ABCDEF";
	else
		buffer = "0123456789abcdef";
	if (exa >= 16)
	{
		count += ft_puthexa(exa / 16, c);
		if (count < 0)
			return (-1);
		count += ft_puthexa(exa % 16, c);
		if (count < 0)
			return (-1);
	}
	else
		count += ft_putchar(buffer[exa % 16]);
	if (count < 0)
		return (-1);
	return (count);
}
