/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:34:37 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/19 18:53:27 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	index;
	size_t	maximum_chars;

	len_dst = ft_strlen(dst);
	index = 0;
	maximum_chars = dstsize - len_dst - 1;
	if (dstsize > len_dst)
	{
		while (index < maximum_chars && src[index] != '\0')
		{
			dst[len_dst + index] = src[index];
			index++;
		}
		dst[len_dst + index] = '\0';
		return (len_dst + ft_strlen(src));
	}
	else
		return (ft_strlen(src) + dstsize);
}
