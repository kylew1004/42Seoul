/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:27:28 by klew              #+#    #+#             */
/*   Updated: 2022/11/13 18:19:58 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = a->top->elem;
	second = a->top->next->elem;
	third = a->top->next->next->elem;
	if (first > second && second > third && first > third)
	{
		do_op(a, b, "sa", 1);
		do_op(a, b, "rra", 1);
	}
	else if (first < second && second > third && first < third)
	{
		do_op(a, b, "rra", 1);
		do_op(a, b, "sa", 1);
	}
	else if (first > second && second < third && first < third)
		do_op(a, b, "sa", 1);
	else if (first < second && second > third && first > third)
		do_op(a, b, "rra", 1);
	else if (first > second && second < third && first > third)
		do_op(a, b, "ra", 1);
}

void	sort_2(t_stack *a, t_stack *b)
{
	if (a->top->elem > a->top->next->elem)
		do_op(a, b, "sa", 1);
}

void	simple_sort(t_stack *a, t_stack *b)
{
	if (a->cnt == 3)
		sort_3(a, b);
	else if (a->cnt == 2)
		sort_2(a, b);
	else
		return ;
}
