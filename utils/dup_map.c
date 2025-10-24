/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:57:20 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 05:57:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**dup_map(t_info *x, char **new_map, int loop, int i)
{
	char	*s;
	int		j;

	new_map = (char **)malloc(sizeof(char **) * (x->grid[Y] + 1));
	if (new_map)
	{
		while (++i < x->grid[Y] && loop)
		{
			s = NULL;
			j = -1;
			s = (char *)malloc(sizeof(char *) * (x->grid[X] + 1));
			if (s)
			{
				while (++j < x->grid[X])
					s[j] = x->map[i][j];
				s[j] = '\0';
				new_map[i] = s;
			}
			else
				(flush_map(new_map), new_map = NULL, loop = FALSE);
		}
		if (new_map)
			new_map[i] = NULL;
	}
	return (new_map);
}
