/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 12:17:34 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/29 11:38:21 by coxer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	t_main	*main;
	
	main = param;
	for (int i = 0; i < (int) main->image->width; ++i)
	{
		for (int y = 0; y < (int) main->image->height; ++y)
		{
			int color = ft_pixel(
				255, // R
				255, // G
				255, // B
				255  // A
			);
			mlx_put_pixel(main->image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	t_main	*main;

	main = param;

	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(main->mlx);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_W))
		main->image->instances[0].y -= 5;
	if (mlx_is_key_down(main->mlx, MLX_KEY_S))
		main->image->instances[0].y += 5;
	if (mlx_is_key_down(main->mlx, MLX_KEY_A))
		main->image->instances[0].x -= 5;
	if (mlx_is_key_down(main->mlx, MLX_KEY_D))
		main->image->instances[0].x += 5;
}

int main(int argc, char **argv)
{
	t_main	main;

	if (ft_map_parsing(argc, argv, &main))
		return (ft_main_free(&main), EXIT_FAILURE);
	int i = 0;
	while (main.map && main.map[i])
		printf("%s\n", main.map[i++]);
	if (!(main.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(main.image = mlx_new_image(main.mlx, 128, 128)))
	{
		mlx_close_window(main.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(main.mlx, main.image, 100, 100) == -1)
	{
		mlx_close_window(main.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_loop_hook(main.mlx, ft_randomize, &main);
	mlx_loop_hook(main.mlx, ft_hook, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	ft_main_free(&main);
	return (EXIT_SUCCESS);
}

