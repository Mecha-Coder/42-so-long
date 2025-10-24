/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 06:09:45 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 06:09:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*reset_memory(void *dst, int val, size_t n)
{
	void	*init_address;

	init_address = dst;
	while (n--)
		*(unsigned char *)dst++ = (unsigned char)val;
	return (init_address);
}
