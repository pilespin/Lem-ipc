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

int		ft_create_shm(t_st *e, char *content)
{
	int shmid;

	ft_putendl("Not get in shm");
	if ((shmid = shmget(e->key, SIZE, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget");
		exit(-1);
	}
	ft_create_shm_with_str(shmid, content);
	e->semid = semget(e->key, 1, IPC_CREAT | 0666);
	semctl(e->semid, 0, SETVAL, 1);
	return (shmid);
}

void	ft_create_shm_with_str(int shmid, char *str)
{
	char	*shm;

	ft_putendl("Create shm");
	if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
	{
		perror("shmat");
		exit(-1);
	}
	ft_strcpy(shm, str);
}

char	*ft_create_map(void)
{
	char	*map;
	int		i;
	int		j;
	int		k;

	map = (char *)malloc(sizeof(char) * (SIZE));
	i = -1;
	j = -1;
	k = 0;
	while (++j < MAP_Y)
	{
		i = -1;
		while (++i < MAP_X)
		{
			map[k++] = EMPTY_CASE;
		}
		map[k++] = SEPARATOR_MAP;
	}
	map[k] = '\0';
	return (map);
}
