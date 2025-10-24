/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:55:25 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 05:55:25 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	msg_close(void)
{
	write(1, "\n", 1);
	write(1, "\x1b[31;01m", 9);
	write(1, "<< GAME EXIT >>\n", 16);
	write(1, "\x1b[0m", 5);
}

void	msg_lose(void)
{
	write(1, "\n", 1);
	write(1, "\x1b[31;01m", 9);
	write(1, "👾👾YOU LOSE👾👾\n", 26);
	write(1, "\x1b[0m", 5);
}

void	msg_step(char *s)
{
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	write(1, s, get_len(s));
	write(1, "\x1b[0m", 5);
	write(1, " steps", 6);
}

void	msg_win(void)
{
	write(1, "\n", 1);
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
}
