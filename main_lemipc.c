/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemipc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 15:05:01 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/11 14:51:27 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/project.h"

int		main(int ac, char **av)
{
	t_st	*e;

	ft_check_user_error(ac, av);
	e = (t_st *)malloc(sizeof(t_st));
	e->key = KEY;
	e->near = ft_strnew(10);
	e->position = -1;
	e->join = 0;
	e->min_player_reached = 0;
	e->min_player_reached2 = 0;
	e->team = ft_atoi(av[1]) + 48;
	e->semid = semget(e->key, 1, IPC_CREAT | 0666);
	ft_get_or_create_shmid(e);
	e->shm = ft_get_shm(e);
	ft_insert_player_in_map(e);
	while (1)
	{
		ft_move_player_on_map(e);
		usleep(WAIT);
	}
	return (0);
}

/*
**void	ft_send_msg(char *message)
**{
**	int			msgid;
**	struct		msgform
**	{
**		long	mtype;
**		char	mtext[256];
**	}
**	msg;
**	if (ft_strlen(message) >= 256)
**		message[256] = '\0';
**	msgid = msgget(KEY, IPC_CREAT | 0666);
**	msg.mtype = 1;
**	strcpy(msg.mtext, message);
**	msgsnd(msgid, &msg, ft_strlen(msg.mtext) + 1, 0);
**	ft_printf("send = \"%s\"\n", msg.mtext);
**}
*/
