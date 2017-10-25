/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 14:56:38 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/11 20:29:23 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/project.h"

int		main(int ac, char **av)
{
	t_st	*e;
	int		i;
	int		chk;

	if ((chk = ft_select_sdl_or_shell(ac, av)) == -1)
		return (0);
	e = (t_st *)malloc(sizeof(t_st));
	ft_init_struct(e);
	i = 0;
	while ((e->shmid = shmget(e->key, SIZE, 0)) < 0)
	{
		if (i == 0)
		{
			i = 1;
			ft_putstr("Waiting a map...\n");
		}
		sleep(1);
	}
	e->shm = shmat(e->shmid, NULL, 0);
	signal(SIGINT, ft_signal);
	if (chk == 0)
		ft_draw_whith_shell(e);
	else
		ft_draw_whith_sdl(e);
	return (0);
}

int		ft_select_sdl_or_shell(int ac, char **av)
{
	if (ac == 2 && (ft_strcmp(av[1], "shell") == 0 ||
					ft_strcmp(av[1], "sdl") == 0))
	{
		if (ft_strcmp(av[1], "shell") == 0)
			return (0);
		if (ft_strcmp(av[1], "sdl") == 0)
			return (1);
	}
	else
		ft_putstr("Usage: visu [sdl | shell]\n");
	return (-1);
}
