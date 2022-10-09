/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javlopez <javlopez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:38:40 by javlopez          #+#    #+#             */
/*   Updated: 2022/10/02 14:33:53 by javlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char    *ft_strchr(char *s, int c);
char	*ft_strcat(char *dest, char const *src);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char *s, size_t start, size_t len);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
ssize_t	ft_read_file(char **fd_file, int fd);
char	*ft_cut_line(char **fd_file, int fd);

#endif
