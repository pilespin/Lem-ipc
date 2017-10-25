/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 12:13:06 by pilespin          #+#    #+#             */
/*   Updated: 2015/09/17 22:29:11 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_img
{
	void			*mer;
	void			*ven;
	void			*ter;
	void			*mar;
	void			*jup;
	void			*sat;
	void			*ura;
	void			*nep;
	void			*plu;
}					t_img;

typedef struct		s_st
{
	int				shmid;
	int				semid;
	int				msgid;
	int				join;
	key_t			key;
	int				position;
	int				team;
	double			time_start;
	char			*shm;
	char			*near;
	int				min_player_reached;
	int				min_player_reached2;
	void			*rend;
	double			tim;
	struct s_img	*img;
}					t_st;

#endif
