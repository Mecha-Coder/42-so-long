/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:16:08 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 05:19:37 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
void *animation(t_info *v)
{
	static int i;
	
	i++;
	if (i < LOOP)
		return (v->img[M1]);
	else if (i < LOOP * 2)
		return (v->img[M2]);
	else if (i < LOOP * 3)
		return (v->img[M3]);
	else
		i = 0;
	return (v->img[M1]);
}
*/

void	print_map(t_info *v, int x, int y)
{
	int	a;
	int	b;

	while (++y < v->grid[Y])
	{
		x = -1;
		while (++x < v->grid[X])
		{
			a = x * IMG_SIZE;
			b = y * IMG_SIZE;
			if (v->map[y][x] == '1')
				mlx_put_image_to_window(v->mlx, v->win, v->img[WALL], a, b);
			else if (v->map[y][x] == '0')
				mlx_put_image_to_window(v->mlx, v->win, v->img[FLOOR], a, b);
			else if (v->map[y][x] == 'E')
				mlx_put_image_to_window(v->mlx, v->win, v->anime_exit, a, b);
			else if (v->map[y][x] == 'C')
				mlx_put_image_to_window(v->mlx, v->win, v->img[COLLECT], a, b);
			else if (v->map[y][x] == 'P')
				mlx_put_image_to_window(v->mlx, v->win, v->anime_player, a, b);
			else if (v->map[y][x] == 'M')
				mlx_put_image_to_window(v->mlx, v->win, v->anime_monster, a, b);
		}
	}
}

/*
void print_step(t_info *v)
{
	int s;
	int color;

	color = 0xffffff;
	s = IMG_SIZE; 
	mlx_string_put(v->mlx, v->win, s/20, s/20, color, "STEP: ");
	if (v->step_str)
		mlx_string_put(v->mlx, v->win, 55, s/20, color, v->step_str);
	else
		mlx_string_put(v->mlx, v->win, 55, s/20, color, "0");
}
*/

int	update_frame(t_info *v)
{
	print_map(v, -1, -1);
	return (0);
}
