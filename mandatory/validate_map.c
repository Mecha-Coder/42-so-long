/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:19:53 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 06:34:06 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	map_rectangular(t_info *x)
{
	int		length;
	int		i;
	char	*msg;

	i = 0;
	msg = "Error\nInvalid map: It is not rectangular\n";
	if (get_height(x->map) > 2)
	{
		length = get_len(x->map[0]);
		if (length > 2)
		{
			while (x->map[++i])
			{
				if (get_len(x-> map[i]) != length)
					return (print(msg), FALSE);
			}
			return (TRUE);
		}
	}
	return (print(msg), FALSE);
}

static int	contain_allowed_characters(t_info *x, int p, int e, int i)
{
	int	j;

	while (x->map[++i])
	{
		j = -1;
		while (x->map[i][++j])
		{
			if (x->map[i][j] == 'P')
				(assign_start(x, i, j), p++);
			else if (x->map[i][j] == 'E')
				e++;
			else if (x->map[i][j] == 'C')
				x->collect++;
			else if (x->map[i][j] == '0' || x->map[i][j] == '1')
			{
			}
			else
				return (print(MSG_ERROR_1), FALSE);
		}
	}
	if (p == 1 && e == 1 && x->collect >= 1)
		return (TRUE);
	return (print(MSG_ERROR_2), FALSE);
}

static int	map_surrounded_with_wall(t_info *z)
{
	int		i;
	char	*msg;

	msg = "Error\nInvalid map: Not surrounded by walls";
	i = -1;
	z->grid[Y] = get_height(z->map);
	z->grid[X] = get_len(z->map[0]);
	while (++i < z->grid[X])
	{
		if (z->map[0][i] != '1' || z->map[z->grid[Y] - 1][i] != '1')
			return (print(msg), FALSE);
	}
	i = -1;
	while (++i < z->grid[Y])
	{
		if (z->map[i][0] != '1' || z->map[i][z->grid[X] - 1] != '1')
			return (print(msg), FALSE);
	}
	return (TRUE);
}

static int	map_have_valid_path(t_info *x)
{
	char	**duplicate;
	char	*msg;

	msg = "Error\nInvalid map: No valid path\n";
	x->c = x->collect;
	x->e = 1;
	duplicate = dup_map(x, NULL, TRUE, -1);
	if (duplicate)
	{
		explore(duplicate, x->pos[X], x->pos[Y], x);
		flush_map(duplicate);
	}
	if (x->c == 0 && x->e == 0)
		return (TRUE);
	return (print(msg), FALSE);
}

int	validate_map(t_info *x)
{
	if (map_rectangular(x))
	{
		if (contain_allowed_characters(x, 0, 0, -1))
		{
			if (map_surrounded_with_wall(x))
			{
				if (map_have_valid_path(x))
					return (TRUE);
			}
		}
	}
	return (flush_map(x->map), FALSE);
}
