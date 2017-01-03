/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removetetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:19:05 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/02 14:28:38 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_removetetri(char **map, int tetri)
{
	char	t;
	int	x;
	int y;
	
	x = 0;
	y = 0;
	t = 65 + tetri;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == t)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}
