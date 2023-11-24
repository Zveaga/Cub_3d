/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 18:52:19 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/21 10:41:28 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	new_str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[e] != '\0')
	{
		new_str[i] = s2[e];
		e++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
