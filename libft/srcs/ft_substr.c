/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 16:55:55 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/28 12:21:05 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	amsize(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (!s || !ft_strlen(s) || !len || ft_strlen(s) < start)
		return (0);
	while (s[start + i] && len != i)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	sub = (char *) malloc((amsize(s, start, len) + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
	{
		sub[i] = 0;
		return (sub);
	}
	while (s[start + i] && len - i != 0)
	{
		sub[i] = s[start + i];
		i++;
	}
	if (!s[start + i] || len - i == 0)
		sub[i] = '\0';
	return (sub);
}
