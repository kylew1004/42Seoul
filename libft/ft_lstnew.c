/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:01 by klew              #+#    #+#             */
/*   Updated: 2022/04/22 19:01:05 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*address;

	address = (t_list *)malloc(sizeof(t_list));
	if (!(address))
		return (NULL);
	address->next = NULL;
	address->content = content;
	return (address);
}
