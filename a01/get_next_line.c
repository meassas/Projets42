/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:54:42 by meassas           #+#    #+#             */
/*   Updated: 2017/02/08 20:49:58 by meassas          ###   ########.fr       */
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
	tmpline = ft_memalloc(len + 1);
	//tmpline = NULL;
	if (buff)
	{
		tmpline = ft_strncat(buff, stock, ft_strgnlen(stock));
		//free(tmpline);
		//tmpline = ft_memmove(tmpline, stock, ft_strgnlen(stock) + ft_strlen(buff));
	}
	else
	{
		//tmpline = ft_memcpy(tmpline, stock, ft_strgnlen(stock));
		tmp = tmpline;
		ft_memdel((void**)&tmpline);
		ft_memdel((void**)tmpline);
		tmpline = ft_memmove(tmp, stock, ft_strgnlen(stock));
		//ft_memdel((void**)tmp);
		//ft_memdel((void**)&tmp);
		//free(tmpline);
	}
	return (tmpline);
}

int		get_next_line(int const fd, char **line)
{
	int ret;
	static char *stock = NULL;
	char *buffer;

	if (!line || fd < 0)
		return (-1);
	buffer = NULL;
	*line = NULL;
	buffer = ft_memalloc(BUFF_SIZE + 1);
	if (stock)
	{
		if (stock + 1)
		{
			*line = get_line(*line, stock + 1);
			stock = ft_strchr(stock + 1, '\n');
		}
		if (stock && (*stock == '\n'))
			return (1);
		ft_memdel((void**)stock);
		ft_memdel((void**)&stock);
		//free(stock);
		/*else if (stock == NULL && (stock = ft_strchr(buffer, '\0')))
		{
			*line = ft_strjoin(*line, stock);
			//free(stock);
			//free(buffer);
			//stock = ft_memalloc(BUFF_SIZE + 1);
			//return (get_next_line(fd, line));
			//buffer = ft_memalloc(BUFF_SIZE + 1);
			//stock = ft_strchr(buffer, '\0');
		}*/
	}
	if (stock == NULL && *line == NULL)
	{
	//	free(buffer);
		stock = ft_memalloc(BUFF_SIZE + 1);
	}
	//if ((buffer == NULL && *line))
	while ((ft_strchr(buffer, '\n')) == NULL && *line)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) < 1 && *line)
		{
			if (ret < 0)
				return (-1);
			if (ret == 0 && ((**line != '\0')))
			{
	//			ft_memdel((void**)&buffer);
				return (1);
			}
			if (ret == 0 && **line == '\0')
			{
				ft_memdel((void**)&stock);
	//			ft_memdel((void**)&buffer);
				ft_memdel((void**)stock);
	//			ft_memdel((void**)buffer);
				//ft_memdel((void**)line);
				//ft_memdel((void*)*line);
		//		ft_putendl("yo");
				return (0);
			}
		}
		buffer[ret] = '\0';
		stock = ft_strchr(buffer, '\n');
		*line = get_line(*line, buffer);
		if (stock && (*stock == '\n'))
		{
			return (1);
		}
	//	ft_memdel((void**)&stock);
	//	free(stock);
		/*if (stock == NULL && *line)
		{
		//	*line = ft_strjoin(*line, buffer);
			//free(buffer);
			//ft_memdel((void**)buffer);
			stock = ft_memalloc(BUFF_SIZE + 1);
		}*/
	}
	//ft_memdel((void**)&stock);
	//free(stock);
	//return (1);
	return (get_next_line(fd, line));
}

/*int		main(int ac, char **av)
{
	int fd;
	char *line;
	(void)ac;
	int ret;
	char *stock;

	if (line)
		free(line);
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		ft_putstr("line = ");
		ft_putendl(line);
		//ft_putstr("ret = ");
		//ft_putnbr(ret);
		//if (line)
		//	free(line);
		//ft_putchar('\n');
		line = NULL;
	}
	close(fd);
}*/
