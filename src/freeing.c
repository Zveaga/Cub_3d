
#include "cube3d.h"

void	free_static_char_buff(int fd)
{
	char	*s;

	if (fd == -1)
		return ;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
}

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

void	free_image_buffer(uint32_t **img_buf)
{
	int	i;

	i = 0;
	if (!img_buf)
		return ;
	while (i < HEIGHT)
	{
		free(img_buf[i]);
		i++;
	}
	free(img_buf);
}

void	free_pixel_grid(int32_t **pixel_grid, mlx_image_t *texture)
{
	uint32_t	i;

	if (!pixel_grid)
		return ;
	i = 0;
	while (i < texture->height)
	{
		free(pixel_grid[i]);
		i++;
	}
	free(pixel_grid);
}

void	free_pixel_grids(t_main *main)
{
	free_pixel_grid(main->north_tex_pixel_grid, main->north_texture_img);
	free_pixel_grid(main->south_tex_pixel_grid, main->south_texture_img);
	free_pixel_grid(main->west_tex_pixel_grid, main->west_texture_img);
	free_pixel_grid(main->east_tex_pixel_grid, main->east_texture_img);
}

void	ft_main_free(t_main *main)
{
	if (main->map)
		ft_free_double(main->map);
	if (main->player_pos)
		free(main->player_pos);
	if (main->ceiling_color)
		free(main->ceiling_color);
	if (main->floor_color)
		free(main->floor_color);
	if (main->north_texture)
		free(main->north_texture);
	if (main->south_texture)
		free(main->south_texture);
	if (main->west_texture)
		free(main->west_texture);
	if (main->east_texture)
		free(main->east_texture);
	if (main->image)
		mlx_delete_image(main->mlx, main->image);
	if (main->image_buffer)
		free_image_buffer(main->image_buffer);
	main->image_buffer = NULL;
	if (main->north_tex_pixel_grid)
		free_pixel_grids(main);
}
