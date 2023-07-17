/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:46:49 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/17 11:23:15 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_one(t_game *game)
{
	free(game->map.file_name);
}

static void	ft_free_two(t_game *game)
{
	free(game->map.full_map);
}

static void	ft_free_three(t_game *game)
{
	size_t	j;

	j = 0;
	while (game->map.full_map[j])
	{
		free(game->map.full_map[j]);
		j++;
	}
}

static void	ft_free_four(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.wall_img);
	mlx_destroy_image(game->mlx_ptr, game->img.floor_img);
	mlx_destroy_image(game->mlx_ptr, game->img.collect_img);
	mlx_destroy_image(game->mlx_ptr, game->img.char_img);
	mlx_destroy_image(game->mlx_ptr, game->img.cl_exit_img);
	mlx_destroy_image(game->mlx_ptr, game->img.op_exit_img);
	mlx_destroy_image(game->mlx_ptr, game->img.ennemy_img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

void	ft_free_struct(t_game *game, int error_code, int exit_value)
{
	while (error_code)
	{
		if (error_code == 1)
			ft_free_one(game);
		if (error_code == 2)
			ft_free_two(game);
		if (error_code == 3)
			ft_free_three(game);
		if (error_code == 4)
			ft_free_four(game);
		error_code--;
	}
	exit(exit_value);
}
