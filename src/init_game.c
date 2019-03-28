/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:28:58 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/28 21:02:46 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cursor	*create_cursor(t_cor *cor, int id, int pos)
{
	t_cursor		*cursor;

	if (!(cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor))))
		error_case("Memory error");
	cursor->id = id;
	cursor->carry = 0;
	cursor->last_live = 0;
	cursor->pos = pos;
	cursor->operation = 0;
	cursor->cycle_wait = 0;
	cursor->next = NULL;
	cursor->reg[0] = -(id + 1);
	return (cursor);
}

void	init_cursor(t_cor *cor)
{
	int			id;
	uint32_t	pos;
	t_cursor	*tmp;

	id = -1;
	pos = 0;
	while (++id < cor->count_heroes)
	{
		tmp = create_cursor(cor, id, pos);
		tmp->next = cor->cursor;
		cor->cursor = tmp;
		cor->cursors++;
		pos += MEM_SIZE / cor->count_heroes;
	}
}

void		init_game(t_cor *cor)
{
	int			id;
	uint32_t	pc;

	id = 0;
	pc = 0;
	while (id < cor->count_heroes)
	{
		ft_memcpy(&(cor->stage[pc]),
			cor->heroes[id].code,
			(size_t)(cor->heroes[id].size));
		pc += MEM_SIZE / cor->count_heroes;
		id++;
	}
	if (cor->visual == 1)
		cor->dump_cycle = -1;
	init_cursor(cor);
}
