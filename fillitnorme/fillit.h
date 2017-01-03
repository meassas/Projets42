/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:38:41 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/14 14:51:47 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct		int_list
{
	int		i;
	int		x;
	int		y;
}					int_list;

int		placetetri(char **tetri, char **map, int t, int my, int mx, int m);
int		ft_deplacebloc_ok(char *tetri, char **map, int t, int one);
int		ft_placebloc_OK(char *tetri, char **map, int my, int mx, int let);
int		ft_deplacebloctetri(char *tetri, char **map, int t, int one);
int		ft_deplacetetri_ok_y(char **map, int tetri);
int		ft_deplacetetri_ok_x(char **map, int tetri);
int		ft_deplacetetri_y(char **map, int tetri);
void	*set_int(int_list *t);
int		ft_place_OK(char *tetri, char **map, int my, int mx);
void	ft_cpy(char *tetri, char **map, int my, int mx);
char	**ft_placeTetri(char **tetri, char **map, int t);
void	ft_setalpha(char **s);
void	*ft_memallocMap(size_t size);
char	**ft_setmap(size_t size);
int		cntTetri(char *s, char c);
char	**ft_splitetri(char *s, char c);
int		ft_xblanc(char *s);
int		ft_yblanc(char *s);
void	ft_swaptetri(char *tetri, int v);
void	ft_rangetetri(char **tetri);
int		ft_sqrtSup(int nb);
int		ft_deplacetetri(char **map, int tetri);
void	ft_removetetri(char **map, int tetri);
int		check_line(char *s);
int		ft_tetri_linker(char *s);
int		ft_tetri_isvalid(char *s);
#endif
