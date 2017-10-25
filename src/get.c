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

int		ft_get_distance(t_st *e, int pos)
{
	int xmin;
	int ymin;

	xmin = ft_absint(ft_get_x(P) - ft_get_x(pos));
	ymin = ft_absint(ft_get_y(P) - ft_get_y(pos));
	return (xmin + ymin);
}

void	ft_get_or_create_shmid(t_st *e)
{
	e->shmid = -1;
	if ((e->shmid = shmget(e->key, SIZE, 0)) < 0)
		e->shmid = ft_create_shm(e, ft_create_map());
}

char	*ft_get_shm(t_st *e)
{
	char	*shm;

	if ((shm = shmat(e->shmid, NULL, 0)) == (char *)-1)
	{
		perror("Error get map shmat");
		exit(-1);
	}
	return (shm);
}

void	ft_get_neighbour(t_st *e)
{
	ft_bzero(e->near, 10);
	ft_check_team_arround(e, e->shm[NO] - 48);
	ft_check_team_arround(e, e->shm[N] - 48);
	ft_check_team_arround(e, e->shm[NE] - 48);
	ft_check_team_arround(e, e->shm[O] - 48);
	ft_check_team_arround(e, e->shm[E] - 48);
	ft_check_team_arround(e, e->shm[SO] - 48);
	ft_check_team_arround(e, e->shm[S] - 48);
	ft_check_team_arround(e, e->shm[SE] - 48);
}
