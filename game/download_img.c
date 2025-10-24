/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:53:28 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 05:54:02 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	downloading(t_info *v)
{
	int	s;

	s = IMG_SIZE;
	v->img[P_FRONT] = mlx_xpm_file_to_image(v->mlx, IMG_P_FRONT, &s, &s);
	v->img[P_BACK] = mlx_xpm_file_to_image(v->mlx, IMG_P_BACK, &s, &s);
	v->img[P_LEFT] = mlx_xpm_file_to_image(v->mlx, IMG_P_LEFT, &s, &s);
	v->img[P_RIGHT] = mlx_xpm_file_to_image(v->mlx, IMG_P_RIGHT, &s, &s);
	v->img[WALL] = mlx_xpm_file_to_image(v->mlx, IMG_WALL, &s, &s);
	v->img[FLOOR] = mlx_xpm_file_to_image(v->mlx, IMG_FLOOR, &s, &s);
	v->img[EXIT] = mlx_xpm_file_to_image(v->mlx, IMG_EXIT, &s, &s);
	v->img[O_EXIT] = mlx_xpm_file_to_image(v->mlx, IMG_O_EXIT, &s, &s);
	v->img[COLLECT] = mlx_xpm_file_to_image(v->mlx, IMG_COLLECT, &s, &s);
	v->img[M1] = mlx_xpm_file_to_image(v->mlx, IMG_M1, &s, &s);
	v->img[M2] = mlx_xpm_file_to_image(v->mlx, IMG_M2, &s, &s);
	v->img[M3] = mlx_xpm_file_to_image(v->mlx, IMG_M3, &s, &s);
}

int	download_img(t_info *v)
{
	int	i;

	i = 0;
	downloading(v);
	while (i < IMG_COUNT)
	{
		if (!v->img[i])
			return (FALSE);
		i++;
	}
	v->anime_exit = v->img[EXIT];
	v->anime_player = v->img[P_FRONT];
	v->anime_monster = v->img[M1];
	return (TRUE);
}
