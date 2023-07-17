/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:07:43 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/17 12:27:53 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game)
{
	if (game->map.full_map[game->p_pos[0] - 1][game->p_pos[1]] == '1')
		return ;
	ft_update_char(game, 1);
	if (game->map.full_map[game->p_pos[0] - 1][game->p_pos[1]] == 'C')
	{
		game->picked_c++;
		if (game->picked_c == game->map.c_count)
			ft_open_door(game);
	}
	if (game->map.full_map[game->p_pos[0] - 1][game->p_pos[1]] == 'E')
	{
		ft_e_case(game);
		return ;
	}
	if (game->map.full_map[game->p_pos[0] - 1][game->p_pos[1]] == 'X')
	{
		game->mov_count++;
		ft_game_over(game);
	}
	game->mov_count++;
	game->map.full_map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->map.full_map[game->p_pos[0] - 1][game->p_pos[1]] = 'P';
	game->p_pos[0]--;
}

static void	move_down(t_game *game)
{
	if (game->map.full_map[game->p_pos[0] + 1][game->p_pos[1]] == '1')
		return ;
	ft_update_char(game, 2);
	if (game->map.full_map[game->p_pos[0] + 1][game->p_pos[1]] == 'C')
	{
		game->picked_c++;
		if (game->picked_c == game->map.c_count)
			ft_open_door(game);
	}
	if (game->map.full_map[game->p_pos[0] + 1][game->p_pos[1]] == 'E')
	{
		ft_e_case(game);
		return ;
	}
	if (game->map.full_map[game->p_pos[0] + 1][game->p_pos[1]] == 'X')
	{
		game->mov_count++;
		ft_game_over(game);
	}
	game->mov_count++;
	game->map.full_map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->map.full_map[game->p_pos[0] + 1][game->p_pos[1]] = 'P';
	game->p_pos[0]++;
}

static void	move_left(t_game *game)
{
	if (game->map.full_map[game->p_pos[0]][game->p_pos[1] - 1] == '1')
		return ;
	ft_update_char(game, 3);
	if (game->map.full_map[game->p_pos[0]][game->p_pos[1] - 1] == 'C')
	{
		game->picked_c++;
		if (game->picked_c == game->map.c_count)
			ft_open_door(game);
	}
	if (game->map.full_map[game->p_pos[0]][game->p_pos[1] - 1] == 'E')
	{
		ft_e_case(game);
		return ;
	}
	if (game->map.full_map[game->p_pos[0]][game->p_pos[1] - 1] == 'X')
	{
		game->mov_count++;
		ft_game_over(game);
	}
	game->mov_count++;
	game->map.full_map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->map.full_map[game->p_pos[0]][game->p_pos[1] - 1] = 'P';
	game->p_pos[1]--;
}

static void	move_right(t_game *game)
{
	if (game->map.full_map[game->p_pos[0]][game->p_pos[1] + 1] == '1')
		return ;
	ft_update_char(game, 4);
	if (game->map.full_map[game->p_pos[0]][game->p_pos[1] + 1] == 'C')
	{
		game->picked_c++;
		if (game->picked_c == game->map.c_count)
			ft_open_door(game);
	}
	if (game->map.full_map[game->p_pos[0]][game->p_pos[1] + 1] == 'E')
	{
		ft_e_case(game);
		return ;
	}
	if (game->map.full_map[game->p_pos[0]][game->p_pos[1] + 1] == 'X')
	{
		game->mov_count++;
		ft_game_over(game);
	}
	game->mov_count++;
	game->map.full_map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->map.full_map[game->p_pos[0]][game->p_pos[1] + 1] = 'P';
	game->p_pos[1]++;
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		ft_exit(game);
		return (12);
	}
	else
	{
		if (keycode == 119)
			move_up(game);
		if (keycode == 97)
			move_left(game);
		if (keycode == 115)
			move_down(game);
		if (keycode == 100)
			move_right(game);
	}
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	ft_print_mov(game);
	return (0);
}
