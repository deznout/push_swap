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

int	minarr(int min, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	free(arr);
	return (min);
}

t_list	*find_suitable_num(t_list *a, t_list *b, int len)
{
	t_list	*minlst;
	int		*greatvals;
	int		i;
	int		min;

	greatvals = malloc(sizeof(int) * len);
	minlst = a;
	i = len;
	while (i--)
		greatvals[i] = 2147483647;
	while (a)
	{
		if (a->number > b->number)
			greatvals[++i] = a->number;
		a = a->next;
	}
	a = minlst;
	min = minarr(greatvals[0], greatvals, len);
	while (a)
	{
		if (a->number == min)
			minlst = a;
		a = a->next;
	}
	return (minlst);
}

int	count_num_oper(t_list *suit, t_list *b)
{
	int	rr;
	int	rrr;
	int	ra_rrb;
	int	rra_rb;

	rr = max(suit->ra, b->ra);
	rrr = max(suit->rra, b->rra);
	ra_rrb = suit->ra + b->rra;
	rra_rb = suit->rra + b->ra;
	if (rr <= rrr && rr <= ra_rrb && rr <= rra_rb)
		return (rr);
	if (rrr <= rr && rrr <= ra_rrb && rrr <= rra_rb)
		return (rrr);
	if (ra_rrb <= rr && ra_rrb <= rrr && ra_rrb <= rra_rb)
		return (ra_rrb);
	return (rra_rb);
}

void	find_optim_actions(t_stack *st)
{
	t_list	*suit_num;
	t_list	*headB;
	t_list	*minA;
	t_list	*minB;
	int		min;

	min = 2147483647;
	headB = st->B;
	while (st->B)
	{
		suit_num = find_suitable_num(st->A, st->B, ft_lstsize(st->A));
		if (min > count_num_oper(suit_num, st->B))
		{
			minA = suit_num;
			minB = st->B;
			min = count_num_oper(suit_num, st->B);
		}
		st->B = st->B->next;
	}
	st->B = headB;
	push_A(st, minA, minB);
}

void	from_b_to_a(t_stack *st)
{
	t_list	*minlst;

	while (st->B)
	{
		find_rotates(st->A);
		find_rotates(st->B);
		find_optim_actions(st);
	}
	find_rotates(st->A);
	minlst = def_min_lst(st->A);
	if (minlst->ra < minlst->rra)
		while (minlst->ra--)
			rotate(st, 'A');
	else
		while (minlst->rra--)
			reverse_rot(st, 'A');
}
