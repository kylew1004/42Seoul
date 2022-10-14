/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:48:07 by klew              #+#    #+#             */
/*   Updated: 2022/10/14 13:29:55 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_join_strings(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	char			*ptr;

	if (!s1)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1_len-- != 0)
		ptr[i++] = *s1++;
	while (s2_len-- != 0)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}

void	put_text(t_data ***data)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*number;

	number = ft_itoa(++(**data)->movement);
	text = ft_join_strings("Move: ", number);
	(**data)->img = mlx_xpm_file_to_image(
			(**data)->mlx, "./img/wall.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**data)->mlx, (**data)->win, (**data)->img, 0, 0);
	mlx_put_image_to_window(
		(**data)->mlx, (**data)->win, (**data)->img, 50, 0);
	mlx_put_image_to_window(
		(**data)->mlx, (**data)->win, (**data)->img, 50 * 2, 0);
	mlx_string_put((**data)->mlx, (**data)->win, 5, 10, 0xfffffff, text);
	printf("%s\n", number);
	free(text);
	free(number);
}
