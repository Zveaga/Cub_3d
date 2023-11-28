/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 13:59:59 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/28 12:21:28 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*am;

	i = 0;
	if (!s1)
		return (NULL);
	am = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!am)
		return (NULL);
	while (s1[i])
	{
		am[i] = s1[i];
		i++;
	}
	am[i] = '\0';
	return (am);
}
