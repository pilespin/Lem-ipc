/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 18:24:01 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/11 14:46:42 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"

void	ft_move(t_st *e)
{
	if (e->join <= WAIT_JOIN_AT_START)
	{
		ft_move_player(e, ft_get_far_team(e, P));
		e->join++;
	}
	else if (ft_get_distance(e, ft_get_near_team(e, P)) > 2)
		ft_move_player(e, ft_get_near_team(e, P));
	else
		ft_move_player(e, ft_get_near_enemy(e, P));
}

void	ft_move_player(t_st *e, int pos)
{
	int random;

	random = ft_random(1, 5);
	if (random == 1 || random == 3)
		ft_move_one(e, pos);
	else if (random == 2 || random == 4)
		ft_move_two(e, pos);
	else
		ft_move_player_on_map_by_random(e);
}

void	ft_move_one(t_st *e, int enemy)
{
	if (ft_get_x(enemy) < ft_get_x(P))
		ft_move_player_on_map_algo(e, O);
	else if (ft_get_x(enemy) > ft_get_x(P))
		ft_move_player_on_map_algo(e, E);
	else if (ft_get_y(enemy) > ft_get_y(P))
		ft_move_player_on_map_algo(e, S);
	else if (ft_get_y(enemy) < ft_get_y(P))
		ft_move_player_on_map_algo(e, N);
}

void	ft_move_two(t_st *e, int enemy)
{
	if (ft_get_y(enemy) < ft_get_y(P))
		ft_move_player_on_map_algo(e, N);
	else if (ft_get_y(enemy) > ft_get_y(P))
		ft_move_player_on_map_algo(e, S);
	else if (ft_get_x(enemy) > ft_get_x(P))
		ft_move_player_on_map_algo(e, E);
	else if (ft_get_x(enemy) < ft_get_x(P))
		ft_move_player_on_map_algo(e, O);
}

void	ft_move_player_on_map_algo(t_st *e, int pos)
{
	if (e->join <= WAIT_JOIN_AT_START)
	{
		if (ft_get_distance(e, ft_get_near_enemy(e, P)) < 5)
			ft_escape(e);
		else
			ft_move_player_on_map_by_index(e, pos);
	}
	else
	{
		if (ft_get_distance(e, ft_get_near_enemy(e, P)) < 8 &&
			ft_get_distance(e, ft_get_near_team(e, P)) > 2)
			ft_escape(e);
		else
			ft_move_player_on_map_by_index(e, pos);
	}
}
