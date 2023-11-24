/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:40:11 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/28 15:07:31 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *) s;
	if (n == 0)
		return ;
	else
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
}
