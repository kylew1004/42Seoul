/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:43:49 by klew              #+#    #+#             */
/*   Updated: 2022/10/14 12:35:17 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_message_error(void)
{
	perror("Error");
	exit(1);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	size;
	char			*ptr;
	int				i;

	size = ft_strlen(s1);
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char	**get_map(char *fmap)
{
	char	*line;
	char	*all_lines;
	int		fd;

	line = "";
	all_lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		ft_message_error();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		ft_message_error();
	return (ft_split(all_lines, '\n'));
}
