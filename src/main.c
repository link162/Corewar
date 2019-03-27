/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:11:07 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/27 21:12:35 by ybuhai           ###   ########.fr       */
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
		ft_printf("Hero %i file %s\nname \"%s\"\ncomment (\"%s\")\nsize %i\n\n\n", i + 1, cor->heroes[i].file, cor->heroes[i].name, cor->heroes[i].comment, cor->heroes[i].size);
}

int		main(int argc, char **argv)
{
	t_cor cor;

	map_init(&cor);
	read_flags(&cor, argc, argv);
	validate_heroes(&cor);
	print_data(&cor);
	system("leaks corewar");
}
