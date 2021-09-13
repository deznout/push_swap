/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kkk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:29:59 by hbrent            #+#    #+#             */
/*   Updated: 2021/09/13 21:30:10 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"

typedef struct s_list
{
	int				number;
	int				keep_id;
	int				ra;
	int				rra;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*A;
	t_list	*B;
	int		len_A;
}	t_stack;

///parsing
int		check_input(char *str);
int		check_int(char *num);
int		check_duplicates(t_list *lst, int num);
void	error_message(void);

///libft
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_lstsize(t_list *lst);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

///utils_4_sort
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);

///operations
void	swap(t_stack *stk, char name);
void	swap_opera(t_list **stk);
void	rotate(t_stack *stk, char name);
void	rot_opera(t_list **stk);
void	reverse_rot_opera(t_list **stk);
void	reverse_rot(t_stack *stk, char name);
void	push(t_stack *stk, char name);

///sorting
void	sort_3_elem(t_stack *stk);
void	find_rotates(t_list *lst);
void	sort_4_elem(t_stack *stk);
void	sort_5_elem(t_stack *stk);
void	brazhnik_sort(t_stack *stk);
t_list	*def_min_lst(t_list *lst);
int		sorting(t_stack *stk);

///markup
int		get_markup(t_list *s);
void	set_markup(t_stack *s, int value);

///fromBtoA
void	from_b_to_a(t_stack *st);
void	push_A(t_stack *st, t_list *A, t_list *B);
void	push_operaA(t_stack *st);
void	push_operaB(t_stack *st);

///rot_actions
int		max(int a, int b);
void	do_rr(t_stack *st, t_list *A, t_list *B);
void	do_rrr(t_stack *st, t_list *A, t_list *B);
void	do_ra_rrb(t_stack *st, t_list *A, t_list *B);
void	do_rra_rb(t_stack *st, t_list *A, t_list *B);

///4checker
void	init_stk(char **argv, t_list **A);
int		check_stc(t_list *A);

#endif