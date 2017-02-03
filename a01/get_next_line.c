/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:54:42 by meassas           #+#    #+#             */
/*   Updated: 2017/02/03 05:53:02 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	len = 0;
	if (buff)
	{
		len = ft_strgnlen(buff);
		//ft_putstr("len buff = ");
		//ft_putnbr(len);
	}
	//ft_putstr("len stock = ");
	//if (ft_strgnlen(stock) == 0)
	//	return (tmpline);
	len += ft_strgnlen(stock);
	//ft_putnbr(len);
	tmpline = ft_memalloc(len + 1);
	//if (!len)
	//	return (tmpline);
	if (buff)
		tmpline = ft_strncat(buff, stock, ft_strgnlen(stock));
	else
		tmpline = ft_strncpy(tmpline, stock, ft_strgnlen(stock));
	return (tmpline);
}

int		get_next_line(int const fd, char **line)
{
	int ret;
	static char *stock = NULL;
	char *buffer;

	*line = NULL;
	buffer = ft_memalloc(BUFF_SIZE + 1);
	//ft_putendl("GNl");
	if (!line || fd < 0)
		return (-1);
	if (stock)
	{
		//ft_putendl("stock != NULL2");
		*line = get_line(*line, stock + 1);
		stock = ft_strchr(stock + 1, '\n');
		if (stock && (*stock == '\n'))
			return (1);
		else if (stock == NULL && (stock = ft_strchr(buffer, '\0')))
		{
		//	ft_putendl("stock == NULL");
			*line = ft_strjoin(*line, stock);
			free(stock);
			//free(buffer);
			stock = ft_memalloc(BUFF_SIZE + 1);
			//buffer = ft_memalloc(BUFF_SIZE + 1);
			//stock = ft_strchr(buffer, '\0');
		}
		//ft_putendl("stock != 99");
//stock = ft_memalloc(BUFF_SIZE + 1);
		//ft_putendl("stock1 = ");
		//ft_putendl(stock);
		//ft_putstr("line = ");
		//ft_putendl(*line);
		/*if (stock == NULL)
		{
			//stock = ft_strchr(stock, '\0'))
			*line = get_line(*line, stock);
		}*/
	}
	if (stock == NULL)
	{
		//ft_putendl("stock == null");
		stock = ft_memalloc(BUFF_SIZE + 1);
	}
	while ((ft_strchr(buffer, '\n')) == NULL && *line)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) < 1 && *line)
		{
			if (ret < 0)
				return (-1);
			if (ret == 0 && ((**line != '\0')))
			{
				free(stock);
				free(buffer);
				//ft_putendl("yoyo");
				return (1);
			}
			if (ret == 0/* && *line == NULL*/)
			{
				//ft_putendl("yo");
				return (0);
			}
		}
		buffer[ret] = '\0';
		stock = ft_strchr(buffer, '\n');
		*line = get_line(*line, buffer);
		//free(buffer);
		//ft_putendl("buffer");
		if (stock && (*stock == '\n'))
			return (1);
		//ft_putendl("buffer2");
		/*if (stock == NULL && (stock = ft_strchr(buffer, '\0')))
		{
			//ft_putendl("stock == NULL");
			*line = ft_strjoin(*line, buffer);
			//free(stock);
			//free(buffer);
			//stock = ft_memalloc(BUFF_SIZE + 1);
			//buffer = ft_memalloc(BUFF_SIZE + 1);
			//stock = ft_strchr(buffer, '\0');
		}*/
	}
	return (get_next_line(fd, line));
}

/*int		main(int ac, char **av)
{
	int fd;
	char *line;
	(void)ac;
	int ret;
	char *stock;

	fd = open(av[1], O_RDONLY);
	if (line)
		free(line);
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
