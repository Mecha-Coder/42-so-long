/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 06:07:28 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 06:08:08 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_intlenght(int c)
{
	size_t	ret;

	ret = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		ret++;
	while (c)
	{
		c = c / 10;
		ret++;
	}
	return (ret);
}

char	*get_str(int n)
{
	char	*str;
	size_t	lenght;
	size_t	i;

	lenght = ft_intlenght(n);
	str = malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return (NULL);
	str[lenght] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		i = 1;
	}
	else
		i = 0;
	while (lenght-- > i)
	{
		if (n < 0)
			str[lenght] = 48 + (n % 10) * (-1);
		else
			str[lenght] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
