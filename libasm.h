/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevelynn <gevelynn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:05:11 by gevelynn          #+#    #+#             */
/*   Updated: 2020/11/16 23:58:31 by gevelynn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
#define LIBASM_H

#include <stdlib.h>

ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
size_t	ft_strlen(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);

#endif
