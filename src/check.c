/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 18:24:01 by pilespin          #+#    #+#             */
/*   Updated: 2015/09/25 10:59:08 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"

void	ft_check_user_error(int ac, char **av)
{
	if (ac != 2 || ft_atoi(av[1]) > 9 || ft_atoi(av[1]) < 1)
	{
		ft_printf("Usage %s [1-9]\n", av[0]);
		exit(-1);
	}
	if (MAP_X < 2 || MAP_Y < 2)
	{
		ft_printf("Map size is too small. Size min 2.\n");
		exit(-1);
	}
}

int		ft_check_if_is_dead(t_st *e, int pos)
{
	int i;
	int j;
	int tmp;

	if (e->shm[pos] != EMPTY_CASE)
	{
		tmp = P;
		P = pos;
		ft_get_neighbour(e);
		P = tmp;
		i = -1;
		while (e->near[++i])
		{
			j = -1;
			while (e->near[++j])
			{
				if (i != j && e->near[i] == e->near[j] &&
					e->near[j] != e->shm[pos])
					return (1);
			}
		}
	}
	return (0);
}

int		ft_check_if_one_near_is_dead(t_st *e)
{
	if (ft_check_if_is_dead(e, P) || ft_check_if_is_dead(e, N) ||
		ft_check_if_is_dead(e, NE) || ft_check_if_is_dead(e, NO) ||
		ft_check_if_is_dead(e, E) || ft_check_if_is_dead(e, O) ||
		ft_check_if_is_dead(e, SE) || ft_check_if_is_dead(e, S) ||
		ft_check_if_is_dead(e, SO))
		return (1);
	else
		return (0);
}

int		ft_check_if_team_have_win(char *shm)
{
	int		i;
	char	c;

	c = -120;
	i = -1;
	while (shm[++i])
	{
		if (c != -120 && shm[i] - 48 >= 1 && shm[i] - 48 <= 9)
		{
			if (shm[i] != c)
				return (0);
		}
		else if (c == -120 && shm[i] - 48 >= 1 && shm[i] - 48 <= 9)
			c = shm[i];
	}
	if (c == -120)
		return (0);
	return ((int)c - 48);
}

void	ft_check_team_arround(t_st *e, int team)
{
	int	i;

	i = -1;
	while (e->near[++i])
		;
	if (team >= 1 && team <= 9)
		e->near[i] = team + 48;
}
