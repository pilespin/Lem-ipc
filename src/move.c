/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 18:24:01 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/11 15:39:05 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"

void	ft_move_player_on_map(t_st *e)
{
	int	nb;

	ft_block_access(e);
	if (ft_check_if_is_dead(e, P))
	{
		ft_putstr("!");
		e->shm[P] = EMPTY_CASE;
		ft_restore_access(e);
		exit(0);
	}
	nb = ft_count_nbr_of_player_on_map(e->shm);
	if (e->min_player_reached)
		e->min_player_reached2 = 1;
	if (nb >= MIN_PLAYER_TO_START)
		e->min_player_reached = 1;
	if (e->min_player_reached2 && ft_check_if_team_have_win(e->shm))
	{
		ft_delete_all_shared(e);
		ft_restore_access(e);
		exit(0);
	}
	if (e->min_player_reached2)
		ft_move(e);
	ft_restore_access(e);
}

void	ft_escape(t_st *e)
{
	int pos;
	int old;
	int dist;
	int dist_max;
	int i;

	old = P;
	pos = P;
	i = -1;
	dist = 999999999;
	dist_max = 0;
	while (++i < 30)
	{
		ft_move_player_on_map_by_random(e);
		dist = ft_get_distance(e, ft_get_near_enemy(e, P));
		if (dist > dist_max)
		{
			pos = P;
			dist_max = dist;
		}
		ft_move_player_on_map_by_index(e, old);
	}
	ft_move_player_on_map_by_index(e, pos);
}

/*
**char	*ft_receive_msg(void)
**{
**	int		msgid;
**	struct msgform2
**	{
**		long	mtype;
**		char	mtext[256];
**	}
**	msg2;
**	msgid = msgget(KEY, IPC_CREAT | 0666);
**	msgrcv(msgid, &msg2, 256, 1, 0);
**	return (ft_strdup(msg2.mtext));
**}
*/

void	ft_move_player_on_map_by_random(t_st *e)
{
	int nb;

	nb = ft_random(1, 4);
	if (nb == 1)
		ft_move_player_on_map_by_index(e, N);
	else if (nb == 2)
		ft_move_player_on_map_by_index(e, S);
	else if (nb == 3)
		ft_move_player_on_map_by_index(e, E);
	else if (nb == 4)
		ft_move_player_on_map_by_index(e, O);
}

void	ft_move_player_on_map_by_index(t_st *e, int new_pos)
{
	int pos;

	pos = P;
	if (new_pos < SIZE && new_pos > 0 && e->shm[new_pos] == EMPTY_CASE)
	{
		e->shm[P] = EMPTY_CASE;
		P = new_pos;
		e->shm[new_pos] = e->team;
	}
	if (ft_check_if_is_dead(e, P))
		ft_move_player_on_map_by_index(e, pos);
}
