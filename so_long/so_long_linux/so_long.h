/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:35:05 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/17 12:28:15 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include "./includes/libft.h"
# include "./minilibx-linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_dup_map
{
	char	**dupl_map;
	int		c_count;
	int		e_count;
}			t_dup_map;

typedef struct s_map
{
	char	**full_map;
	char	*file_name;
	int		fd;
	size_t	row;
	size_t	line;
	int		p_count;
	int		c_count;
	int		e_count;
}		t_map;

typedef struct s_img
{
	int			width;
	int			height;
	int			win_width;
	int			win_height;
	const char	*path;
	char		*character;
	char		*wall;
	char		*floor;
	char		*collectible;
	char		*exit_closed;
	char		*exit_open;
	char		*ennemy;
	void		*char_img;
	void		*wall_img;
	void		*floor_img;
	void		*collect_img;
	void		*cl_exit_img;
	void		*op_exit_img;
	void		*ennemy_img;
}	t_img;

typedef struct s_game
{
	t_map		map;
	t_img		img;
	t_dup_map	dup_map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			picked_c;
	int			p_pos[2];
	int			mov_count;
}	t_game;

// utils
void	ft_print_map(char **map);
size_t	ft_file_linecount(int fd);
int		ft_str_same_char_str(const char *str, int c);
void	ft_find_p_pos(t_game *game);

// free
void	ft_free_struct(t_game *game, int error_code, int exit_value);

// arg_parsing
int		ft_parse_arg(const char *str);

// get_map_from_file
void	ft_get_map_setup(t_game *game);

//map_checker
int		ft_check_map(t_game *game);
int		ft_map_checker_check(t_map *checker);

//is_map_solvable
int		ft_is_map_solvable(t_game *game);

//set_struct
void	ft_map_checker_initialize(t_game *game);
void	ft_set_img(t_game *game);
void	ft_update_char(t_game *game, int direction);

//struct_checker
int		struct_check(t_game *game);

//render_next
int		ft_render_next_frame(t_game *game);
void	ft_e_case(t_game *game);
void	ft_exit(t_game *game);

//key_hook
int		ft_key_hook(int keycode, t_game *game);

//render
void	ft_main_render(t_game *game);
void	ft_print_mov(t_game *game);
void	ft_game_win(t_game *game);
int		ft_game_over(t_game *game);
void	ft_open_door(t_game *game);

#endif