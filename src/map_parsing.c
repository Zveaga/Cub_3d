/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parsing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/20 18:46:34 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/30 13:37:46 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_if_input_are_valid(char **map)
{
	int		found_pos;
	int		x;
	int		y;

	y = -1;
	found_pos = 0;
	if (!map)
		return (1);
	while (map[++y])
	{
		x = -1;
		while (map && map[y][++x] && map[y][x] != '\n')
		{
			if (map[y][x] == 'W' || map[y][x] == 'N'
				|| map[y][x] == 'S' || map[y][x] == 'E')
				found_pos++;
			if (map[y][x] != 'W' && map[y][x] != 'N'
				&& map[y][x] != 'S' && map[y][x] != 'E'
				&& map[y][x] != ' ' && map[y][x] != '0' && map[y][x] != '1')
				return (1);
		}
	}
	if (found_pos == 0 || found_pos > 1)
		return (1);
	return (0);
}

int	*find_player_start(t_main *main)
{
	int		*cordinate;
	int		x;
	int		y;

	cordinate = malloc(2 * sizeof(int));
	if (!cordinate)
		return (NULL);
	y = 0;
	while (main->map && main->map[y])
	{
		x = 0;
		while (main->map[y][x] && main->map[y][x] != '\n')
		{
			if (main->map[y][x] == 'W' || main->map[y][x] == 'N'
				|| main->map[y][x] == 'S' || main->map[y][x] == 'E')
			{
				cordinate[x] = x;
				cordinate[y] = y;
				return (cordinate);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

int	map_length(t_main *main)
{
	int		count;
	int		fd;
	char	*s;
	int		pos;

	fd = open(main->map_name, O_RDONLY, 0644);
	pos = 0;
	if (fd == -1)
		return (0);
	count = 0;
	s = get_next_line(fd);
	if (!s)
		return (close(fd), 0);
	while (s)
	{
		if (pos >= main->map_line)
			count++;
		pos++;
		free(s);
		s = get_next_line(fd);
		if (!s)
			break ;
	}
	close(fd);
	return (count);
}

int	fill_map(t_main *main, int fd)
{
	int		i;
	char	*s;
	int		pos;

	i = 0;
	pos = 0;
	if (fd == -1)
		return (1);
	s = get_next_line(fd);
	if (!s)
		return (ft_free_double(main->map), close(fd), 1);
	while (s)
	{
		if (pos >= main->map_line)
		{
			main->map[i] = ft_strdup(s);
			if (!main->map[i])
				return (close(fd), ft_free_double(main->map), 1);
			i++;
		}
		pos++;
		free(s);
		s = get_next_line(fd);
		if (!s)
			break ;
	}
	main->map[i] = NULL;
	return (0);
}

int	create_map(t_main *main)
{
	int		fd;
	int		size;

	if (!main)
		return (1);
	size = map_length(main);
	if (size == 0)
		return (1);
	fd = open(main->map_name, O_RDONLY, 0644);
	if (fd == -1)
		return (1);
	main->map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!main->map)
		return (close (fd), 1);
	if (fill_map(main, fd))
		return (1);
	close(fd);
	if (check_if_input_are_valid(main->map))
		return (1);
	return (0);
}
