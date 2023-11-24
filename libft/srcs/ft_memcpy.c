/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 17:32:03 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/21 20:29:09 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*new_dest;
	char	*new_src;
	size_t	i;

	i = 0;
	new_dest = (char *) dest;
	new_src = (char *) src;
	if (!dest && !src)
		return (NULL);
	if (n > 0)
	{
		while (i < n)
		{
			new_dest[i] = new_src[i];
			i++;
		}
	}
	return (dest);
}
