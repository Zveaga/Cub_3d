/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:41:56 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/03/27 18:14:58 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_white_spaces(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] < '0' || str[i] > '9'))
	{
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			if (str[i] == '-')
				sign = -1;
		}
		else if ((str[i] > 32) || ft_white_spaces(str[i]))
			break ;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - 48;
		i++;
	}
	return (number * sign);
}
