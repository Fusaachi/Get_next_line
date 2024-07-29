/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:11:13 by pgiroux           #+#    #+#             */
/*   Updated: 2024/07/29 11:23:05 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			nboc;

	nboc = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (NULL);
	str = ft_init("");
	str = ft_strjoin(str, buffer);
	while (nboc > 0 && ft_check(buffer) == -1)
	{
		nboc = read(fd, buffer, BUFFER_SIZE);
		if (buffer[0] == '\0')
			return (free(str), NULL);
		else if (nboc == -1)
			return (str);
		buffer[nboc] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (ft_clearbuffer(buffer, ft_check(buffer)), str);
}

// int main(void)
// {
// 	int fd;
// 	int nb_read;
// 	char *str;
// 	nb_read = 5;
// 	fd = open("test.txt", O_RDONLY);
// 	while (nb_read > 0)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s",str);
// 		free(str);
// 		nb_read--;
// 	}
// 	close(fd);
// 	return (0);
// }