
#include "cube3d.h"

void	free_static_char_buff(int fd)
{
	char	*s;

	if (fd == -1)
		return ;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
}

void	ft_free_double(char	**double_arr)
{
	int	i;

	i = 0;
	if (!double_arr)
		return ;
	while (double_arr && double_arr[i])
	{
		free(double_arr[i]);
		i++;
	}
	if (double_arr)
		free(double_arr);
}

void	ft_main_free(t_main *main)
{
	// main = NULL;
	if (!main)
		return ;
	if (main->map)
		ft_free_double(main->map);
	if (main->player_pos)
		free(main->player_pos);
}
