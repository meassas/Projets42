/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitTetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:03:59 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/01 16:15:31 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cntTetri(char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] == c))
			j++;
		i++;
	}
	return (j);
}

char		**ft_splitetri(char *s, char c)
{
	int		i;
	int		y;
	char	**split;

	i = 0;
	y = 0;
	if (!(split = (char**)malloc(sizeof(char*) * (cntTetri(s, c)) + 1))
		|| (!s))
		return (NULL);
	while (y < cntTetri(s, c) && s[i]) //s[i] facultatif
	{
		split[y++] = ft_strsub(s, i , 20); // 21 pour ajouter le dernier \n
		i += 21;
	}
	split[y] = 0;
	return (split);
}
