/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:03:54 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/23 19:12:01 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		proto_place(char **tetri, char **map, int t, int my, int mx, int m)
{
	int tmp;
	int y;
	int x;
	int test;

	test = 1;
	y = 0;
	x = 0;
	tmp = 0;
	if (ft_place_OK(tetri[t], map, my, mx) == 4 && map[my] != NULL)
	{
		if (tetri[t + 1] == NULL)
			return (1);
		ft_cpy(tetri[t], map, my, mx);
		//map debug
		tmp = 0;
		while (map[tmp])
		{
			ft_putendl(map[tmp]);
			tmp++;
		}
		ft_putchar('\n');
		if (proto_place(tetri, map, t + 1, 0, 0, m) == 0)
		{
			if (ft_deplacebloc_ok(tetri[t], map, t, 1) == 1)
			{
				ft_deplacebloctetri(tetri[t], map, t, 1);
				ft_putendl("map apres deplace"); //map test
				tmp = 0;
				while (map[tmp] != '\0')
					ft_putendl(map[tmp++]);
				ft_putchar('\n');              // fin map test
			}
			else if (ft_deplacebloc_ok(tetri[t], map, t, 1) == 0)
			{
				ft_removetetri(map, t);
				ft_putendl("map apres remove");
				tmp = 0;
				while (map[tmp] != '\0')
					ft_putendl(map[tmp++]);
				ft_putchar('\n');
				return (0);
			}
		}
		return((proto_place(tetri, map, t + 1, 0, 0, m)));
	}
	else if (map[my] == NULL)
		return (0);
	else
	{
		mx++;
		if (map[my][mx] == '\0')
		{
			my++;
			mx = 0;
		}
		return (proto_place(tetri, map, t, my, mx, m));
	}
	return (1);
}
