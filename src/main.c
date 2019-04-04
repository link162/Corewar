/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:11:07 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/04 19:46:03 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	heroes_to_null(t_cor *cor)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		cor->heroes[i].name = NULL;
		cor->heroes[i].file = NULL;
		cor->heroes[i].comment = NULL;
		cor->heroes[i].code = NULL;
		cor->heroes[i].live = 0;
		cor->heroes[i].last_live = 0;
		i++;
	}
}

void	map_init(t_cor *cor)
{
	ft_memset(cor->stage, 0, MEM_SIZE);
	heroes_to_null(cor);
	cor->cycles = 0;
	cor->count_heroes = 0;
	cor->visual = 0;
	cor->dump_cycle = -2;
	cor->list = NULL;
	cor->cursor = NULL;
	cor->cursors = 0;
	cor->check_in = 0;
	cor->live_in = 0;
	cor->log = 0;
	cor->cycles_to_die = CYCLE_TO_DIE;
}

int		main(int argc, char **argv)
{
	t_cor cor;

	map_init(&cor);
	read_flags(&cor, argc, argv);
	validate_heroes(&cor);
	init_game(&cor);
	print_players(&cor);
	full_game(&cor);
	print_last_alive(&cor);
	init_win(&cor);
	update_arena(&cor);
	dinit_win();
}
