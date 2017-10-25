/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemipc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 15:05:01 by pilespin          #+#    #+#             */
/*   Updated: 2015/09/17 22:41:39 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/project.h"

void	ft_draw_player_select(t_st *e, int l, int j, int i)
{
	if (e->shm[i] == 49)
		ft_draw_img_renderer(e->rend, e->img->mer, (l * PL_SZ) - PL_SZ, j);
	else if (e->shm[i] == 50)
		ft_draw_img_renderer(e->rend, e->img->ven, (l * PL_SZ) - PL_SZ, j);
	else if (e->shm[i] == 51)
		ft_draw_img_renderer(e->rend, e->img->ter, (l * PL_SZ) - PL_SZ, j);
	else if (e->shm[i] == 52)
		ft_draw_img_renderer(e->rend, e->img->mar, (l * PL_SZ) - PL_SZ, j);
	else if (e->shm[i] == 53)
		ft_draw_img_renderer(e->rend, e->img->jup, (l * PL_SZ) - PL_SZ, j);
	else if (e->shm[i] == 54)
		ft_draw_img_renderer(e->rend, e->img->sat, (l * PL_SZ) - PL_SZ, j);
	else if (e->shm[i] == 55)
		ft_draw_img_renderer(e->rend, e->img->ura, (l * PL_SZ) - PL_SZ, j);
	else if (e->shm[i] == 56)
		ft_draw_img_renderer(e->rend, e->img->nep, (l * PL_SZ) - PL_SZ, j);
	else if (e->shm[i] == 57)
		ft_draw_img_renderer(e->rend, e->img->plu, (l * PL_SZ) - PL_SZ, j);
}

void	ft_draw_whith_sdl(t_st *e)
{
	SDL_Window		*screen;
	SDL_Event		user_event;

	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_CreateWindow("Lem-IPC", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOW_X, SDL_WINDOW_Y,
			SDL_WINDOW_SHOWN);
	e->rend = SDL_CreateRenderer(screen, -1,
			SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(e->rend, 19, 43, 68, 255);
	while (1)
	{
		if (SDL_PollEvent(&user_event))
		{
			if ((user_event.type == SDL_KEYDOWN &&
						user_event.key.keysym.sym == SDLK_ESCAPE) ||
					user_event.type == SDL_QUIT)
				ft_signal(e);
		}
		ft_draw_player(e);
		ft_draw_score(e);
	}
	SDL_DestroyWindow(screen);
	SDL_Quit();
}

void	ft_draw_img_renderer(SDL_Renderer *renderer, SDL_Surface *img,
		int x, int y)
{
	SDL_Texture	*texture;
	SDL_Rect	dest;

	texture = SDL_CreateTextureFromSurface(renderer, img);
	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(renderer, texture, NULL, &dest);
	SDL_DestroyTexture(texture);
}

void	ft_draw_player(t_st *e)
{
	int	i;
	int	j;
	int	k;
	int	l;

	SDL_RenderClear(e->rend);
	i = -1;
	k = 0;
	j = 0;
	l = 1;
	while (e->shm[++i])
	{
		if (k++ >= MAP_X)
		{
			j += PL_SZ;
			k = 0;
			l = 0;
		}
		if (e->shm[i] >= 49 && e->shm[i] <= 57)
			ft_draw_player_select(e, l, j, i);
		l++;
	}
	SDL_RenderPresent(e->rend);
}

void	ft_init_struct(t_st *e)
{
	e->key = KEY;
	e->time_start = 0;
	e->tim = 0;
	e->min_player_reached = 0;
	e->img = (t_img *)malloc(sizeof(t_img));
	e->img->mer = SDL_LoadBMP("img/mer.bmp");
	e->img->ven = SDL_LoadBMP("img/ven.bmp");
	e->img->ter = SDL_LoadBMP("img/ter.bmp");
	e->img->mar = SDL_LoadBMP("img/mar.bmp");
	e->img->jup = SDL_LoadBMP("img/jup.bmp");
	e->img->sat = SDL_LoadBMP("img/sat.bmp");
	e->img->ura = SDL_LoadBMP("img/ura.bmp");
	e->img->nep = SDL_LoadBMP("img/nep.bmp");
	e->img->plu = SDL_LoadBMP("img/plu.bmp");
}
