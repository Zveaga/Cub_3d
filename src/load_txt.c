/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_txt.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:34:31 by ibehluli      #+#    #+#                 */
/*   Updated: 2024/01/19 11:11:31 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// int	add_texture(t_main *main)
// {
// 	mlx_texture_t	*temp;
// 	// mlx_texture_t	*temp1;
// 	// mlx_texture_t	*temp2;
// 	// mlx_texture_t	*temp3;
// 	(void) main;

// 	temp = mlx_load_png("wallnorth.png");
// 	// temp1 = mlx_load_png("wallsouth.png");
// 	// temp2 = mlx_load_png("walleast.png");
// 	// temp3 = mlx_load_png("wallwest.png");
// 	printf("txt_texture: byte: %d, height: %d, pixel: %d, width: %d\n", temp->bytes_per_pixel, temp->height, temp->pixels[0], temp->width);
// 	return (0);
// }

// int	put_texture(t_main *main)
// {
// 	mlx_texture_t	*temp;
// 	mlx_image_t		*image;
// 	mlx_image_t		*pointing_at;

// 	temp = mlx_load_png("arm.png");
// 	if (!temp)
// 		return (1);
// 	image = mlx_texture_to_image(main->mlx, temp);
// 	if (mlx_resize_image(image, 450, 500) == false)
// 	{
// 		mlx_delete_texture(temp);
// 		return (1);
// 	}
// 	mlx_delete_texture(temp);
// 	temp = mlx_load_png("pointer.png");
// 	pointing_at = mlx_texture_to_image(main->mlx, temp);
// 	mlx_resize_image(pointing_at, 50, 50);
// 	mlx_image_to_window(main->mlx, pointing_at, (main->mlx->width / 2) - pointing_at->width / 2, ( main->mlx->height / 2) - pointing_at->height / 2);
// 	if (mlx_image_to_window(main->mlx, image, main->mlx->width / 2, main->mlx->height - image->height) == -1)
// 	{
// 		mlx_delete_texture(temp);
// 		return (1);
// 	}
// 	mlx_delete_texture(temp);
// 	return (0);
// }