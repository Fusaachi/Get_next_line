/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:13:20 by pgiroux           #+#    #+#             */
/*   Updated: 2024/07/29 11:22:46 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"

char	*ft_init(char *cp)
{
	char	*str;
	int		i;

	i = 0;
	while (cp[i] != '\0' && cp[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (cp[i] != '\0' && cp[i] != '\n')
	{
		str[i] = cp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buffer)
{
	int		i;
	int		j;
	int		len;
	char	*newstr;

	if (!str || !buffer)
		return (NULL);
	len = ft_strlen(str) + ft_strlen(buffer);
	newstr = malloc(sizeof(char) * (len + 2));
	if (!newstr)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	j = 0;
	while (buffer[j] != '\0' && buffer[j] != '\n')
		newstr[i++] = buffer[j++];
	if (buffer[j] == '\n' )
		newstr[i++] = '\n';
	newstr[i] = '\0';
	return (free(str), newstr);
}

int	ft_check(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_clearbuffer(char *buffer, int i)
{
	int		j;
	int		itemp;
	int		len;
	char	*temp;

	i += 1;
	len = 0;
	j = 0;
	itemp = i;
	while (buffer[itemp++] != '\0')
		len++;
	temp = malloc(sizeof(char) * (len + 1));
	while (buffer[i] != '\0')
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	i = 0;
	while (temp[i] != '\0')
	{
		buffer[i] = temp[i];
		i++;
	}
	buffer[i] = '\0';
	return (free(temp), buffer);
}
