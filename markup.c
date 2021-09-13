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

int	get_markup(t_list *s)
{
	int		count;
	t_list	*prev;

	count = 1;
	prev = s;
	s = s->next;
	if (s)
	{
		while (s->next)
		{
			if (prev->number < s->number)
			{
				count++;
				prev = s;
			}
			s = s->next;
		}
		if (prev->number < s->number)
			count++;
	}
	return (count);
}

int	get_id(t_list *s, int val)
{
	int	i;

	i = 0;
	while (s->number != val)
	{
		i++;
		s = s->next;
	}
	return (i);
}

void	set_id(t_list *s, t_list *prev)
{
	while (s->next)
	{
		if (prev->number < s->number)
		{
			prev = s;
			s->keep_id = 1;
		}
		s = s->next;
	}
	if (prev->number < s->number)
		s->keep_id = 1;
}

void	set_markup(t_stack *s, int value)
{
	int		id;
	int		tmp;
	t_list	*lstmp;
	t_list	*prev;

	id = get_id(s->A, value);
	tmp = s->len_A - id;
	while (tmp--)
		reverse_rot_opera(&s->A);
	tmp = s->len_A - id;
	prev = s->A;
	prev->keep_id = 1;
	lstmp = s->A->next;
	if (lstmp)
		set_id(lstmp, prev);
	while (tmp--)
		rot_opera(&s->A);
}

void	push_A(t_stack *st, t_list *A, t_list *B)
{
	int	rr;
	int	rrr;
	int	ra_rrb;
	int	rra_rb;

	rr = max(A->ra, B->ra);
	rrr = max(A->rra, B->rra);
	ra_rrb = A->ra + B->rra;
	rra_rb = A->rra + B->ra;
	if (rr <= rrr && rr <= ra_rrb && rr <= rra_rb)
		do_rr(st, A, B);
	else if (rrr <= rr && rrr <= ra_rrb && rrr <= rra_rb)
		do_rrr(st, A, B);
	else if (ra_rrb <= rr && ra_rrb <= rrr && ra_rrb <= rra_rb)
		do_ra_rrb(st, A, B);
	else if (rra_rb <= rr && rra_rb <= rrr && rra_rb <= ra_rrb)
		do_rra_rb(st, A, B);
	push(st, 'A');
}
