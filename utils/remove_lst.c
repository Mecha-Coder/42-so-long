/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 06:08:49 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 06:09:21 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	remove_lst_nonprintable_char(char *s)
{
	int	len;
	int	i;

	i = 1;
	len = get_len(s);
	if (len)
	{
		while ((len - i) >= 0 && (s[len - i] >= 1 && s[len - i] <= 31))
			s[len - i++] = '\0';
	}
}
