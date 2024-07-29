/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:11:13 by pgiroux           #+#    #+#             */
/*   Updated: 2024/07/29 11:22:52 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer [1024][BUFFER_SIZE + 1];
	char		*str;
	int			nboc;

	nboc = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer[fd], 0) == -1)
		return (NULL);
	str = ft_init("");
	str = ft_strjoin(str, buffer[fd]);
	while (nboc > 0 && ft_check(buffer[fd]) == -1)
	{
		nboc = read(fd, buffer[fd], BUFFER_SIZE);
		if (buffer[fd][0] == '\0')
			return (free(str), NULL);
		else if (nboc == -1)
			return (str);
		buffer[fd][nboc] = '\0';
		str = ft_strjoin(str, buffer[fd]);
	}
	return (ft_clearbuffer(buffer[fd], ft_check(buffer[fd])), str);
}

// int main(void)
// {
// 	int fd1;
// 	int fd2;

// 	char *str;

// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	str = get_next_line(fd1);
// 	printf("%s",str);
// 	free(str);
// 	str = get_next_line(fd2);
// 	printf("%s",str);
// 	free(str);
// 	str = get_next_line(fd1);
// 	printf("%s",str);
// 	free(str);
// 	str = get_next_line(fd2);
// 	printf("%s",str);
// 	free(str);
// 	str = get_next_line(fd1);
// 	printf("%s",str);
// 	free(str);
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }