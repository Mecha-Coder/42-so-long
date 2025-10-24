/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:40:35 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 06:36:35 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	explore(char **map, int x, int y, t_info *v)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		v->e -= 1;
		map[y][x] = '1';
		return ;
	}
	else if (map[y][x] == 'C')
		v->c -= 1;
	map[y][x] = '1';
	explore(map, x + 1, y, v);
	explore(map, x - 1, y, v);
	explore(map, x, y + 1, v);
	explore(map, x, y - 1, v);
}
