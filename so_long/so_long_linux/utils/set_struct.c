/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:07:55 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/17 12:31:41 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_char(t_game *game, int direction)
{
	mlx_destroy_image(game->mlx_ptr, game->img.char_img);
	if (direction == 1)
		game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr,
				"./sprites/char_up.xpm", &game->img.width, &game->img.height);
	if (direction == 2)
		game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr,
				"./sprites/char_down.xpm", &game->img.width, &game->img.height);
	if (direction == 3)
		game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr,
				"./sprites/char_left.xpm", &game->img.width, &game->img.height);
	if (direction == 4)
		game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr,
				"./sprites/char_right.xpm", &game->img.width,
				&game->img.height);
	if (!(game->img.char_img))
		return (ft_free_struct(game, 4, 14));
}

void	ft_map_checker_initialize(t_game *game)
{
	game->map.c_count = 0;
	game->map.e_count = 0;
	game->map.p_count = 0;
	game->img.win_width = 64 * game->map.row;
	game->img.win_height = 64 * game->map.line + 35;
}

static void	ft_set_img_path(t_game *game)
{
	game->img.path = "./sprites/";
	game->img.character = "./sprites/char_up.xpm";
	game->img.wall = "./sprites/obstacle.xpm";
	game->img.floor = "./sprites/grass.xpm";
	game->img.collectible = "./sprites/collectible.xpm";
	game->img.exit_closed = "./sprites/closed_door.xpm";
	game->img.exit_open = "./sprites/open_door.xpm";
	game->img.ennemy = "./sprites/ennemy.xpm";
}

static void	ft_set_img_void(t_game *game)
{
	int	height;
	int	width;

	game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.character, &width, &height);
	game->img.wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.wall, &width, &height);
	game->img.floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.floor, &width, &height);
	game->img.collect_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.collectible, &width, &height);
	game->img.cl_exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.exit_closed, &width, &height);
	game->img.op_exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.exit_open, &width, &height);
	game->img.ennemy_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.ennemy, &width, &height);
}

void	ft_set_img(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_free_struct(game, 3, 8));
	game->picked_c = 0;
	ft_set_img_path(game);
	ft_set_img_void(game);
	if (struct_check(game))
		return (ft_free_struct(game, 3, 9));
}
