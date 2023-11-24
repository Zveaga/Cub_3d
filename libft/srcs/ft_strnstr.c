/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 16:21:34 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/28 12:02:27 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	e;

	i = 0;
	if (!*needle)
		return ((char *) haystack);
	while (haystack[i])
	{
		e = 0;
		while (i + e < len && e < ft_strlen(needle)
			&& i + e < ft_strlen(haystack) && haystack[i + e] == needle[e])
			e++;
		if (e == ft_strlen(needle))
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
