/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:31:20 by meassas           #+#    #+#             */
/*   Updated: 2017/01/18 02:21:35 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != c)
	{
		if ((str[i] == '\0' && (c != '\0' || c != 0xff00)))
			return (NULL);
		i++;
	}
	return ((char*)&str[i]);
}

/*int		main(void)
{
	char *str;

	str = "mehdi assas\n38 rue jean pierre timbaud\n92400\nCourbevoie\n";
	if (str)
		ft_putendl(ft_strchr(str, '\n'));
}*/
