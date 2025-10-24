/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:11:46 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 06:22:56 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_step(t_info *v)
{
	if (v->step_str)
		free(v->step_str);
	v->step_str = get_str(++v->step);
	msg_step(v->step_str);
}

static void	move(t_info *v, int y, int x)
{
	if (v->map[y][x] == '0' || v->map[y][x] == 'C')
	{
		if (v->map[y][x] == 'C')
			v->collect--;
		v->map[y][x] = 'P';
		v->map[v->pos[Y]][v->pos[X]] = '0';
		v->pos[Y] = y;
		v->pos[X] = x;
		print_step(v);
	}
	else if (v->map[y][x] == 'E' && !v->collect)
		(msg_win(), shutdown(v));
}

int	handle_input(int key, t_info *v)
{
	if (key == ESC)
		close_window(v);
	else if (key == UP || key == W)
		move(v, v->pos[Y] - 1, v->pos[X]);
	else if (key == DOWN || key == S)
		move(v, v->pos[Y] + 1, v->pos[X]);
	else if (key == LEFT || key == A)
		move(v, v->pos[Y], v->pos[X] - 1);
	else if (key == RIGHT || key == D)
		move(v, v->pos[Y], v->pos[X] + 1);
	return (0);
}
