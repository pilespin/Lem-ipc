/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 18:24:01 by pilespin          #+#    #+#             */
/*   Updated: 2015/09/25 10:54:14 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"

int		ft_count_nbr_of_player_on_map(char *shm)
{
	int		i;
	int		nb;

	nb = 0;
	i = -1;
	while (shm[++i])
	{
		if (shm[i] - 48 >= 1 && shm[i] - 48 <= 9)
			nb++;
	}
	return (nb);
}

void	ft_add_player_on_map_by_index(t_st *e, int new_pos)
{
	if (e->shm[new_pos] == EMPTY_CASE && new_pos < SIZE)
	{
		e->shm[new_pos] = 'O';
	}
}

void	ft_insert_player_in_map(t_st *e)
{
	ft_block_access(e);
	if (e->shm)
	{
		if ((e->position = ft_insert_in_map(e)) == -1)
		{
			ft_putstr("Map is full\n");
			ft_restore_access(e);
			exit(-1);
		}
	}
	ft_restore_access(e);
}

int		ft_insert_in_map(t_st *e)
{
	int		i;

	i = ft_random(0, SIZE);
	while (e->shm[++i])
	{
		if (ft_insert_in_map_after(e, i) != -1)
			return (i);
	}
	i = -1;
	while (e->shm[++i])
	{
		if (ft_insert_in_map_after(e, i) != -1)
			return (i);
	}
	return (-1);
}

int		ft_insert_in_map_after(t_st *e, int pos)
{
	if (e->shm[pos] == EMPTY_CASE)
	{
		e->shm[pos] = e->team;
		P = pos;
		if (ft_check_if_one_near_is_dead(e))
		{
			e->shm[pos] = EMPTY_CASE;
			return (-1);
		}
		else
			return (pos);
	}
	return (-1);
}
