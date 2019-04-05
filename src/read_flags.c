/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:42:51 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/05 13:42:17 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visual_flag(t_cor *cor, int *i)
{
	cor->visual = 1;
	(*i)++;
}

void	dump_flag(t_cor *cor, int *i, int argc, char **argv)
{
	if (cor->dump_cycle == -2 && *i + 1 < argc)
	{
		(*i)++;
		cor->dump_cycle = mod_atoi(argv[*i]);
		if (cor->dump_cycle < 0)
			cor->dump_cycle = -1;
		(*i)++;
	}
	else
		error_case(USAGE);
}

void	num_flag(t_cor *cor, int *i, int argc, char **argv)
{
	int		z;
	t_files	*list;

	if (*i + 2 >= argc)
		error_case(USAGE);
	(*i)++;
	z = mod_atoi(argv[*i]);
	if (z < 1 || z > MAX_PLAYERS || is_filename(argv[++(*i)]))
		error_case(USAGE);
	if (!cor->list)
		cor->list = create_list(z, argv[*i]);
	else
	{
		list = cor->list;
		while (list->next)
			list = list->next;
		list->next = create_list(z, argv[*i]);
	}
	(*i)++;
}

void	log_flag(t_cor *cor, int *i, int argc, char **argv)
{
	int z;

	if (*i + 1 >= argc)
		error_case(USAGE);
	(*i)++;
	z = mod_atoi(argv[*i]);
	if (z == 1 || z == 2 || z == 4 || z == 8)
		cor->log = z;
	else
		error_case(USAGE);
	(*i)++;
}

void	read_flags(t_cor *cor, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-v"))
			visual_flag(cor, &i);
		else if (!ft_strcmp(argv[i], "-dump") || !ft_strcmp(argv[i], "-d"))
			dump_flag(cor, &i, argc, argv);
		else if (!ft_strcmp(argv[i], "-n"))
			num_flag(cor, &i, argc, argv);
		else if (!ft_strcmp(argv[i], "-l"))
			log_flag(cor, &i, argc, argv);
		else if (!ft_strcmp(argv[i], "-a"))
		{
			cor->aff = 1;
			i++;
		}
		else if (!is_filename(argv[i]))
			add_file(cor, &i, argv);
		else
			error_case(USAGE);
	}
	set_players(cor);
}
