
#include "cube3d.h"

int	ft_check_map_name(char	*map_name)
{
	if (!ft_strncmp(&map_name[ft_strlen(map_name) - 4], ".cub", 4))
		return (0);
	return (1);
}

int	ft_all_number(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	path_check(char	*s)
{
	int		fd;
	char	*s1;

	if (!s)
		return (0);
	s1 = ft_strtrim(s, " 	\n");
	if (!s1)
		return (1);
	fd = open(s1, O_RDONLY, 0644);
	if (fd == -1)
		return (free(s1), 1);
	free(s1);
	close(fd);
	return (0);
}

int	color_check(char *s)
{
	int		i;
	char	**split_color_value;
	char	*s1;

	i = 1;
	if (!s)
		return (1);
	s1 = ft_strtrim(s + i, " 	\n");
	if (!s1)
		return (1);
	split_color_value = ft_split(s1, ',');
	if (!split_color_value)
		return (free(s1), 1);
	free(s1);
	i = 0;
	while(split_color_value && split_color_value[i])
	{
		if (!ft_all_number(split_color_value[i])
			|| ft_atoi(split_color_value[i]) < 0
			|| ft_atoi(split_color_value[i]) > 255)
			return (ft_free_double(split_color_value), 1);
		i++;
	}
	// i = 0;
	// while (split_color_value[i])
	// {
	// 	printf("i: %d, %s\n", i, split_color_value[i]);
	// 	i++;
	// }
	ft_free_double(split_color_value);
	return (0);
}

int	check_more_precise(char	*s)
{
	if (s && (!ft_strncmp(s, "F", 1) || !ft_strncmp(s, "C", 1)))
	{
		if (color_check(s + 1))
			return (1);
	}
	else
	{
		if (path_check(s + 2))
			return (1);
	}
	return (0);
}

int	check_credentials_value(char *s)
{
	int	i;
	int	flag;
	
	i = 0;
	flag = 0;
	while(s && s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		else
			break;
    }
	if (!ft_strnstr(s + i, "NO", 2) && !ft_strnstr(s + i, "SO", 2)
		&& !ft_strnstr(s + i, "WE", 2) && !ft_strnstr(s + i, "EA", 2)
		&& !ft_strnstr(s + i, "F", 1) && !ft_strnstr(s + i, "C", 1))
		flag++;
	if (flag == 6)
	{
		if (check_more_precise(s + i))
			return (1);
	}
	return (0);
}

int	check_credentials(t_main *main)
{
	int		count;
	int		fd;
	char	*s;

	fd = open(main->map_name, O_RDONLY, 0644);
	if (fd == -1)
		return (1);
	count = 0;
	s = get_next_line(fd);
	if (!s)
		return (close(fd), 1);
	main->map_line = 0;
	while (s)
	{
		if (!check_credentials_value(s))
			count++;
		else
			return (free(s), close(fd), 1);
		main->map_line++;
		free(s);
		if (count == 6)
			break ;
		s = get_next_line(fd);
		if (!s)
			break ;
	}
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	// printf("%d\n", count);
	return (0);
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
	//printf("hehehe\n");
	main->player_pos = find_player_start(main);
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
