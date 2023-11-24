/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 14:42:26 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/21 14:07:40 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*s1, int c, size_t length)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *) s1;
	while (i < length)
	{
		dest[i] = c;
		i++;
	}
	return (s1);
}
