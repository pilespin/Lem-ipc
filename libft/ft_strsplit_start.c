/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:43:07 by pilespin          #+#    #+#             */
/*   Updated: 2015/03/03 18:39:21 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int sp;
	int sp_tmp;

	sp_tmp = 0;
	sp = 0;
	while (*s)
	{
		if (sp_tmp == 1 && *s == c)
			sp_tmp = 0;
		if (sp_tmp == 0 && *s != c)
		{
			sp_tmp = 1;
			sp++;
		}
		s++;
	}
	return (sp);
}

char		**ft_strsplit_start(char const *s, char c, int start)
{
	int		sp;
	char	**tab;
	int		i;
	int		j;

	if ((s == 0) || (c == 0))
		return (NULL);
	sp = ft_count_words(s, c) + start;
	tab = malloc((sizeof(char *) * (sp + 1 + start)));
	i = 0;
	j = 0;
	tab[0] = ft_strdup("");
	while (++j < sp)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_strsub(s, start, i - start);
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
