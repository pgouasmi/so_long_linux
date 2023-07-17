/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:02:35 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/17 12:12:53 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_win(t_game *game)
{
	ft_printf("Victory !\n");
	ft_free_struct(game, 4, 0);
}

int	ft_game_over(t_game *game)
{
	game->mov_count++;
	ft_printf("Game Over !\n");
	ft_free_struct(game, 4, 0);
	return (0);
}

void	ft_open_door(t_game *game)
{
	int	width;
	int	height;

	mlx_destroy_image(game->mlx_ptr, game->img.cl_exit_img);
	game->img.cl_exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.exit_open, &width, &height);
}

void	ft_print_mov(t_game *game)
{
	char	*to_display;
	char	*line;

	line = ft_itoa(game->mov_count);
	if (!line)
		return (ft_free_struct(game, 4, 13));
	to_display = ft_strjoin("Movements : ",
			(const char *)line);
	if (!to_display)
	{
		if (line)
			free(line);
		return (ft_free_struct(game, 4, 11));
	}
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		50, game->map.line * 64 + 20,
		165115616, to_display);
	free(line);
	free(to_display);
}

void	ft_main_render(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->img.win_width,
			game->img.win_height, "Paint Adventures");
	if (!game->win_ptr)
		return (ft_free_struct(game, 4, 10));
	game->mov_count = 0;
	mlx_loop_hook(game->mlx_ptr, &ft_render_next_frame, game);
	mlx_hook(game->win_ptr, 17, 1L << 0, &ft_game_over, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, &ft_key_hook, game);
	mlx_loop(game->mlx_ptr);
}
