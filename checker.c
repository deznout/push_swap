/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:21:09 by hbrent            #+#    #+#             */
/*   Updated: 2021/09/13 21:21:18 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotates(t_stack *st, char *line)
{
	if (ft_strncmp(line, "rra", 3) == 0)
		reverse_rot_opera(&st->A);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		reverse_rot_opera(&st->B);
	else if (ft_strncmp(line, "rrr", 3) == 0)
	{
		reverse_rot_opera(&st->A);
		reverse_rot_opera(&st->B);
	}
	else if (ft_strncmp(line, "rb", 2) == 0)
		rot_opera(&st->B);
	else if (ft_strncmp(line, "ra", 2) == 0)
		rot_opera(&st->A);
	else if (ft_strncmp(line, "rr", 2) == 0)
	{
		rot_opera(&st->A);
		rot_opera(&st->B);
	}
}

int	make_lst_opers(t_stack *st, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		swap_opera(&st->A);
	else if (ft_strncmp(line, "sb", 2) == 0)
		swap_opera(&st->B);
	else if (ft_strncmp(line, "ss", 2) == 0)
	{
		swap_opera(&st->A);
		swap_opera(&st->B);
	}
	else if (ft_strncmp(line, "pa", 2) == 0)
		push_operaA(st);
	else if (ft_strncmp(line, "pb", 2) == 0)
		push_operaB(st);
	else if (ft_strncmp(line, "rb", 2) == 0)
		rot_opera(&st->B);
	else if (*line == 'r')
		rotates(st, line);
	else
		return (1);
	return (0);
}

void	checker(t_stack *st)
{
	char	*line;

	line = NULL;
	if (check_stc(st->A))
		return ;
	while (get_next_line(0, &line))
	{
		if (make_lst_opers(st, line))
			error_message();
		free(line);
	}
	free(line);
	if (check_stc(st->A))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	stk;

	stk.A = NULL;
	stk.B = NULL;
	if (argc < 2)
		exit(0);
	init_stk(argv, &stk.A);
	checker(&stk);
	return (0);
}
