/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 09:46:49 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/27 14:09:25 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*update_reserve(char *reserve)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	while (reserve[i] != '\n' && reserve[i])
		i++;
	if (reserve[i] == '\n')
		i++;
	if (reserve[i] == '\0')
		return (free(reserve), NULL);
	dup = malloc(sizeof(char) * (ft_strlen(reserve) - i + 1));
	if (dup == NULL)
	{
		free(reserve);
		reserve = NULL;
		return (NULL);
	}
	j = 0;
	while (reserve[i])
		dup[j++] = reserve[i++];
	dup[j] = '\0';
	return (free(reserve), dup);
}

static char	*save_line(char *reserve)
{
	int		i;
	char	*dup;
	int		flag;

	i = 0;
	while (reserve[i] != '\n' && reserve[i])
		i++;
	if (reserve[i] == '\n')
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	i = 0;
	flag = 0;
	if (dup == NULL)
		return (NULL);
	while (reserve && reserve[i] && (flag == 0))
	{
		dup[i] = reserve[i];
		if (reserve[i] == '\n')
			flag = 1;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	*ft_strjoin1(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*reserve;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	reserve = malloc((len + 1) * sizeof(char));
	if (!reserve)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		reserve[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		reserve[i++] = s2[j++];
	free(s1);
	reserve[i] = '\0';
	return (reserve);
}

static char	*read_and_reserve(char *reserve, int fd)
{	
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(reserve), NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(reserve), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		reserve = ft_strjoin1(reserve, buffer);
		if (reserve == NULL || ft_strchr(reserve, '\n') != 0)
			break ;
	}
	return (free(buffer), reserve);
}

char	*get_next_line(int fd)
{
	static char		*reserve;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reserve = read_and_reserve(reserve, fd);
	if (!reserve)
		return (NULL);
	line = save_line(reserve);
	if (!line)
	{
		if (reserve)
		{
			free(reserve);
			reserve = NULL;
		}
		return (NULL);
	}
	reserve = update_reserve(reserve);
	return (line);
}
