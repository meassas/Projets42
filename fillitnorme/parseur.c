/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:19:34 by meassas           #+#    #+#             */
/*   Updated: 2017/01/02 17:56:36 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		check_line(char *s)
{
	int i;
	int j;
	int k;

	k = 4;
	i = 0;
	j = 0;
	if ((s[i] != '#' && s[i] != '.' && s[i] != '\n' && s[i] != '\0') && s[i])
		return (0);
	while ((s[i] == '#' || s[i] == '.' || s[i] == '\n' || s[i] == '\0') && s[i])
	{
		if (s[i] == '\n' && ((i == k)))
		{
			k += 5;
			j++;
		}
		else if (s[i] == '\n' && s[i - 1] == '\n')
			j++;
//		else if (s[i] == '\n' && ((i != k)))
//			return (0);
		i++;
	}
	return (j);
}

/*int		main()
{
	char *str;

	str = "....\n####\n....\n....\n";
	ft_putnbr(check_line(str));
}*/

int		ft_tetri_linker(char *s)
{
	int i;
	int link;

	link = 0;
	i = 0;
	if (check_line(s) == 5 || check_line(s) == 4)
	{
		while (i <= 21 && s[i] && link < 9)
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
			i++;
		}
		return (link);
	}
	return (0);
}

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
				i++;
			else if (((s[i] == '#' && (hash += 1)) || (s[i] == '.'
							&& (point += 1)) || s[i] == '\n'))
				i++;
			else
				return (0);
		}
	}
	if (hash == 4 && point == 12 && ((i == 20) || (i == 21)))
		return (1);
	return (0);
}

/*int		main()
{
	char *str;

	str = "....\n####\n....\n....\n\n";
	ft_putnbr(ft_tetri_isvalid(str));
}*/
