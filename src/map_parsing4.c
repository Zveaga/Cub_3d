/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parsing4.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 16:10:44 by ibehluli      #+#    #+#                 */
/*   Updated: 2024/01/25 15:35:56 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_all_number(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map_name(char	*map_name)
{
	int	fd;

	fd = open(map_name, O_RDWR, 0644);
	if (fd == -1)
		return (close(fd), 1);
	close(fd);
	if (!ft_strncmp(&map_name[ft_strlen(map_name) - 4], ".cub", 4))
		return (0);
	return (1);
}

int	ft_map_checking(char *map_name, t_main *main)
{
	main->map_name = map_name;
	if (!main->map_name || ft_check_map_name(map_name))
		return (1);
	if (check_credentials(main))
		return (1);
	if (create_map(main))
		return (1);
	if (find_player_start(main))
		return (1);
	if (flood_fill(main, main->player_pos[0], main->player_pos[1], '0') == 1)
		return (1);
	return (0);
}
