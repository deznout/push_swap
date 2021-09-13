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

void	sort_3_elem(t_stack *stk)
{
	if ((stk->A->number > stk->A->next->number && \
	stk->A->next->next->number > stk->A->number) || \
	(stk->A->number < stk->A->next->next->number && \
	stk->A->next->number > stk->A->next->next->number) || \
	(stk->A->number > stk->A->next->number && \
	stk->A->next->number > stk->A->next->next->number))
		swap(stk, 'A');
	if (stk->A->number > stk->A->next->number && \
	stk->A->next->number < stk->A->next->next->number)
		rotate(stk, 'A');
	if (stk->A->number < stk->A->next->number && \
	stk->A->next->next->number < stk->A->number)
		reverse_rot(stk, 'A');
}

void	sort_4_elem(t_stack *stk)
{
	t_list	*min_lst;

	find_rotates(stk->A);
	min_lst = def_min_lst(stk->A);
	if (min_lst->ra <= min_lst->rra)
		while (min_lst->ra-- > 0)
			rotate(stk, 'A');
	else
		while (min_lst->rra-- > 0)
			reverse_rot(stk, 'A');
	push(stk, 'B');
	sort_3_elem(stk);
	push(stk, 'A');
}

void	sort_5_elem(t_stack *stk)
{
	t_list	*min_lst;

	find_rotates(stk->A);
	min_lst = def_min_lst(stk->A);
	if (min_lst->ra <= min_lst->rra)
		while (min_lst->ra-- > 0)
			rotate(stk, 'A');
	else
		while (min_lst->rra-- > 0)
			reverse_rot(stk, 'A');
	push(stk, 'B');
	sort_4_elem(stk);
	push(stk, 'A');
}

void	from_a_to_b(t_stack *st)
{
	while (st->len_A--)
	{
		if (st->A->keep_id != 1)
			push(st, 'B');
		else
			rotate(st, 'A');
	}
}

void	brazhnik_sort(t_stack *stk)
{
	int	tmp;
	int	value;
	int	max_posit;
	int	len;

	max_posit = 0;
	len = stk->len_A;
	while (len--)
	{
		tmp = get_markup(stk->A);
		if (tmp > max_posit)
		{
			max_posit = tmp;
			value = stk->A->number;
		}
		rot_opera(&stk->A);
	}
	set_markup(stk, value);
	from_a_to_b(stk);
	from_b_to_a(stk);
}
