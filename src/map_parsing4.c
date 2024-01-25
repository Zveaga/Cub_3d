/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parsing4.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 16:10:44 by ibehluli      #+#    #+#                 */
/*   Updated: 2024/01/24 16:11:25 by ibehluli      ########   odam.nl         */
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