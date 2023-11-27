/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 12:06:07 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/27 16:16:32 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_main
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		**map;
	char		*map_name;
	int			*player_pos;
}	t_main ;

// int	ft_check_map(char *argv);
int ft_map_parsing(int argc, char **argv, t_main *main);

// free
void	ft_free_double(char	**double_arr);
void	ft_main_free(t_main *main);

#endif