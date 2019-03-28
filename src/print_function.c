/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:07:31 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/28 21:13:05 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_players(t_cor *cor)
{
	int id;

	id = -1;
	ft_printf("Introducing contestants...\n");
	while (++id < cor->count_heroes)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				id + 1, cor->heroes[id].size, cor->heroes[id].name,
				cor->heroes[id].comment);
		id++;
	}
}

void	print_last_alive(t_cor *cor)
{
//	ft_printf("Contestant %d, \"%s\", has won !\n",
//													FT_ABS(vm->last_alive->id),
//													vm->last_alive->name);
}
