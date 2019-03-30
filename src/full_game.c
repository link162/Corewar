/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:38:17 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/29 16:29:53 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_operation(t_cor *cor, t_cursor *cursor)
{
	cursor->operation = cor->stage[cursor->pos];
	if (cor->stage[cursor->pos] >= 0x01 && cor->stage[cursor->pos] <= 0x10)
		cursor->cycle_wait = g_op[cursor->operation - 1].cycles;
}

void	check_cursor(t_cursor *cursor, t_cor *cor)
{
	t_operation	*new;

	if (!cursor->cycle_wait)
		set_operation(cor, cursor);
	if (cursor->cycle_wait > 0)
		cursor->cycle_wait--;
	if (!cursor->cycle_wait)
	{
		new = NULL;
		if (cursor->operation >= 0x01 && cursor->operation <= 0x10)
			new = &g_op[cursor->operation - 1];
		if (new)
		{
			read_command(cor, cursor, new);
	/*		if (is_arg_types_valid(cursor, op) && is_args_valid(cursor, vm, op))
				new->func(cor, cursor);
			else
				cursor->step += calc_step(cursor, op);*/
		}
		else
			cursor->step = 1;
	}
//		move_cursor(vm, cursor);
}

void	run_cycle(t_cor *cor)
{
	t_cursor *tmp;

	cor->cycles++;
	cor->cycles_after_check++;
	tmp = cor->cursor;
	while (tmp)
	{
		check_cursor(tmp, cor);
		tmp = tmp->next;
	}
}

void	check_who_die(t_cor *cor)
{
	
}

void	full_game(t_cor *cor)
{
	while (cor->cursors)
	{
		if (cor->dump_cycle == cor->cycles)
		{
			print_arena(cor);
			exit(1);
		}
		run_cycle(cor);
		if (cor->cycles_to_die == cor->cycles_after_check ||
				cor->cycles_to_die <= 0)
			check_who_die(cor);
		cor->cursors--;
	}
}
