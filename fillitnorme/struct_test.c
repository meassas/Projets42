/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:09:33 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/08 13:39:06 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

void	*set_int(int_list *t)
{
	t = malloc(sizeof(int_list));
	t->i = 0;
	t->x = 0;
	t->y = 0;
	return (t);
}
