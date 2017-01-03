/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:15:14 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/02 14:05:50 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memallocMap(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_setmap(size_t size)
{
	char	**map;
	size_t		i;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * size + 1)))
			return (NULL);
	while (i < size)
		map[i++] = ft_memallocMap(size);
	map[i] = NULL;
	return (map);
}
/*
int		main(int ac, char **av)
{
	int	i;
	char	**map;

	i = 0;
	map = ft_setmap(atoi(av[1]));
	while (map[i] != 0)
	{
		printf("%s\n", (map[i]));
		i++;
	}
	return (0);
}*/
