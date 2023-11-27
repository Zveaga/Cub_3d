/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parsing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/20 18:46:34 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/27 16:24:22 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_if_input_are_valid(char **map)
{
	int		found_pos;
	int		x;
	int		y;

	y = 0;
	found_pos = 0;
	if (!map)
		return (1);
	while (map[y])
	{
		x = 0;
		while (map && map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == 'W' || map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E')
				found_pos++;
			if (map[y][x] != 'W' && map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] != 'E' && map[y][x] != ' ' && map[y][x] != '0' && map[y][x] != '1')
				return (1);
			x++;
		}
		y++;

	}
	if (found_pos == 0 || found_pos > 1)
		return (1);
	return (0);
}

int	*find_player_start(t_main *main)
{
	int		found_pos;
	int		*cordinate;
	int		x;
	int		y;

	found_pos = 0;
	y = 0;
	cordinate = malloc(2 * sizeof(int));
	if (!cordinate)
		return (NULL);
	while (main->map && main->map[y])
	{
		x = 0;
		while (main->map[y][x] && main->map[y][x] != '\n')
		{
			if (main->map[y][x] == 'W' || main->map[y][x] == 'N' || main->map[y][x] == 'S' || main->map[y][x] == 'E')
			{
				found_pos++;
				break ;
			}
			x++;
		}
		if (found_pos == 1)
			break ;
		y++;
	}
	cordinate[y] = y;
	cordinate[x] = x;
	printf("x: %d, y: %d\n", cordinate[y], cordinate[x]);
	return (cordinate);
}

int	map_length(t_main *main)
{
	int		count;
	int		fd;
	char	*s;

	fd = open(main->map_name, O_RDONLY, 0644);
	if (fd == -1)
		return (0);
	count = 0;
	s = get_next_line(fd);
	if (!s)
		return (close(fd), 0);
	while (s)
	{
		count++;
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

	i = 0;
	if (fd == -1)
		return (1);
	s = get_next_line(fd);
	if (!s)
		return (ft_free_double(main->map), close(fd), 1);
	while (s)
	{
		main->map[i] = ft_strdup(s);
		if (!main->map[i])
			return (close(fd), ft_free_double(main->map), 1);
		i++;
		free(s);
		s = get_next_line(fd);
		if (!s)
		{
			free(s);
			break ;
		}
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

int	ft_check_map_name(char	*map_name)
{
	if (!ft_strncmp(&map_name[ft_strlen(map_name) - 4], ".cub", 4))
		return (0);
	return (1);
}

int	ft_map_checking(char *map_name, t_main *main)
{
	main->map_name = map_name;
	if (!main->map_name || ft_check_map_name(map_name))
		return (1);
	if (create_map(main))
		return (1);
	int i = 0;
	while (main->map && main->map[i])
		printf("%s\n", main->map[i++]);
	main->player_pos = find_player_start(main);
	return (0);
}

int ft_map_parsing(int argc, char **argv, t_main *main)
{

	if (argc < 2)
		return (ft_putstr_fd("Map not inserted\n", 2), 1);
	if (ft_map_checking(argv[1], main) == 1)
		return (ft_putstr_fd("Map Error\n", 2), 1);
	return (0);
}


