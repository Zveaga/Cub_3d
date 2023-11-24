/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:10:47 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/03/07 16:59:20 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substring_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**ft_free_memory(char **failed_string, size_t index)
{
	while (index--)
		free(failed_string[index]);
	free(failed_string);
	return (NULL);
}

static size_t	ft_word_count(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**final_array;
	char	*temp_string;
	size_t	e;
	size_t	i;

	i = -1;
	e = 0;
	if (!s)
		return (NULL);
	final_array = ft_calloc((ft_substring_count(s, c) + 1), sizeof (char *));
	if (!final_array)
		return (NULL);
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			temp_string = ft_substr(s, i, ft_word_count(s + i, c));
			if (!temp_string)
				return (ft_free_memory(final_array, e));
			final_array[e++] = temp_string;
			i += ft_strlen(temp_string) - 1;
		}
	}
	return (final_array);
}
