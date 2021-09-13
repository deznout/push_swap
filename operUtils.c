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

void	reverse_rot(t_stack *stk, char name)
{
	if (name == 'A')
	{
		reverse_rot_opera(&stk->A);
		write(1, "rra\n", 4);
	}
	if (name == 'B')
	{
		reverse_rot_opera(&stk->B);
		write(1, "rrb\n", 4);
	}
	if (name == 'S')
	{
		reverse_rot_opera(&stk->A);
		reverse_rot_opera(&stk->B);
		write(1, "rrr\n", 4);
	}
}

t_list	*def_min_lst(t_list *lst)
{
	t_list	*min;

	min = lst;
	while (lst)
	{
		if (lst->number < min->number)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

void	push_operaA(t_stack *st)
{
	t_list	*tmp;

	tmp = st->B;
	st->B = st->B->next;
	tmp->next = NULL;
	ft_lstadd_front(&st->A, tmp);
}

void	push_operaB(t_stack *st)
{
	t_list	*tmp;

	tmp = st->A;
	st->A = st->A->next;
	tmp->next = NULL;
	ft_lstadd_front(&st->B, tmp);
}

void	push(t_stack *stk, char name)
{
	if (name == 'A')
	{
		push_operaA(stk);
		write(1, "pa\n", 3);
	}
	if (name == 'B')
	{
		push_operaB(stk);
		write(1, "pb\n", 3);
	}
}
