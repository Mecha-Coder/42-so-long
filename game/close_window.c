/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:52:10 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 05:52:10 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// To fully free mlx resources
// Use mlx_destroy_display() only on Linux
// MacOS can't mlx_destroy_display(), there is some memory leak

void	shutdown(t_info *v)
{
	int	i;

	i = 0;
	if (v->mlx && v->win)
		mlx_destroy_window(v->mlx, v->win);
	if (v->step_str)
		free(v->step_str);
	while (i < IMG_COUNT)
	{
		if (v->img[i])
			mlx_destroy_image(v->mlx, v->img[i]);
		i++;
	}
	flush_map(v->map);
	if (v->mlx)
		free(v->mlx);
	exit(EXIT_SUCCESS);
}

int	close_window(t_info *v)
{
	msg_close();
	shutdown(v);
	return (0);
}
