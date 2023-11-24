/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 19:44:49 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/16 12:15:55 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_int_length(int n)
{
	size_t	length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n != 0)
	{
		length++;
		n = n / 10;
	}
	return ((size_t) length);
}

char	*ft_itoa(int n)
{
	char	*string_with_numbers;
	size_t	length;
	long	var_long;

	var_long = (long) n;
	length = ft_int_length(n) + (n < 0);
	string_with_numbers = (char *) malloc(length + 1);
	if (!string_with_numbers)
		return (NULL);
	if (n == 0)
		string_with_numbers[0] = '0';
	string_with_numbers[length] = '\0';
	if (n < 0)
	{
		string_with_numbers[0] = '-';
		var_long *= -1;
	}
	while (length && var_long > 0)
	{
		string_with_numbers[--length] = (var_long % 10) + '0';
		var_long = var_long / 10;
	}
	return (string_with_numbers);
}
