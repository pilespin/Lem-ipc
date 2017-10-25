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

void	ft_draw_whith_shell(t_st *e)
{
	char	**tab;
	int		winner;
	int		nb;

	while (1)
	{
		tab = ft_strsplit(e->shm, SEPARATOR_MAP);
		nb = ft_count_nbr_of_player_on_map(e->shm);
		if (system("clear"))
			;
		ft_draw_map_shell(tab);
		ft_printf("\n%d Players on map\n", nb);
		ft_draw_player_on_map_shell(e, nb);
		if (e->time_start)
			printf("Running time %.1f sec\n", ft_utime() - e->time_start);
		if (e->min_player_reached &&
				(winner = ft_check_if_team_have_win(e->shm)))
		{
			ft_printf("Team \"%d\" Win !!\n", winner);
			exit(0);
		}
		ft_freetabchar(tab);
		usleep(100000);
	}
}

void	ft_draw_player_on_map_shell(t_st *e, int nb)
{
	if (!e->min_player_reached && nb >= MIN_PLAYER_TO_START)
	{
		e->time_start = ft_utime();
		e->min_player_reached = 1;
	}
	else if (e->time_start == 0)
		ft_printf("Waiting \"%d\" Players !!\n", MIN_PLAYER_TO_START - nb);
}

void	ft_draw_map_shell(char **tab)
{
	ft_putnbr(SIZE);
	ft_putstr(" octets:\n");
	ft_putnchar((MAP_X) * 2 + 1, '#');
	ft_putstr("\n");
	ft_draw_player_shell(tab);
	ft_putnchar((MAP_X) * 2 + 1, '#');
}

void	ft_draw_player_shell(char **tab)
{
	int		i;
	int		j;

	i = -1;
	while (tab[++i])
	{
		ft_putstr("#");
		j = -1;
		while (tab[i][++j])
		{
			if (j != 0)
				ft_putstrc(7, 0, "|");
			ft_draw_player_2_shell(tab, i, j);
		}
		ft_putstr("#\n");
	}
}

void	ft_draw_player_2_shell(char **tab, int i, int j)
{
	if (tab[i][j] - 48 == 1)
		ft_putcharc(1, 1, tab[i][j]);
	else if (tab[i][j] - 48 == 2)
		ft_putcharc(2, 2, tab[i][j]);
	else if (tab[i][j] - 48 == 3)
		ft_putcharc(3, 3, tab[i][j]);
	else if (tab[i][j] - 48 == 4)
		ft_putcharc(4, 4, tab[i][j]);
	else if (tab[i][j] - 48 == 5)
		ft_putcharc(5, 5, tab[i][j]);
	else if (tab[i][j] - 48 == 6)
		ft_putcharc(6, 6, tab[i][j]);
	else if (tab[i][j] - 48 == 6)
		ft_putcharc(7, 7, tab[i][j]);
	else
		ft_putchar(tab[i][j]);
}
