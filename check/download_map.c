/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:30:36 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/07 05:30:36 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**append_map(char **list, char *s)
{
	static int	size;
	char		**newlist;
	int			i;

	i = 0;
	newlist = (char **)malloc(sizeof(char *) * (++size + 1));
	if (((size < 2 && !list) || (size >= 2 && list)) && s && newlist)
	{
		while (list && list[i])
		{
			newlist[i] = list[i];
			i++;
		}
		newlist[i++] = s;
		newlist[i] = NULL;
		return (newlist);
	}
	else
		return (NULL);
}

static int	downloading(t_info *x, int fd, int loop)
{
	char	**temp;
	char	*s;

	while (loop)
	{
		s = get_next_line(fd);
		if (s)
		{
			remove_lst_nonprintable_char(s);
			temp = x->map;
			x->map = append_map(temp, s);
			if (!x->map)
			{
				flush_map(temp);
				return (print(MSG_ERROR_3), FALSE);
			}
			else if (temp)
				free(temp);
		}
		else
			loop = FALSE;
	}
	return (TRUE);
}

int	download_map(t_info *x, char *file)
{
	char	*msg[3];
	int		fd;

	msg[0] = "Error\nFile not found\n";
	msg[1] = "Error\nFile is not readeble\n";
	msg[2] = "Error\nFile is empty\n";
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print(msg[0]), FALSE);
	else if (read(fd, NULL, 0) == -1)
		return (print(msg[1]), close(fd), FALSE);
	else if (downloading(x, fd, TRUE))
	{
		if (x->map)
			return (close(fd), TRUE);
		else
			return (print(msg[2]), close(fd), FALSE);
	}
	return (close(fd), FALSE);
}

/*
//Test ---> remove_map()
int main()
{
	char s1[] = "This is awesome\n\n\n";
	print(s1);
	print("---------\n");
	remove_newline(s1);
	print(s1);
	print("---------\n");
	remove_newline(s1);
	print(s1);
	print("---------\n");
	remove_newline(s1);
	print(s1);
	print("---------\n");
	remove_newline(s1);
	print(s1);
	print("---------\n");
	remove_newline(s1);
	print(s1);
	print("---------\n");
	char s2[] = "\n";
	remove_newline(s2);
	print(s2);
	print("---------\n");
	remove_newline(s2);
	print(s2);
	print("---------\n");
}
*/

/*
//Test ---> append_map()
int main()
{
	char **list;
	char **temp;
	int i;

	i = 1;
	list = NULL;

	temp = list;
	list = append_map(temp, "Hello", i++);
	if (temp)
		free(temp);
	
	temp = list;
	list = append_map(temp, " there", i++);
	if (temp)
		free(temp);
	
	temp = list;
	list = append_map(temp, " , make it burn\n", i++);
	if (temp)
		free(temp);
	
	i = -1;
	while(list[++i])
		print(list[i]);
   free(list);

	return 0;
}
*/