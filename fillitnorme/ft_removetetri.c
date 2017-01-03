/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removetetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:19:05 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/02 16:57:29 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_placebloc_OK(char *tetri, char **map, int my, int mx, int let)
{
	int_list	*t;
	int res;

	t = NULL;
	res = 0;
	t = set_int(t);
	while (tetri[t->i] != '\0')
	{
		if (tetri[t->i] == let)
			if ((my + t->y) >= (int)ft_strlen(map[0]))
				return (0);
		if (tetri[t->i] == let)
		{
			if (map[my + t->y][mx + t->x] == '.' || map[my + t->y][mx + t->x] == let)
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

int		ft_deplacebloc_ok(char *tetri, char **map, int t, int one)
{
	int y;
	int i;
	int x;

	i = 0;
	y = 0;
	x = 0;
	if (t == -1)
		return (- 1);
	while (tetri[i] && map[y][x] && tetri[i] == '.')
		i++;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == t + 65 && one == 1)
				one = 0;
			else if (ft_placebloc_OK(tetri, map, y, x - i, t + 65) == 4 && one == 0)
			{
				one = 3;
				return (1);
				one = 3;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int		ft_deplacebloctetri(char *tetri, char **map, int t, int one)
{
	int y;
	int x;
	int i;

	i = 0;
	y = 0;
	x = 0;
	while (tetri[i] == '.')
		i++;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == t + 65 && one == 1)
			{
				ft_removetetri(map, t);
				one = 0;
			}
			else if (ft_place_OK(tetri, map, y, x - i) == 4 && one == 0)
			{
				ft_cpy(tetri, map, y, x - i);
				one = 3;
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_deplacetetri_y(char **map, int tetri)
{
	char t;
	int y;
	int x;

	x = ft_strlen(map[0]) - 1;
	y = x;
	t = 65 + tetri;
	while (y >= 0)
	{
		while (x >= 0)
		{
			if (map[y][x] == t && (map[y + 1][x] != '.' && map[y + 1][x] != t))
				return (0);
			x--;
		}
		x = ft_strlen(map[0]) - 1;
		y--;
	}
	return (1);
}

int		ft_deplacetetri(char **map, int tetri)
{
	char	t;
	int x;
	int y;

	x = ft_strlen(map[0]) - 1;
	y = x;
	t = 65 + tetri;
	while (y >= 0)
	{
		while (x >= 0)
		{
			if (map[y][x] == t)
			{
				if (map[y][x + 1] == '.')
				{
					map[y][x] = '.';
					map[y][x + 1] = t;
				}
				else if (map[y][x] == t && map[y][x + 1] != '.')
					return (0);
			}
			x--;
		}
		x = ft_strlen(map[0]) - 1;
		y--;
	}
	return (1);
}

void	ft_removetetri(char **map, int tetri)
{
	char	t;
	int	x;
	int y;
	
	x = 0;
	y = 0;
	t = 65 + tetri;
//	if (ft_deplacetetri(map, t) == 0)
//	{
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == t)
				map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}

//	}
//	else
//		return (1);
}

/*int		main()
{
	int i;
	int b;
	char	t1[21] = "AAAA\n....\n....\n....\n\n";
	char	t2[21] = "BB..\n.B..\n.B..\n....\n\n";
	//char	t3[21] = "CC..\nCC..\n....\n....\n\n";
	char **map;

	b = 0;
	i = 0;
	map = ft_setmap(4);
	ft_cpy(t1, map, 3, 0);
	//ft_cpy(t3, map, 3, 2);
	ft_cpy(t2, map, 0, 0);
	while (b < 8)
	{
		ft_putnbr(ft_deplacebloc_ok(t2, map, 1, 1));
		ft_putchar('\n');
		if (ft_deplacebloc_ok(t2, map, 1, 1) == 1)
			ft_deplacebloctetri(t2, map, 1, 1);
		i = 0;
		while (map[i] != 0)
		{
			printf("%s\n", map[i]);
			i++;
		}
		b++;
	}
	return (0);
}*/
