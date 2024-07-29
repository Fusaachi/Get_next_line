/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:01:35 by pgiroux           #+#    #+#             */
/*   Updated: 2024/06/21 14:07:42 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>

char	*get_next_line(int fd);
char	*ft_init(char *cp);
char	*ft_strjoin(char *str, char *buffer);
int		ft_check(char *buffer);
char	*ft_clearbuffer(char *buffer, int i);
size_t	ft_strlen(const char *str);

#endif
