/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:34:27 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/17 11:26:25 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	struct_check(t_game *game)
{
	if (game->img.char_img == NULL)
		return (1);
	if (game->img.wall_img == NULL)
		return (1);
	if (game->img.floor_img == NULL)
		return (1);
	if (game->img.collect_img == NULL)
		return (1);
	if (game->img.cl_exit_img == NULL)
		return (1);
	if (game->img.op_exit_img == NULL)
		return (1);
	if (game->img.ennemy == NULL)
		return (1);
	return (0);
}
