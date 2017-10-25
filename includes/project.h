/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 12:13:13 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/11 20:30:23 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# define MAP_X 50
# define MAP_Y 30
# define PL_SZ 20
# define SDL_WINDOW_X MAP_X * PL_SZ
# define SDL_WINDOW_Y MAP_Y * PL_SZ
# define MIN_PLAYER_TO_START 5
# define WAIT_JOIN_AT_START MAP_X * 3
# define WAIT 100000
# define KEY 1234659417
# define EMPTY_CASE ' '
# define SEPARATOR_MAP '\n'
# define SIZE ((MAP_X + 1) * (MAP_Y + 1))
# define POS e->position
# define N e->position - (MAP_X + 1)
# define NE e->position - (MAP_X + 1) + 1
# define NO e->position - (MAP_X + 1) - 1
# define SO e->position + (MAP_X + 1) - 1
# define SE e->position + (MAP_X + 1) + 1
# define S e->position + (MAP_X + 1)
# define E e->position + 1
# define O e->position - 1
# define P e->position

# include "../libft/libft.h"
# include "struct.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/msg.h>
# include <SDL2/SDL.h>

void	ft_signal();
int		ft_select_sdl_or_shell(int ac, char **av);
void	ft_send_msg(char *message);
char	*ft_receive_msg();
void	ft_init_struct(t_st *e);
void	ft_delete_all_shared();
int		ft_random(int min, int max);
void	ft_block_access(t_st *e);
void	ft_restore_access(t_st *e);
int		ft_count_nbr_of_player_on_map(char *shm);

void	ft_get_or_create_shmid(t_st *e);
void	ft_get_neighbour(t_st *e);
char	*ft_get_shm(t_st *e);
int		ft_get_x(int pos);
int		ft_get_y(int pos);
int		ft_get_near_enemy(t_st *e, int pos);
int		ft_get_near_team(t_st *e, int pos);
int		ft_get_far_team(t_st *e, int pos);
int		ft_get_distance(t_st *e, int pos);

void	ft_move(t_st *e);
void	ft_escape(t_st *e);
void	ft_move_player(t_st *e, int pos);
void	ft_move_one(t_st *e, int enemy);
void	ft_move_two(t_st *e, int enemy);
void	ft_move_player_on_map(t_st *e);
void	ft_move_player_on_map_algo(t_st *e, int pos);
void	ft_move_player_on_map_by_index(t_st *e, int new_pos);
void	ft_move_player_on_map_by_random(t_st *e);

void	ft_insert_player_in_map(t_st *e);
int		ft_insert_in_map(t_st *e);
int		ft_insert_in_map_after(t_st *e, int pos);

char	*ft_create_map();
void	ft_create_shm_with_str(int shmid, char *str);
int		ft_create_shm(t_st *e, char *content);

void	ft_check_team_arround(t_st *e, int team);
void	ft_check_user_error(int ac, char **av);
int		ft_check_if_is_dead(t_st *e, int pos);
int		ft_check_if_one_near_is_dead(t_st *e);
int		ft_check_if_team_have_win(char *shm);

void	ft_put_shm(t_st *e);
void	ft_putstrc(int color, int background, char *str);
void	ft_putcharc(int color, int background, char str);
void	ft_add_player_on_map_by_index(t_st *e, int new_pos);

void	ft_draw_whith_shell(t_st *e);
void	ft_draw_whith_sdl(t_st *e);
void	ft_draw_img_renderer(SDL_Renderer *renderer, SDL_Surface *img,
								int x, int y);
void	ft_draw_score(t_st *e);
void	ft_draw_score_wait(t_st *e, int nb);
void	ft_draw_player(t_st *e);
void	ft_draw_player_shell(char **tab);
void	ft_draw_map_shell(char **tab);
void	ft_draw_player_2_shell(char **tab, int i, int j);
void	ft_draw_player_on_map_shell(t_st *e, int nb);
void	ft_draw_player_select(t_st *e, int l, int j, int i);

#endif
