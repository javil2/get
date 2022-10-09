/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javlopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:31:11 by javlopez          #+#    #+#             */
/*   Updated: 2022/10/02 14:38:10 by javlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (*(str + n) != '\0')
		n++;
	return (n);
}

char	*ft_strchr(char *s, int c)
{
	char	*r;

	r = s;
	while (*r)
	{
		if (*r == (char)c)
			return (r);
		r++;
	}
	if (c == 0 || (char)c == '\0')
		return (r);
	return (NULL);
}

char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	j;

	i = 0;
	while ((*(dest + i)) != '\0')
	{
		i++;
	}
	j = 0;
	while ((*(src + j)) != '\0')
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	*(dest + i + j) = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*sum;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	sum = (char *)malloc((i + j + 1) * sizeof(char));
	if (!sum)
		return (NULL);
	sum[0] = '\0';
	sum = ft_strcat(sum, s1);
	sum = ft_strcat(sum, s2);
	/* ft_strlcpy (sum, s1, i + j + 1);
	ft_strlcat (sum, s2, i + j + 1); */
	free ((void *)s1);
	return (sum);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
