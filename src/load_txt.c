/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_txt.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:34:31 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/12/15 12:30:14 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	put_texture(t_main *main)
{
	mlx_texture_t	*temp;
	mlx_image_t		*image;

	temp = mlx_load_png("arm.png");
	if (!temp)
		return (1);
	image = mlx_texture_to_image(main->mlx, temp);
	if (mlx_resize_image(image, 450, 500) == false)
	{
		mlx_delete_texture(temp);
		return (1);
	}
	if (mlx_image_to_window(main->mlx, image, main->mlx->width / 2, main->mlx->height - image->height) == -1)
	{
		mlx_delete_texture(temp);
		return (1);
	}
	mlx_delete_texture(temp);
	return (0);
}