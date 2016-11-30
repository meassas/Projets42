/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:19:34 by meassas           #+#    #+#             */
/*   Updated: 2016/11/30 17:44:46 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		check_line(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == '#' || s[i] == '.' || s[i] == '\n')
		{
			if (s[i] == '\n' && ((i % 5) == 0))
				j++;
			if (s[i] == '\n' && s[i - 1] == '\n')
				j++;
		}
		i++;
	}
	return (j);
}

int		ft_tetri_linker(char *s)
{
	int i;
	int link;

	link = 0;
	i = -1;
	while (++i < 22 && s[i] && link < 9)
	{
		if (s[i] == '#')
		{
			if (s[i] == '#' && s[i + 1] == '#')
				++link;
			if (s[i] == '#' && s[i - 1] == '#')
				++link;
			if (s[i] == '#' && s[i + 5] == '#')
				++link;
			if (s[i] == '#' && s[i - 5] == '#')
				++link;
		}
	}
	return (link);
}

/*int		main(void)
{
	char *str;

	str = "##..\n##..\n....\n....\n\n";
	printf("%d\n", ft_tetri_linker(str));
}*/

int		ft_tetri_isvalid(char *s)
{
	int i;
	int link;
	int point;
	int hash;

	hash = 0;
	point = 0;
	link = ft_tetri_linker(s);
	i = 0;
	if ((link == 6 || link == 8) && s[i])
	{
		while (i <= 21 && s[i])
		{
			if (s[i] == '\n' && s[i - 1] == '\n')
				++i;
			else if (((s[i] == '#' && (hash += 1)) || (s[i] == '.'
							&& (point += 1)) || s[i] == '\n'))
				++i;
			else
				return (0);
		}
	}
	if (hash == 4 && point == 12 && i == 21)
		return (1);
	return (0);
}

/*int		main(void)
{
	char *str;

	str = "..##\n...#\n....\n....\n\n";
	printf("%d\n", ft_tetri_isvalid(str));
}*/


