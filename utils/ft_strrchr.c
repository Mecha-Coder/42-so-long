/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:43:50 by jpaul             #+#    #+#             */
/*   Updated: 2024/06/26 15:45:46 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*
    Description
        search for the last occurance of a specific character in a string
    Param
        str -> pointer to string (char *)
        c -> character to be search (int)
    Return
        type :char *
        1) pointer to the last occurance
        2) NULL is not found
*/

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = get_len((char *)str);
	if (c == '\0')
		return ((char *)(str + i));
	while (i)
	{
		if (*(str + i - 1) == (char)c)
			return ((char *)(str + i - 1));
		i--;
	}
	return (NULL);
}

/*
int main()
{   
    char str1[] = "https://www.tutorialspoint.com";
    char ch1 = '.';
    printf("%s\n%s\n\n", strrchr(str1,ch1), ft_strrchr(str1, ch1));
    
    char str2[] = "https://www.tutorialspoint.com";
    char ch2 = 'w';
    printf("%s\n%s\n\n", strrchr(str2,ch2), ft_strrchr(str2, ch2));
    
    char str3[] = "";
    char ch3 = 'w';
    printf("%s\n%s\n\n", strrchr(str3,ch3), ft_strrchr(str3, ch3));
}
*/
