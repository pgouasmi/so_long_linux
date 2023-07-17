/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_solvable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:20:50 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/17 12:04:56 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_dup(char **arr)
{
	size_t	j;

	if (!arr)
		return ;
	j = 0;
	while (arr[j])
	{
		free(arr[j]);
		j++;
	}
	free (arr);
}

static void	ft_dup_map(t_game *game)
{
	size_t	i;

	game->dup_map.dupl_map = malloc(sizeof(char *) * (game->map.line + 1));
	if (!game->dup_map.dupl_map)
		return ;
	i = 0;
	game->dup_map.dupl_map[game->map.line] = NULL;
	i = 0;
	while (i < game->map.line)
	{
		game->dup_map.dupl_map[i] = ft_strdup(game->map.full_map[i]);
		if (!game->dup_map.dupl_map[i])
			return (ft_free_dup(game->dup_map.dupl_map));
		i++;
	}
}

static void	ft_solve_map(t_dup_map *map_dup, int j, int i)
{
	if (map_dup->dupl_map[j][i] == 'W')
		return ;
	if (map_dup->dupl_map[j][i] == '0' || map_dup->dupl_map[j][i] == 'C'
	|| map_dup->dupl_map[j][i] == 'P' || map_dup->dupl_map[j][i] == 'E')
	{
		if (map_dup->dupl_map[j][i] == 'C')
			map_dup->c_count++;
		if (map_dup->dupl_map[j][i] == 'E')
			map_dup->e_count = 1;
		map_dup->dupl_map[j][i] = 'W';
		ft_solve_map(map_dup, j - 1, i);
		ft_solve_map(map_dup, j + 1, i);
		ft_solve_map(map_dup, j, i + 1);
		ft_solve_map(map_dup, j, i - 1);
	}
	return ;
}

static int	ft_compare_items(t_map map, t_dup_map dup)
{
	return ((map.c_count - dup.c_count) + (map.e_count - dup.e_count));
}

int	ft_is_map_solvable(t_game *game)
{
	ft_find_p_pos(game);
	ft_dup_map(game);
	if (!game->dup_map.dupl_map)
		return (ft_free_dup(game->dup_map.dupl_map), 1);
	game->dup_map.c_count = 0;
	game->dup_map.e_count = 0;
	ft_solve_map(&game->dup_map, game->p_pos[0],
		game->p_pos[1]);
	if (ft_compare_items(game->map, game->dup_map))
		return (ft_printf("Error\nThe map is not solvable\n"),
			ft_free_dup(game->dup_map.dupl_map), 1);
	return (ft_free_dup(game->dup_map.dupl_map), 0);
}
