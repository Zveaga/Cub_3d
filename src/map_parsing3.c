/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parsing3.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 16:04:46 by ibehluli      #+#    #+#                 */
/*   Updated: 2024/01/25 15:35:31 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_range(char **split_color_value)
{
	int	i;

	i = 0;
	if (!split_color_value)
		return (1);
	while (split_color_value && split_color_value[i])
	{
		if (!ft_all_number(split_color_value[i])
			|| ft_atoi(split_color_value[i]) < 0
			|| ft_atoi(split_color_value[i]) > 255)
			return (ft_free_double(split_color_value), 1);
		i++;
	}
	return (0);
}

int	color_check(t_main *main, char *s, char f_or_c)
{
	int		i;
	char	**split_color_value;
	char	*s1;

	i = 1;
	if (!s || !main)
		return (1);
	if ((f_or_c == 'C' && main->ceiling_c) || (f_or_c == 'F' && main->floor_c))
		return (1);
	s1 = ft_strtrim(s + i, " \n");
	if (!s1)
		return (1);
	if (check_commas(s))
		return (free(s1), 1);
	split_color_value = ft_split(s1, ',');
	free(s1);
	if (check_range(split_color_value))
		return (1);
	assign_color(main, split_color_value, f_or_c);
	if (f_or_c == 'F' && !main->floor_c)
		return (ft_free_double(split_color_value), 1);
	if (f_or_c == 'C' && !main->ceiling_c)
		return (ft_free_double(split_color_value), 1);
	ft_free_double(split_color_value);
	return (0);
}

int	check_more_precise(t_main *main, char	*s)
{
	if (s && (!ft_strncmp(s, "F", 1) || !ft_strncmp(s, "C", 1)))
	{
		if (color_check(main, s + 1, s[0]))
			return (1);
	}
	else
	{
		if (path_check(main, s + 2, s[0]))
			return (1);
	}
	return (0);
}

int	check_texture_symbols(char *str, int i)
{
	if (ft_strncmp(&str[i], "NO ", 3) == 0)
		return (0);
	else if (ft_strncmp(&str[i], "SO ", 3) == 0)
		return (0);
	else if (ft_strncmp(&str[i], "WE ", 3) == 0)
		return (0);
	else if (ft_strncmp(&str[i], "EA ", 3) == 0)
		return (0);
	else if (ft_strncmp(&str[i], "F ", 2) == 0)
		return (0);
	else if (ft_strncmp(&str[i], "C ", 2) == 0)
		return (0);
	return (1);
}

int	check_credentials_value(t_main *main, char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!main || !s)
		return (1);
	while (s && s[i])
	{
		if (s[i] == ' ' || s[i] == '\n')
			i++;
		else
			break ;
	}
	if (check_texture_symbols(s, i) == 1)
		return (1);
	if (!ft_strnstr(s + i, "NO ", 3) || !ft_strnstr(s + i, "SO ", 3)
		|| !ft_strnstr(s + i, "WE ", 3) || !ft_strnstr(s + i, "EA ", 3)
		|| !ft_strnstr(s + i, "F ", 2) || !ft_strnstr(s + i, "C ", 2))
		flag++;
	if (flag == 1)
		if (check_more_precise(main, s + i))
			return (1);
	return (0);
}
