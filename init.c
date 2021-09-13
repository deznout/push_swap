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

void	init_stk(char **argv, t_list **A)
{
	char	**splitted;
	int		i;
	int		j;
	int		num;

	i = 1;
	while (argv[i])
	{
		j = -1;
		splitted = ft_split(argv[i++], ' ');
		while (splitted[++j])
		{
			if (check_input(splitted[j]) && check_int(splitted[j]))
			{
				num = (int)ft_atoi(splitted[j]);
				if (check_duplicates(*A, num))
					error_message();
				ft_lstadd_back(A, ft_lstnew(num));
			}
			else
				error_message();
			free(splitted[j]);
		}
		free(splitted);
	}
}

int	check_stc(t_list *A)
{
	if (!A || !A->next)
		return (1);
	while (A->next)
	{
		if (A->number < A->next->number)
			A = A->next;
		else
			return (0);
	}
	return (1);
}

int	sorting(t_stack *stk)
{
	stk->len_A = ft_lstsize(stk->A);
	if (stk->len_A == 2)
		swap(stk, 'A');
	else if (stk->len_A == 3)
		sort_3_elem(stk);
	else if (stk->len_A == 4)
		sort_4_elem(stk);
	else if (stk->len_A == 5)
		sort_5_elem(stk);
	else
		brazhnik_sort(stk);
	return (0);
}
