/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parsing1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 14:57:16 by ibehluli      #+#    #+#                 */
/*   Updated: 2024/01/25 15:22:23 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	path_check(t_main *main, char	*s, char face)
{
	char			*s1;
	mlx_texture_t	*temp;

	if (!main)
		return (1);
	if (!s)
		return (0);
	s1 = ft_strtrim(s, " 	\n");
	if (!s1)
		return (free(s1), 1);
	temp = mlx_load_png(s1);
	if (!temp)
		return (free(s1), 1);
	mlx_delete_texture(temp);
	if (face == 'N' && !main->north_texture)
		main->north_texture = s1;
	else if (face == 'S' && !main->south_texture)
		main->south_texture = s1;
	else if (face == 'W' && !main->west_texture)
		main->west_texture = s1;
	else if (face == 'E' && !main->east_texture)
		main->east_texture = s1;
	else
		return (free(s1), 1);
	return (0);
}

void	assign_color(t_main *main, char **spl_col, char f_or_c)
{
	if (!spl_col || !spl_col[0] || !spl_col[1] || !spl_col[2])
		return ;
	if (f_or_c == 'C')
	{
		main->ceiling_c = (int *) malloc(sizeof(int) * 3);
		if (!main->ceiling_c)
			return ;
		main->ceiling_c[0] = ft_atoi(spl_col[0]);
		main->ceiling_c[1] = ft_atoi(spl_col[1]);
		main->ceiling_c[2] = ft_atoi(spl_col[2]);
	}
	else
	{
		main->floor_c = (int *) malloc(sizeof(int) * 3);
		if (!main->floor_c)
			return ;
		main->floor_c[0] = ft_atoi(spl_col[0]);
		main->floor_c[1] = ft_atoi(spl_col[1]);
		main->floor_c[2] = ft_atoi(spl_col[2]);
	}
}

int	check_commas(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int	open_file(t_main *main, int *fd, int *count, char **s)
{
	*count = 0;
	*fd = open(main->map_name, O_RDONLY, 0644);
	*s = get_next_line(*fd);
	if (!(*s))
		return (close(*fd), 1);
	main->map_line = 0;
	return (0);
}

int	check_credentials(t_main *main)
{
	int		count;
	int		fd;
	char	*s;

	if (open_file(main, &fd, &count, &s) == 1)
		return (1);
	while (s)
	{
		if (!ft_isspace(s))
		{
			if (!check_credentials_value(main, s))
				count++;
			else
				return (free(s), free_static_char_buff(fd), 1);
		}
		main->map_line++;
		free(s);
		if (count == 6)
			break ;
		s = get_next_line(fd);
		if (!s)
			break ;
	}
	return (0);
}
