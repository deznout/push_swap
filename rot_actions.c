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

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	do_rr(t_stack *st, t_list *A, t_list *B)
{
	while (A->ra > 0 && B->ra > 0)
	{
		rotate(st, 'S');
		A->ra--;
		B->ra--;
	}
	while (A->ra--)
		rotate(st, 'A');
	if (st->B == 0)
		st->B = B;
	while (B->ra--)
		rotate(st, 'B');
}

void	do_rrr(t_stack *st, t_list *A, t_list *B)
{
	while (A->rra > 0 && B->rra > 0)
	{
		reverse_rot(st, 'S');
		A->rra--;
		B->rra--;
	}
	while (A->rra--)
		reverse_rot(st, 'A');
	while (B->rra--)
		reverse_rot(st, 'B');
}

void	do_ra_rrb(t_stack *st, t_list *A, t_list *B)
{
	while (A->ra--)
		rotate(st, 'A');
	while (B->rra--)
		reverse_rot(st, 'B');
}

void	do_rra_rb(t_stack *st, t_list *A, t_list *B)
{
	while (A->rra--)
		reverse_rot(st, 'A');
	while (B->ra--)
		rotate(st, 'B');
}
