/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:11:07 by ybuhai            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/03/28 17:39:03 by ybuhai           ###   ########.fr       */
=======
/*   Updated: 2019/03/28 15:27:41 by akorobov         ###   ########.fr       */
>>>>>>> fdcbad4ff5d471abed2bfdc87ba88836091e71a7
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
		i++;
	}
}

void	map_init(t_cor *cor)
{
	cor->count_heroes = 0;
	cor->visual = 0;
	cor->dump_cycle = -2;
	cor->list = NULL;
	heroes_to_null(cor);
}

void		print_arena(uint8_t *arena, int print_mode)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.4p : ", i);
		j = 0;
		while (j < print_mode)
		{
			ft_printf("%.2x ", arena[i + j]);
			j++;
		}
		ft_printf("\n");
		i += print_mode;
	}
}

void	print_data(t_cor *cor)
{
	int i;

	if (cor->visual)
		ft_printf("Visual\n");
	if (cor->dump_cycle >= 0)
		ft_printf("Dump after %i cycles\n", cor->dump_cycle);
	ft_printf("%i heroes\n", cor->count_heroes);
	i = -1;
	while (++i < cor->count_heroes)
		ft_printf("Hero %i file %s\nname \"%s\"\ncomment (\"%s\")\nsize %i\n\n\n\n", i + 1, cor->heroes[i].file, cor->heroes[i].name, cor->heroes[i].comment, cor->heroes[i].size);
<<<<<<< HEAD
	print_arena(cor->stage, 32);
=======
	ft_memset(cor->stage, 0, MEM_SIZE);
//	print_arena(cor->stage, 32);
>>>>>>> fdcbad4ff5d471abed2bfdc87ba88836091e71a7
}

int		main(int argc, char **argv)
{
	t_cor cor;

	map_init(&cor);
	read_flags(&cor, argc, argv);
	validate_heroes(&cor);
<<<<<<< HEAD
	init_game(&cor);
//	init_win(&cor);
//	dinit_win();
	print_data(&cor);
=======
	print_data(&cor);
	init_win(&cor);
	update_arena(&cor);
	dinit_win();
>>>>>>> fdcbad4ff5d471abed2bfdc87ba88836091e71a7
	system("leaks corewar");
}
