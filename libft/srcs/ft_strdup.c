/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 13:59:59 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/23 17:02:22 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_s1;
	size_t	len;

	len = ft_strlen(s1) + 1;
	new_s1 = (char *) malloc(len);
	if (!new_s1)
		return (NULL);
	while (*s1 != '\0')
		*new_s1++ = *s1++;
	*new_s1 = '\0';
	return (new_s1 - len + 1);
}
