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

void	ft_restore_access(t_st *e)
{
	struct sembuf	sops;

	sops.sem_num = 0;
	sops.sem_op = 1;
	sops.sem_flg = 0;
	semop(e->semid, &sops, 1);
}

void	ft_block_access(t_st *e)
{
	struct sembuf	sops;

	sops.sem_num = 0;
	sops.sem_op = -1;
	sops.sem_flg = 0;
	semop(e->semid, &sops, 1);
}

void	ft_delete_all_shared(t_st *e)
{
	shmctl(e->shmid, IPC_RMID, NULL);
	semctl(e->semid, 0, IPC_RMID);
}
