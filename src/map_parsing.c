/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parsing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/20 18:46:34 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/27 12:18:58 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// int	check_if_input_are_valid(int fd_map)
// {
// 	int		found_pos;
// 	int		i;
// 	char	*s;

// 	i = 0;
// 	found_pos = 0;
// 	s = get_next_line(fd_map);
// 	while (s)
// 	{
// 		i = 0;
// 		while (s && s[i] && s[i] != '\n')
// 		{
// 			if (s[i] == 'W' || s[i] == 'N' || s[i] == 'S' || s[i] == 'E')
// 			{
// 				found_pos++;
// 				break ;
// 			}
// 			i++;
// 		}
// 		if (s)
// 			free(s);
// 		s = get_next_line(fd_map);
// 	}
// 	if (found_pos == 0 || found_pos > 1)
// 		return (1);
// 	return (0);
// }

// int	*find_player_start(char **map, int x, int y)
// {
// 	char	*s;
// 	int		found_pos;
// 	int		*cordinate;
// 	int		i;

// 	found_pos = 0;
// 	cordinate = malloc(2 * sizeof(int));
// 	if (!cordinate)
// 		return (NULL);
// 	cordinate[y] = 0;
// 	s = get_next_line(fd);
// 	while (s)
// 	{
// 		cordinate[x] = 0;
// 		printf("x: %d, y: %d\n", cordinate[x], cordinate[y]);
// 		i = 0;
// 		while (s && s[i] && s[i] != '\n')
// 		{
// 			if (s[i] == 'W' || s[i] == 'N' || s[i] == 'S' || s[i] == 'E')
// 			{
// 				found_pos++;
// 				break ;
// 			}
// 			cordinate[x] += 1;
// 			i++;
// 		}
// 		if (found_pos == 1)
// 			break ;
// 		cordinate[y] += 1;
// 		if (s)
// 			free(s);
// 		s = get_next_line(fd);
// 	}
// 	return (cordinate);
// }

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

int	create_map(t_main *main)
{
	int		fd;
	char	*s;
	int		i;
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
	s = get_next_line(fd);
	if (!s)
		return (ft_free_double(main->map), close(fd), 1);
	i = 0;
	while (s)
	{
		main->map[i] = ft_strdup(s);
		free(s);
		if (!main->map[i])
			return (close(fd), ft_free_double(main->map), 1);
		i++;
		s = get_next_line(fd);
		if (!s)
		{
			free(s);
			break ;
		}
	}
	close(fd);
	main->map[i] = NULL;
	return (0);
}

int	ft_map_checking(char *map_name, t_main *main)
{
	main->map_name = map_name; // check_map_name
	if (!main->map_name)
		return (1);
	if (create_map(main))
		return (1);
	int i = 0;
	while (main->map[i])
		printf("%s", main->map[i++]);
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


