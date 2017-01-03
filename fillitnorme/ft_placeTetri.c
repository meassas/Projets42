/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeTetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:56:52 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/02 18:13:44 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	ft_place_OK(char *tetri, char **map, int my, int mx)
{
	int_list	*t;
	int res;

	t = NULL;
	res = 0;
	t = set_int(t);
	while (tetri[t->i] != '\0')
	{
		if (tetri[t->i] >= 'A' && tetri[t->i] <= 'Z')
			if ((my + t->y) >= (int)ft_strlen(map[0]))
				return (0);
		if (tetri[t->i] >= 'A' && tetri[t->i] <= 'Z')
		{
			if (map[my + t->y][mx + t->x] == '.')
				res++;
			t->x++;
		}
		else if (tetri[t->i] == '\n' && tetri[t->i + 1] != '\n')
		{
			t->y++;
			t->x = 0;
		}
		else
			t->x++;
		t->i++;
	}
	free (t);
	return (res);
}

void	ft_cpy(char *tetri, char **map, int my, int mx)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	x = 0;
	while (tetri[i] != '\0')
	{
		if(tetri[i] >= 'A' && tetri[i] <= 'Z')
		{
			map[my + y][mx + x] = tetri[i];
			x++;
		}
		else if (tetri[i] == '\n' && tetri[i + 1] != '\n')
		{
		y++;
		x = 0;
		}
		else
			x++;
		i++;
	}
}

int		placetetri(char **tetri, char **map, int t, int my, int mx, int m)
{
	if (tetri[t] == NULL)
		return(1);
		while (ft_place_OK(tetri[t], map, my, mx) != 4)
	{
		mx++;
		if (map[my][mx] == '\0')
		{
			my++;
			mx = 0;
		}
		if (map[my] == NULL)
		{
			if (ft_deplacebloc_ok(tetri[t - 1], map, t - 1, 1) == 1)
			{
				ft_deplacebloctetri(tetri[t - 1], map, t - 1, 1);
				m++;
				mx = 0;
				my = 0;
			}
			else
			{
				m++;
				while (ft_deplacebloc_ok(tetri[t - 1], map, t - 1, 1) == 0)
				{
					ft_removetetri(map, t - 1);
					t--;
				}
				if (t < 0 || ft_deplacebloc_ok(tetri[t], map, t - 1, 1 == -1))
					return (0);
				ft_deplacebloctetri(tetri[t - 1], map, t - 1, 1);
				mx = 0;
				my = 0;
			}
			//else
			//	return (0);
		}
	}
	ft_cpy(tetri[t], map, my, mx);
	return (placetetri(tetri, map, t + 1, 0, 0, m));
}
