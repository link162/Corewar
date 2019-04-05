/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:11:07 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/05 14:03:24 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_case(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

int		main(int argc, char **argv)
{
	t_cor cor;

	ft_bzero(&cor, sizeof(t_cor));
	cor.dump_cycle = -2;
	cor.cycles_to_die = CYCLE_TO_DIE;
	read_flags(&cor, argc, argv);
	validate_heroes(&cor);
	init_game(&cor);
	print_players(&cor);
	if (cor.visual == 1)
		init_win(&cor);
	full_game(&cor);
	print_last_alive(&cor);
}
