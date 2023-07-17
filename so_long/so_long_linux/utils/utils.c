/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:26:40 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/13 16:06:41 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_file_linecount(int fd)
{
	size_t	result;
	char	*line;

	result = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		result++;
	}
	close(fd);
	return (result);
}

void	ft_print_map(char **map)
{
	size_t	j;

	j = 0;
	while (map[j])
	{
		ft_printf("%s", map[j]);
		ft_printf("\n");
		j++;
	}
}

int	ft_str_same_char_str(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_find_p_pos(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	while (1)
	{
		if (ft_strchr((const char *)game->map.full_map[j], 'P'))
			break ;
		j++;
	}
	i = 0;
	while (game->map.full_map[j][i] != 'P')
		i++;
	game->p_pos[0] = j;
	game->p_pos[1] = i;
}
