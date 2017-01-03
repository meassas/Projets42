/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitTetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:03:59 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/28 23:20:34 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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
		else if (s[i] == c && s[i + 1] == '\0')
			j++;
		i++;
	}
	return (j);
}

/*int main()
{
	char *str;

	str = "....\n####\n....\n....\n\n....\n####\n....\n....\n";
	ft_putnbr(cntTetri(str, '\n'));
}*/

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
		split[y++] = ft_strsub(s, i , 21); // 21 pour ajouter le dernier \n
		i += 21;
	}
	split[y] = 0;
	return (split);
}
