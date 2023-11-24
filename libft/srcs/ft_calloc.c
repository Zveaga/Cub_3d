/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 13:19:08 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/17 19:12:09 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*space_with_null_values;

	space_with_null_values = (char *) malloc(count * size);
	if (!space_with_null_values)
		return (NULL);
	ft_bzero(space_with_null_values, count * size);
	return (space_with_null_values);
}
