/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:22:04 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/23 15:05:17 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*free_arr(char **arr1, char **arr2, int a, int b)
{
	if (a)
	{
		free(*arr1);
		*arr1 = NULL;
		arr1 = NULL;
	}
	if (b && *arr2)
	{
		free(*arr2);
		*arr2 = NULL;
		arr2 = NULL;
	}
	return (NULL);
}

char	*put_in_stash(int fd, char *stash, char *buf)
{
	int			char_read;
	char		*temp;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 0)
		return (free_arr(&buf, &stash, 1, 1));
	if (stash == NULL)
		stash = ft_strdup("");
	char_read = 1;
	while (char_read)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1 || (char_read == 0 && !*stash))
			return (free_arr(&buf, &stash, 1, 1));
		buf[char_read] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (stash);
}

char	*make_line(char **stash_adr)
{
	int		len;
	char	*line;
	char	*stash;

	stash = *stash_adr;
	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] != '\n' && stash[len] != '\0')
		len++;
	if (stash[len] == '\0')
	{
		line = ft_strdup(stash);
		free_arr(&line, stash_adr, 0, 1);
	}
	else
	{
		line = (char *)malloc(sizeof(char) * (len + 2));
		if (!line)
			return (NULL);
		ft_strlcpy(line, stash, len + 1);
		line[len] = '\n';
		line[len + 1] = '\0';
	}
	return (line);
}

char	*remove_line_from_stash(char *stash, char *line)
{
	char	*temp;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	temp = (char *)malloc(sizeof(char *) * (
				ft_strlen(stash) - ft_strlen(line) + 1));
	if (!temp)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	i = ft_strlen(line);
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free(stash);
	if (!*temp)
	{
		free(temp);
		temp = NULL;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	stash = put_in_stash(fd, stash, buf);
	line = make_line(&stash);
	stash = remove_line_from_stash(stash, line);
	return (line);
}
// # include <stdio.h>
// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	/* line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line); */
// 	close(fd);
// 	return (0);
// }
