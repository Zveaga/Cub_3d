/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 10:36:06 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/03/09 16:54:26 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*something;

	something = (t_list *) malloc(sizeof (t_list));
	if (!something)
		return (NULL);
	something -> content = content;
	something -> next = NULL;
	return (something);
}
