

#include "libft.h"

#define BUF_SIZE 550// 21 Char * 26 Tetrimax

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char	**tabtetri;
	int		y;
	char	**map;
	char	**map2;

	if (ac > 2)
	{
		ft_putstr("<ERROR> Too many arguments");
		return (0);
	}
	y = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open FAILED");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE); // soit boucle de read, soit taille max 26 elements
	buf[ret] = '\0';
	if (ret > 546) //nb de char max pour 26 tetriminos
	{
		ft_putstr("<ERROR> Too many characters\nCheck your entrance file");
		return (0);
	}
	if (close(fd) == -1)
	{
		ft_putstr("read FAILED");
		return (1);
	}
	tabtetri = ft_splitetri(buf, '\n');
	ft_rangetetri(tabtetri);
	ft_setalpha(tabtetri);
	map = ft_setmap(5);
	map2 = (ft_placeTetri(tabtetri, map));
	while (map2[y] != 0)
	{
		ft_putstr(map2[y]);
		ft_putchar('\n');
		y++;
	}
	return (0);
}
