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

void	ft_draw_score(t_st *e)
{
	int		winner;
	int		nb;

	winner = ft_check_if_team_have_win(e->shm);
	nb = ft_count_nbr_of_player_on_map(e->shm);
	if (system("clear"))
		usleep(50000);
	ft_printf("\n%d Players on map\n", nb);
	if (!e->min_player_reached)
		ft_draw_score_wait(e, nb);
	else
	{
		if (!winner && e->min_player_reached)
			e->tim = ft_utime() - e->time_start;
		if (e->time_start)
			printf("Running time %.1f sec\n", e->tim);
		if (e->min_player_reached && winner)
			ft_printf("Team \"%d\" Win !!\n", winner);
	}
}

void	ft_draw_score_wait(t_st *e, int nb)
{
	if (!e->min_player_reached && nb >= MIN_PLAYER_TO_START)
	{
		e->time_start = ft_utime();
		e->min_player_reached = 1;
	}
	if (!e->time_start)
		ft_printf("Waiting \"%d\" Players !!\n", MIN_PLAYER_TO_START - nb);
}
