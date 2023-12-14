/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_txt.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:34:31 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/12/14 17:38:40 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	put_texture(t_main *main)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png(s1);
	if (!temp)
		return (free(s1), 1);
	mlx_texture_to_image();
	mlx_delete_texture(temp);
}