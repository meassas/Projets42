/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:54:42 by meassas           #+#    #+#             */
/*   Updated: 2017/01/27 06:40:57 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_strgnlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	return (len);
}

static char		*get_line(char *buff, char *stock)
{
	int len;
	char *tmpline;

	len = 0;
	if (buff)
		len = ft_strlen(buff);
	len += ft_strgnlen(stock);
	tmpline = ft_memalloc(len + 1);
	//if (!len)
	//	return (tmpline);
	if (buff)
	{
		//ft_putendl("test2");
		tmpline = ft_strncat(buff, stock, ft_strgnlen(stock));
	}
	else
	{
		//ft_putendl("test3");
		//ft_putendl(stock);
		tmpline = ft_strncpy(tmpline, stock, ft_strgnlen(stock));
		//ft_putstr("tmpline =");
		//ft_putendl(tmpline);
	}
	return (tmpline);
}

int		get_next_line(int const fd, char **line)
{
	int ret;
	static char *stock = NULL;
	char *buffer;

	//ft_putstr("stock1 = ");
	//ft_putendl(stock);
	*line = NULL;
	buffer = ft_memalloc(BUFF_SIZE + 1);
	if (!line || fd < 0)
		return (-1);
	if (stock)
	{
		if ((stock && (*stock == '\n') && (*++stock) == '\n'))
		{
			ft_putendl("newline * 2:");
			*line = ft_strnew(0);
			**line = ENDL;
			ft_putnbr(10);
			return (1);
		}
		else
		{
			ft_putendl("else if stock:");
			*line = get_line(*line, stock + 1);
			//ft_putendl(stock);
			stock = ft_strchr(stock + 1, '\n');
			if (stock && (*stock == '\n'))
			{
				ft_putnbr(4);
				return (1);
			}
			else if (!stock && ret > 0)
			{
				stock = ft_strchr(stock + 1, '\0');
				ft_putnbr(3);
				return (1);
			}
		}
		/*if (!stock)
		{
			ft_putnbr(3);
			return (1);
		}*/
	}
	if (stock == NULL)
		stock = ft_memalloc(BUFF_SIZE + 1);
	while ((ft_strchr(buffer, '\n')) == NULL)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) < 1)
		{
			ft_putendl("ret < 1");
			if (ret < 0)
				return (-1);
			if (stock && (*stock == '\n'))
				return (1);
			else if (ft_strlen(stock) == 0 && ret == 0)
				return (0);
		}
		buffer[ret] = '\0';
		*line = get_line(*line, buffer);
		stock = ft_strchr(buffer, '\n');
		//ft_putstr("stock = ");
		if (stock && (*stock == '\n'))
		{
			ft_putnbr(7);
			return (1);
		}
		else if (stock == NULL && ft_strchr(buffer, '\0') && (ret > 0 || ret == 0))
		{
			stock = ft_strchr(buffer, '\0');
			*line = get_line(*line, stock);
			ft_putnbr(6);
			//return (0);
		}
		else if (stock && (*stock == '\n'))
		{
			ft_putnbr(7);
			return (1);
		}
		ft_putendl("boucle");
	}
	return (1);
}

int		main(int ac, char **av)
{
	int fd;
	char *line;
	(void)ac;
	int ret;

	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		//ft_putstr("line = ");
		ft_putendl(line);
		//ft_putstr("ret = ");
		//ft_putnbr(ret);
		//free(line);
		//ft_putchar('\n');
		line = NULL;
	}
	close(fd);
}
