/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kkk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:29:59 by hbrent            #+#    #+#             */
/*   Updated: 2021/09/13 21:30:10 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = ((char *)s)[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*res;
	size_t	lenS1;
	size_t	lenS2;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	lenS1 = ft_strlen(s1);
	lenS2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (lenS1 + lenS2 + 1));
	if (!res)
		return (NULL);
	while (i < lenS1)
	{
		res[i] = s1[i];
		i++;
	}
	while (k < lenS2)
		res[i++] = s2[k++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
