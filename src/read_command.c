/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:08:35 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/30 09:08:36 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
			operation->args_types[0] = g_arg_code[((atc & 0xC0) >> 6) - 1];
		if (operation->args_num >= 2)
			operation->args_types[1] = g_arg_code[((atc & 0x30) >> 4) - 1];
		if (operation->args_num >= 3)
			operation->args_types[2] = g_arg_code[((atc & 0xC) >> 2) - 1];
	}
	else
		operation->args_types[0] = operation->args_types[0];
}
