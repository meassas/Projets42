/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:54:42 by meassas           #+#    #+#             */
/*   Updated: 2017/03/02 20:53:47 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		get_line_in_stock(char *stock, char **line)
{
	char *tmp;

	if ((tmp = ft_strchr(stock, '\n')))
	{
		*tmp = '\0';
		ft_putstr("stock2 = ");
		ft_putendl(stock);
		if (!(*line))
			*line = ft_strnew(0);
		*line = ft_strjoin(*line, stock);
		free(stock);
		ft_putstr("tmp = ");
		ft_putendl(tmp);
		stock = ft_strdup(tmp + 1);
		ft_putstr("stock = ");
		ft_putendl(stock);
		tmp = NULL;
		return (1);
	}
	ft_putstr("stock 3 = ");
	ft_putendl(stock);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	int ret;
	static char *stock = NULL;
	char *buffer;
	char *tmp;

	ft_putendl("apl fct");
	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	buffer = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(0);
	if (stock)
	{
		ft_putstr("stock1 = ");
		ft_putendl(stock);
		ft_putnbr(198);
		if (get_line_in_stock(stock, line))
			return (1);
		//stock = ft_strjoin(stock, *line);
	}
	while ((ft_strchr(buffer, '\n')) == NULL)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) < 1 && *line && stock != NULL)
		{
			ft_putstr("ret = ");
			ft_putnbr(ret);
			ft_putstr("buffer = ");
			ft_putendl(buffer);
			if (ret < 0)
				return (-1);
			else if (ret == 0 && *buffer == '\0')
				return (0);
			else if (ret == 0 && ((**line != '\0')))/* || (stock && line)))*/
				return (1);
			//else if (ret == 0 && *buffer == '\0')
			//	return (0);
		}
		buffer[ret] = '\0';
		if ((tmp = ft_strchr(buffer, '\n')))
		{
			*tmp = '\0';
			if (!stock)
			{
				ft_putnbr(255);
				stock = ft_strnew(0);
				*line = ft_strjoin(*line, buffer);
				//free(buffer);
			}
			else
			{
				ft_putnbr(155);
				*line = ft_strjoin(stock , buffer);
			//	free(buffer);
			}
			ft_putnbr(855);
			stock = ft_strdup(tmp + 1);
			tmp = NULL;
			return (1);
		}
		if (!(*line))
			*line = ft_strnew(0);
		if (stock)
		{
			ft_putnbr(55);
			*line = ft_strdup(stock);
			free(stock);
			stock = NULL;
		}
		ft_putnbr(77);
		//stock = ft_strchr(buffer, '\0');
		ft_putstr("stock5 = ");
		ft_putendl(stock);
		tmp = ft_strjoin(*line, buffer);
		*line = tmp;
		tmp = NULL;
	}
	return (1);
}

/*int		main(int ac, char **av)
{
	int fd;
	char *line;
	(void)ac;
	int ret;
	char *stock;

	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		ft_putstr("line = ");
		ft_putendl(line);
		free(line);
		line = NULL;
	}
	close(fd);
	while (1)
	{
	}
}*/
