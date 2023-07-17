/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:18:02 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/17 11:03:23 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_get_map(t_game *game)
{
	size_t	i;
	char	*line;
	char	*trim;

	i = 0;
	game->map.fd = open(game->map.file_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(game->map.fd);
		if (!line)
			break ;
		trim = ft_strtrim((const char *)line, "\n");
		if (!trim)
			return (free(line), ft_free_struct(game, 2, 6));
		game->map.full_map[i] = ft_strdup((const char *)trim);
		if (!game->map.full_map[i])
			return (ft_free_struct(game, 2, 6), exit(1));
		free(trim);
		free(line);
		i++;
	}
	close(game->map.fd);
}

void	ft_get_map_setup(t_game *game)
{
	if (game->map.line < 3)
		return (ft_printf("trop peu de lignes, erreur\n"),
			ft_free_struct(game, 1, 2));
	game->map.full_map = malloc(sizeof(char *) * (game->map.line + 1));
	if (!game->map.full_map)
		return (ft_free_struct(game, 1, 6));
	game->map.full_map[game->map.line] = NULL;
	ft_get_map(game);
}
