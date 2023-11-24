/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:34:20 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/28 11:59:36 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;
	size_t			i;

	i = 0;
	s1_copy = (unsigned char *) s1;
	s2_copy = (unsigned char *) s2;
	while (i < n && n > 0)
	{
		if (s1_copy[i] == s2_copy[i])
			i++;
		else
			return (s1_copy[i] - s2_copy[i]);
	}
	return (0);
}
