/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 12:49:29 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/28 12:00:55 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*final_str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	final_str = (char *) malloc(len + 1);
	if (!final_str)
		return (NULL);
	while (s[i] != '\0')
	{
		final_str[i] = f(i, s[i]);
		i++;
	}
	final_str[i] = '\0';
	return (final_str);
}
