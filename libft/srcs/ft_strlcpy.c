/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:57:48 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/19 18:09:30 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	e;

	e = 0;
	if (dstsize != 0)
	{
		while (e < dstsize - 1 && src[e] != '\0')
		{
			dst[e] = src[e];
			e++;
		}
		dst[e] = '\0';
	}
	return (ft_strlen(src));
}
