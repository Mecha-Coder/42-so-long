/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:14:23 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/15 14:51:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	start_game(t_info *v)
{
	char	*msg[3];

	msg[0] = "Error\nFail to initialize MinilibX\n";
	msg[1] = "Error\nFail to create game window\n";
	msg[2] = "Error\nFail to download game images\n";


	
	v->mlx = mlx_init();
	if (!v->mlx)
		return (print(msg[0]), shutdown(v), FALSE);
	v->win = mlx_new_window(v->mlx, v->size[X], v->size[Y],
			"jpaul's so_long (MANDATORY)");
	if (!v->win)
		return (print(msg[1]), shutdown(v), FALSE);
	if (!download_img(v))
		return (print(msg[2]), shutdown(v), FALSE);
	msg_step("0");
	


	mlx_key_hook(v->win, handle_input, v);
	mlx_loop_hook(v->mlx, update_frame, v);
	mlx_hook(v->win, 17, 0, close_window, v);
	
	// Loop forever
	mlx_loop(v->mlx);	
	return (FALSE);
}

int	main(int size, char **list)
{
	t_info	v;

	reset_memory(&v, 0, sizeof(t_info));
	if (check_input(size, list))
	{
		if (download_map(&v, list[1]))
		{
			if (validate_map(&v))
			{
				v.size[Y] = v.grid[Y] * IMG_SIZE;
				v.size[X] = v.grid[X] * IMG_SIZE;
				start_game(&v);
			}
		}
	}
	return (FALSE);
}
