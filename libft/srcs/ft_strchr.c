/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:43:09 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/21 10:24:49 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	variable;

	i = 0;
	if (!s)
		return (NULL);
	variable = (unsigned char) c;
	if (variable)
	{
		while (s[i] != '\0')
		{
			if (s[i] == variable)
				return ((char *) s + i);
			i++;
		}
		return (NULL);
	}
	else
		return ((char *)s + ft_strlen(s));
}
