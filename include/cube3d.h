/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 12:06:07 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/29 12:22:17 by ibehluli      ########   odam.nl         */
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
	int			map_line;
}	t_main ;

// int	ft_check_map(char *argv);
int		ft_map_parsing(int argc, char **argv, t_main *main);
int		ft_check_map_name(char	*map_name);
int		ft_map_checking(char *map_name, t_main *main);
int		check_if_input_are_valid(char **map);
int		*find_player_start(t_main *main);
int		create_map(t_main *main);

// free
void	ft_free_double(char	**double_arr);
void	ft_main_free(t_main *main);
void	free_static_char_buff(int fd);

#endif