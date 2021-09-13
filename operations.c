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

void	swap_opera(t_list **stk)
{
	int	tmp;

	if ((*stk)->next)
	{
		tmp = (*stk)->number;
		(*stk)->number = (*stk)->next->number;
		(*stk)->next->number = tmp;
	}
}

void	swap(t_stack *stk, char name)
{
	if (name == 'A')
	{
		swap_opera(&stk->A);
		write(1, "sa\n", 3);
	}
	if (name == 'B')
	{
		swap_opera(&stk->B);
		write(1, "sb\n", 3);
	}
	if (name == 'S')
	{
		swap_opera(&stk->A);
		swap_opera(&stk->B);
		write(1, "ss\n", 3);
	}
}

void	rot_opera(t_list **stk)
{
	t_list	*tmp;

	tmp = *stk;
	*stk = (*stk)->next;
	tmp->next = NULL;
	ft_lstadd_back(stk, tmp);
}

void	rotate(t_stack *stk, char name)
{
	if (name == 'A')
	{
		rot_opera(&stk->A);
		write(1, "ra\n", 3);
	}
	if (name == 'B')
	{
		rot_opera(&stk->B);
		write(1, "rb\n", 3);
	}
	if (name == 'S')
	{
		rot_opera(&stk->A);
		rot_opera(&stk->B);
		write(1, "rr\n", 3);
	}
}

void	reverse_rot_opera(t_list **stk)
{
	t_list	*last;
	t_list	*prelast;

	prelast = *stk;
	if (*stk && (*stk)->next)
	{
		while (prelast->next->next)
			prelast = prelast->next;
		last = prelast->next;
		prelast->next = NULL;
		ft_lstadd_front(stk, last);
	}
}
