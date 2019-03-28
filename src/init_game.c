/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:28:58 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/28 18:10:25 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_game(t_cor *cor)
{
	int			id;
	uint32_t	pc;

	ft_memset(cor->stage, 0, MEM_SIZE);
	id = 0;
	pc = 0;
	while (id < cor->count_heroes)
	{
	ft_printf("hello\n");
		ft_memcpy(&(cor->stage[pc]),
			cor->heroes[id].code,
			(size_t)(cor->heroes[id].size));
		pc += MEM_SIZE / cor->count_heroes;
		id++;
	}
}
