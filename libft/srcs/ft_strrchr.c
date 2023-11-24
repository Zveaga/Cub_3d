/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:08:46 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/20 11:49:03 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len_s;
	unsigned char	variable;

	len_s = ft_strlen(s);
	variable = (unsigned char) c;
	if (variable == '\0')
		return ((char *) s + len_s);
	while (len_s > 0)
	{
		len_s--;
		if (s[len_s] == variable)
			return ((char *) s + len_s);
	}
	return (NULL);
}
