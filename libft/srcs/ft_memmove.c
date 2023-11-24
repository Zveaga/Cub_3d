/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 12:06:12 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/28 13:40:58 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*new_dest;
	const char	*new_src;

	new_dest = dst;
	new_src = (void *) src;
	if (dst == src)
		return (dst);
	else if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			len--;
			new_dest[len] = new_src[len];
		}
	}
	return (dst);
}
