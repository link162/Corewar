/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:08:35 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/30 10:47:11 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_args(t_cursor *cursor, t_cor *cor, t_operation *operation)
{
	int		i;
	int		step;

	i = 0;
	step = (1 + (operation->args_types_code ? 1 : 0));
	while (i < operation->args_num)
	{
		if ((cursor->args_types[i] == T_REG)
			&& !is_register(vm, cursor->pc, step))
			return (0);
		step += step_size(cursor->args_types[i], op);
		i++;
	}
	return (1);
}

int		validate_args(t_cursor *cursor, t_operation *operation)
{
	int i;

	i = -1;
	while (++i < operation->args_num)
		if (!(cursor->args_types[i] & operation->args_types[i]))
			return (0);
	return (1);
}

void	read_command(t_cor *cor, t_cursor *cursor, t_operation *operation)
{
	int8_t atc;

	if (operation->args_types_code)
	{
		atc = cor->stage[find_adress(cursor->pos + 1)];
		if (operation->args_num >= 1)
			cursor->args_types[0] = g_arg_code[((atc & 0xC0) >> 6) - 1];
		if (operation->args_num >= 2)
			cursor->args_types[1] = g_arg_code[((atc & 0x30) >> 4) - 1];
		if (operation->args_num >= 3)
			cursor->args_types[2] = g_arg_code[((atc & 0xC) >> 2) - 1];
	}
	else
		cursor->args_types[0] = operation->args_types[0];
}
