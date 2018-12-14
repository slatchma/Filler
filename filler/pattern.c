/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 18:59:40 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 22:57:59 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	ft_pattern_malloc(t_filler *player)
{
	int i;

	i = 0;
	if ((player->pattern = (char**)malloc(sizeof(char*) *
					(player->pattern_dim[0] + 1))) == NULL)
		return ;
	player->pattern[player->pattern_dim[0]] = NULL;
	while (i < player->pattern_dim[0])
	{
		if ((player->pattern[i] = (char*)malloc(sizeof(char) *
					(player->pattern_dim[1] + 1))) == NULL)
			return ;
		player->pattern[i][player->pattern_dim[1]] = '\0';
		i++;
	}
}

void	ft_pattern_free(t_filler *player)
{
	int i;

	i = 0;
	while (i <= player->pattern_dim[0])
	{
		free(player->pattern[i]);
		i++;
	}
	free(player->pattern);
	player->pattern = NULL;
}

void	ft_pattern_write(t_filler *player, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		player->pattern[player->compt][i] = line[i];
		i++;
	}
	player->compt++;
	if (player->compt < player->pattern_dim[0])
	{
		player->state = 5;
	}
	else
	{
		player->compt = 0;
		player->state = 7;
	}
}
