/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freeing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 16:27:29 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/28 17:44:05 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_free_double(char	**double_arr)
{
	int	i;

	i = 0;
	if (!double_arr)
		return ;
	while (double_arr && double_arr[i])
	{
		free(double_arr[i]);
		i++;
	}
	if (double_arr)
		free(double_arr);
}

void	ft_main_free(t_main *main)
{
	// main = NULL;
	if (main && main->map)
		ft_free_double(main->map);
	if (main->player_pos)
		free(main->player_pos);
}
