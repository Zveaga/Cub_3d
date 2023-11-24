/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:22:03 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/19 17:45:42 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lista;

	if (*lst == NULL && new)
		*lst = new;
	else
	{
		lista = ft_lstlast(*(lst));
		lista ->next = new;
	}
}
