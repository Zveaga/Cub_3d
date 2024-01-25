/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parsing2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 14:54:38 by ibehluli      #+#    #+#                 */
/*   Updated: 2024/01/25 15:34:52 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	loop_to_fill_map(t_main *main, int fd, char	*s, int i)
{
	int		pos;

	pos = 0;
	while (s)
	{
		if (s && s[0] && ft_isspace(s))
			pos--;
		if (pos >= main->map_line)
		{
			main->map[i] = ft_strdup(s);
			if (!main->map[i])
				return (free(s), 1);
			i++;
		}
		pos++;
		free(s);
		s = get_next_line(fd);
		if (!s)
			break ;
	}
	return (i);
}

int	fill_map(t_main *main, int fd)
{
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	if (!s)
		return (1);
	i = loop_to_fill_map(main, fd, s, i);
	main->map[i] = NULL;
	return (0);
}

int	flood_fill_util(t_main *main, int x, int y)
{
	if (flood_fill(main, x + 1, y, '0'))
		return (1);
	else if (flood_fill(main, x - 1, y, '0'))
		return (1);
	else if (flood_fill(main, x, y + 1, '0'))
		return (1);
	else if (flood_fill(main, x, y - 1, '0'))
		return (1);
	else if (flood_fill(main, x + 1, y + 1, '0'))
		return (1);
	else if (flood_fill(main, x + 1, y - 1, '0'))
		return (1);
	else if (flood_fill(main, x - 1, y - 1, '0'))
		return (1);
	else if (flood_fill(main, x - 1, y + 1, '0'))
		return (1);
	else
		return (0);
}

int	flood_fill(t_main *main, int x, int y, char find)
{
	if (!main->player_pos || x < 0 || y < 0)
		return (1);
	if (!main || !main->map || !main->map[y] || !main->map[y][x])
		return (1);
	if (main->map[y][x] == '\n' || main->map[y][x] == ' ')
		return (1);
	if (main->map && (main->map[y][x] == find || main->map[y][x] == 'N'
		|| main->map[y][x] == 'S' || main->map[y][x] == 'W'
		|| main->map[y][x] == 'E'))
	{
		if (main->map[y][x] != 'N' && main->map[y][x] != 'S'
		&& main->map[y][x] != 'W' && main->map[y][x] != 'E')
			main->map[y][x] = 'A';
		if (flood_fill_util(main, x, y) == 1)
			return (1);
	}
	return (0);
}

int	ft_map_parsing(int argc, char **argv, t_main *main)
{
	if (argc < 2)
		return (ft_putstr_fd("Map not inserted\n", 2), 1);
	if (ft_map_checking(argv[1], main) == 1)
		return (ft_putstr_fd("Map Error\n", 2), 1);
	return (0);
}
