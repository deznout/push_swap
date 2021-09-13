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

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	check_input(char *str)
{
	int	j;

	j = 0;
	if (str[j] == '+' || str[j] == '-')
		j++;
	while (ft_isdigit(str[j]))
		j++;
	if (j && ft_isdigit(str[j - 1]) && str[j] == '\0')
		return (1);
	return (0);
}

int	check_int(char *num)
{
	if (ft_strlen(num) > 11)
		return (0);
	if (ft_atoi(num) >= -2147483648 && ft_atoi(num) <= 2147483647)
		return (1);
	return (0);
}

int	check_duplicates(t_list *lst, int num)
{
	while (lst)
	{
		if (lst->number == num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	error_message(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
