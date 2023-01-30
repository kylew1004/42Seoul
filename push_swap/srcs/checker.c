/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:26:45 by klew              #+#    #+#             */
/*   Updated: 2022/11/13 17:16:03 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		do_op(a, b, (const char *)line, 0);
		free(line);
	}
	free(line);
	if (is_sorted(a) && !b->top)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	init_stack(&a);
	init_stack(&b);
	i = 0;
	while (++i < argc)
	{
		if (!*argv[i])
			handle_error();
		while (*argv[i])
			argv[i] = get_values(&a, argv[i]);
	}
	checker(&a, &b);
	return (0);
}
