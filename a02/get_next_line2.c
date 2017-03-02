/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:54:42 by meassas           #+#    #+#             */
/*   Updated: 2017/02/27 18:06:06 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static	int		ft_strgnlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

static char		*get_line(char *buff, char *stock)
{
	int len;
	char *tmpline;
	char *tmp;

	len = 0;
	if (buff)
		len = ft_strlen(buff);
	len += ft_strgnlen(stock);
	tmpline = ft_strnew(len);
	if (buff)
	{
		tmpline = ft_strncat(buff, stock, ft_strgnlen(stock));
	}
	else
	{
		tmp = tmpline;
		tmpline = ft_strncpy(tmp, stock, ft_strgnlen(stock));
		tmp = NULL;
	}
	//ft_putendl(tmpline);
	return (tmpline);
}

int		get_line_in_stock(char *stock, char **line)
{
	char *tmp;

	if ((tmp = ft_strchr(stock, '\n')))
	{
		*tmp = '\0';
		ft_putstr("line = ");
		ft_putendl(*line);
		if (!(*line))
			*line = ft_strnew(0);
		*line = ft_strjoin(*line, stock);
		ft_putstr("line2 = ");
		ft_putendl(stock);
		free(stock);
		stock = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
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
	tmp = NULL;
	*line = NULL;
	buffer = ft_strnew(BUFF_SIZE + 1);
	/*if (stock)
	{
		*if (stock + 1 != NULL)
		{
			tmp = *line;
			free(*line);
			stock = ft_strchr(stock + 1, '\n');
		}
		if (stock && (*stock == '\n'))
			return (1);*
		//if (stock && (*stock == '\0'))
		//return (1);
		if (get_line_in_stock(stock, line))
			return (1);
		//line = get_line(*line, stock);
		//if (!(*line))
		//	*line = ft_strnew(0);
		//stock = ft_strjoin(*line, stock);
	}*/
	//if (stock == NULL)
	//	stock = ft_strnew(0);
	while ((ft_strchr(buffer, '\n')) == NULL)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) < 1 && *line)
		{
			ft_putstr("ret = ");
			ft_putnbr(ret);
			if (ret < 0)
				return (-1);
			/*else if (ret == 0 && (*stock == '\0'))
			{
				ft_putnbr(111);
				return (0);
			}*/
			else if (ret == 0 && (**line != '\0'))
			{
				ft_putendl("yolo");
				return (1);
			}
			else if (ret == 0 && (**line == '\0'))
			{
				ft_putendl("yala");
				return (0);
			}
		}
	//	ft_putstr("ret = ");
		//ft_putnbr(ret);
		buffer[ret] = '\0';
		if ((tmp = ft_strchr(buffer, '\n')))
		{
			ft_putendl("yallah");
			*tmp = '\0';
			//xi/f (!(*line))
			//	*line = ft_strnew(0);
			ft_putstr("stock1 = ");
			ft_putendl(stock);
			if (stock)
			{
				ft_putendl("yallah2");
				*line = ft_strjoin(stock, *line);
				stock = ft_strdup(tmp + 1);
				tmp = NULL;
			}
			else
			{
				ft_putendl("yallah3");
				*line = ft_strjoin(*line, buffer);
				stock = ft_strdup(tmp + 1);
				tmp = NULL;
			}
			ft_putstr("stock2 = ");
			ft_putendl(stock);
			return (1);
		}
		if (!(*line))
			*line = ft_strnew(0);
		*line = ft_strjoin(stock, buffer);
		ft_putstr("*line = ");
		ft_putendl(*line);
	}
	//return (get_next_line(fd, line));
	return (0);
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
