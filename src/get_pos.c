/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 18:24:01 by pilespin          #+#    #+#             */
/*   Updated: 2015/09/18 00:15:17 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"

int		ft_get_x(int pos)
{
	while (pos > MAP_X)
		pos -= MAP_X + 1;
	return (pos);
}

int		ft_get_y(int pos)
{
	int x;

	x = 0;
	while (pos > MAP_X)
	{
		pos -= MAP_X + 1;
		x++;
	}
	return (x);
}

int		ft_get_far_team(t_st *e, int pos)
{
	int i;
	int tmp;
	int posmin;

	tmp = -1;
	posmin = 0;
	i = -1;
	while (e->shm[++i])
	{
		if (e->shm[i] >= 49 && e->shm[i] <= 57 &&
			e->shm[i] == e->team && i != pos)
		{
			if (tmp < ft_get_distance(e, i))
			{
				tmp = ft_get_distance(e, i);
				posmin = i;
			}
		}
	}
	if (posmin >= 0)
		return (posmin);
	else
		return (-1);
}

int		ft_get_near_team(t_st *e, int pos)
{
	int i;
	int tmp;
	int posmin;

	tmp = 999999999;
	posmin = 0;
	i = -1;
	while (e->shm[++i])
	{
		if (e->shm[i] >= 49 && e->shm[i] <= 57 &&
			e->shm[i] == e->team && i != pos)
		{
			if (tmp > ft_get_distance(e, i))
			{
				tmp = ft_get_distance(e, i);
				posmin = i;
			}
		}
	}
	return (posmin);
}

int		ft_get_near_enemy(t_st *e, int pos)
{
	int i;
	int tmp;
	int posmin;

	tmp = 999999999;
	posmin = 0;
	i = -1;
	while (e->shm[++i])
	{
		if (e->shm[i] >= 49 && e->shm[i] <= 57 &&
			e->shm[i] != e->team && i != pos)
		{
			if (tmp > ft_get_distance(e, i))
			{
				tmp = ft_get_distance(e, i);
				posmin = i;
			}
		}
	}
	return (posmin);
}
