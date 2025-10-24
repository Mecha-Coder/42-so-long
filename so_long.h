/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 06:11:25 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 06:32:46 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//******************************************************
// LIBRARIES
//******************************************************
# include "mlx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

//******************************************************
// CONSTANT
//******************************************************

// Animation (Loop / frame)
# define LOOP 160

//{x, y} coordinate || height X width 
# define Y 1
# define X 0

//Bool logic
# define TRUE 1
# define FALSE 0

//Image array pointer
# define P_FRONT 0
# define P_BACK 1
# define P_LEFT 2
# define P_RIGHT 3
# define WALL 4
# define FLOOR 5
# define EXIT 6
# define O_EXIT 7
# define COLLECT 8
# define M1 9
# define M2 10
# define M3 11

//Image path & data
# define IMG_P_FRONT "./img/p_front.xpm"
# define IMG_P_BACK "./img/p_back.xpm"
# define IMG_P_LEFT "./img/p_left.xpm"
# define IMG_P_RIGHT "./img/p_right.xpm"
# define IMG_WALL "./img/wall.xpm"
# define IMG_FLOOR "./img/floor.xpm"
# define IMG_EXIT "./img/exit.xpm"
# define IMG_O_EXIT "./img/o_exit.xpm"
# define IMG_COLLECT "./img/collect.xpm"
# define IMG_M1 "./img/m1.xpm"
# define IMG_M2 "./img/m2.xpm"
# define IMG_M3 "./img/m3.xpm"
# define IMG_COUNT 12
# define IMG_SIZE 50

//Keyboard
#define UP     65362
#define DOWN   65364
#define LEFT   65361
#define RIGHT  65363
#define W      119
#define S      115
#define A      97
#define D      100
#define ESC    65307


// Error Message
# define MSG_ERROR_1 "Error\nInvalid map: Contain forbidden character\n"
# define MSG_ERROR_2 "Error\nInvalid map: P, E, C count not per requirement\n"
# define MSG_ERROR_3 "Error\nIssue to download map"

//******************************************************
// INFO MANAGEMENT
//******************************************************

typedef struct s_info
{
	void	*mlx;
	void	*win;
	char	**map;
	int		size[2];
	int		grid[2];
	int		pos[2];
	void	*img[12];
	int		collect;
	int		step;
	char	*step_str;
	void	*anime_exit;
	void	*anime_player;
	void	*anime_monster;
	int		c;
	int		e;
}	t_info;

//******************************************************
// FUNCTION
//******************************************************

// Game
int		start_game(t_info *v);
int		update_frame(t_info *v);
int		handle_input(int key, t_info *v);
int		download_img(t_info *v);
int		close_window(t_info *v);
void	shutdown(t_info *v);

// Checks
int		check_input(int size, char **list);
int		download_map(t_info *x, char *file);
void	explore(char **map, int x, int y, t_info *v);
int		validate_map(t_info *x);

// Game Message
void	msg_step(char *s);
void	msg_win(void);
void	msg_lose(void);
void	msg_close(void);

// Utils
char	*get_str(int n);
int		get_len(char *s);
int		get_height(char **list);
void	flush_map(char **map);
void	*reset_memory(void *dst, int val, size_t n);
char	**dup_map(t_info *x, char **new_map, int loop, int i);
char	*ft_strrchr(const char *str, int c);
void	remove_lst_nonprintable_char(char *s);
void	assign_start(t_info *v, int i, int j);
void	print(char *s);
#endif
