/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:27:32 by klew              #+#    #+#             */
/*   Updated: 2022/11/15 12:50:35 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*getnode(t_node *next, int elem)
{
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	ptr->elem = elem;
	ptr->next = next;
	return (ptr);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->max[0] = INTG_MIN;
	stack->min = INTG_MAX;
	stack->cnt = 0;
}

void	free_stack(t_stack *stack)
{
	t_node	*ptr;
	t_node	*tmp;

	ptr = stack->top;
	if (!ptr)
		return ;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free(ptr);
}

void	add_node(t_stack *stack, int elem)
{
	t_node	*ptr;

	ptr = getnode(stack->top, elem);
	if (!ptr)
		handle_error();
	ptr->next = stack->top;
	stack->top = ptr;
	if (elem > stack->max[0])
		stack->max[0] = elem;
	if (elem < stack->min)
		stack->min = elem;
	stack->cnt++;
}

int	remove_node(t_stack *stack)
{
	int		ret;
	t_node	*ptr;

	ptr = stack->top;
	ret = ptr->elem;
	stack->top = stack->top->next;
	free(ptr);
	stack->cnt--;
	return (ret);
}
