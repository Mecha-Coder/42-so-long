/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_correct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:45:07 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/01 14:45:07 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_hidden(char *filename)
{
	char	*base_name;

	base_name = ft_strrchr(filename, '/');
	if (base_name)
		base_name++;
	else
		base_name = filename;
	return (base_name[0] != '.');
}

// -4 -3 -2 -1
//  1  2  3  4
//  .  b  e  r /0
static int	is_file_extension_ber(char *s)
{
	int	size;

	size = get_len(s);
	if (s && size > 2 && is_hidden(s)
		&& s[size - 1] == 'r'
		&& s[size - 2] == 'e'
		&& s[size - 3] == 'b'
		&& s[size - 4] == '.')
		return (TRUE);
	return (FALSE);
}

int	check_input(int size, char **list)
{
	char	*msg[3];

	msg[0] = "Error\nNo map file given as argument\n";
	msg[1] = "Error\nProgram only accept a single map file\n";
	msg[2] = "Error\nMap file extension is not '.ber'\n";
	if (size == 1 || ((size == 2) && !list[1][0]))
		return (print(msg[0]), FALSE);
	else if (size != 2)
		return (print(msg[1]), FALSE);
	else if (!is_file_extension_ber(list[1]))
		return (print(msg[2]), FALSE);
	return (TRUE);
}

/*
int main(int size, char **list)
{
	is_input_correct(size, list);
	return (0);
}
*/

/*
ERRROR
./a.out d,ber
./a.out d.txt
./a.out .be
./a.out dsadadasdber
./a.out ""
./a.out
./a.out "dsadsa" "dsad"
./a.out dsa.ber dsa.ber

OK
./a.out .ber
./a.out dsadadasd.ber
./a.out a.ber
./a.out ./dsad./dsa.ber
./a.out "test.ber"
*/