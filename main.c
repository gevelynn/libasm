/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevelynn <gevelynn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:06:52 by gevelynn          #+#    #+#             */
/*   Updated: 2020/11/16 23:59:05 by gevelynn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libasm.h"
#include <errno.h>

int		main(void)
{
	int 	i, j;
	char	s_long[] = "A Queen Bee from Hymettus flew up to Olympus with some fresh honey from the hive as a present to Jupiter, who was so pleased with the gift that he promised to give her anything she liked to ask for. She said she would be very grateful if he would give stings to the bees, to kill people who robbed them of their honey. Jupiter was greatly displeased with this request.";
	char	s_empty[] = "", s_empty2[] = "";
	char 	s1[] = "hello", s2[] = "hello", s3[] = "world";
	int 	fd, fd1, fd2, fd3;
	char	*str, *str1, *str2, *str3, *str_stdin;
	char	dest[100] = "", dest1[100] = "", dest_long[446] = "", dest_long1[446] = "";

	i = 0;
	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * 100)) || !(str1 = (char *)malloc(sizeof(char) * 100)) || !(str_stdin = (char *)malloc(sizeof(char) * 100)))
		return (0);
	fd = open("./main.c", O_RDONLY);
	fd1 = open("./main.c", O_RDONLY);
	fd2 = open("output_ft_write.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	fd3 = open("output_write.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

	printf("   \033[1;32m--ft_strlen--\033[0m\n");	//ft_strlen
	printf("--empty string--\nft_strlen: %7lu\nstrlen: %10lu\n\n", ft_strlen(s_empty), strlen(s_empty));
	printf("--long string--\nft_strlen: %7zu\nstrlen: %10lu\n", ft_strlen(s_long), strlen(s_long));

	printf("   \033[1;32m--ft_strcpy--\033[0m\n");	//ft_strcpy
	printf("--empty string--\nft_strcpy: |%s|\nstrcpy:    |%s|\n\n", ft_strcpy(dest, s_empty), strcpy(dest1, s_empty));
	printf("--long string--\nft_strcpy: |%s|\nstrcpy:    |%s|\n", ft_strcpy(dest_long, s_long), strcpy(dest_long1, s_long));

	printf("   \033[1;32m--ft_strcmp--\033[0m\n");	//ft_strcmp
	printf("--2 empty strings--\nft_strcmp: %7d\nstrcmp: %10d\n\n", ft_strcmp(s_empty, s_empty2), strcmp(s_empty, s_empty2));
	printf("--1 empty string as first argument--\nft_strcmp: %7d\nstrcmp: %10d\n\n", ft_strcmp(s_empty, s1), strcmp(s_empty, s1));
	printf("--1 empty string as second argument--\nft_strcmp: %7d\nstrcmp: %10d\n\n", ft_strcmp(s1, s_empty), strcmp(s1, s_empty));
	printf("--equal strings--\nft_strcmp: %7d\nstrcmp: %10d\n\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("--not equal strings--\nft_strcmp: %7d\nstrcmp: %10d\n\n", ft_strcmp(s1, s3), strcmp(s1, s3));
	printf("--switched not equal strings--\nft_strcmp: %7d\nstrcmp: %10d\n", ft_strcmp(s3, s1), strcmp(s3, s1));

	printf("   \033[1;32m--ft_write--\033[0m\n");	//ft_write
	ft_write(1, "STDOUT:\n", 8);
	write(1, "ft_write: ", 10);
	i = ft_write(1, s1, 4);
	write(1, "\n", 1);
	write(1, "write: ", 7);
	j = write(1, s1, 4);
	write(1, "\n", 1);
	printf("ft_write ret: %7d\nwrite ret: %10d\n", i, j);

	ft_write(fd2, s_long, ft_strlen(s_long));
	write(fd3, s_long, ft_strlen(s_long));
	printf("\033[1;34mfiles \"output_ft_write.txt\" & \"output_write.txt\" was created\033[0m\n");
	printf("--fd == 10--\n");
	write(10, "error\n", 6);
	printf("write errno code = %d\n", errno);
	perror("write");
	write(1, "\n", 1);

	errno = 0;
	printf("reset errno code = %d\n", errno);

	printf("--fd == 10--\n");
	ft_write(10, "error\n", 6);
	printf("ft_write errno code = %d\n", errno);
	perror("ft_write");

	printf("   \033[1;32m--ft_read--\033[0m\n");	//ft_read
	printf("\033[1;34mType some text for ft_read testing.\033[0m\n");
	j = ft_read(0, str_stdin, 99);
	ft_write(1, str_stdin, j);
	printf("\nreturn value = %d\n", j);
		
	i = ft_read(fd, str, 99);
	j = read(fd1, str1, 99);
	printf("\n\033[1;34mReading 99 symbols from main.c:\033[0m\n");
	printf("ft_read: %7d %s\nread: %10d %s\n", i, str, j, str1);

	printf("--fd == 10--\n");
	i = ft_read(10, str, 99);
	printf("ft_read ret: %7d\nft_read errno: %6d\n", i, errno);
	perror("ft_read");

	errno = 0;
	printf("\nreset errno code = %d\n\n", errno);

	printf("--fd == 10--\n");
	j = read(10, str, 99);
	printf("read ret: %10d\nread errno: %9d\n", j, errno);
	perror("read");

	printf("   \033[1;32m--ft_strdup--\033[0m\n");	//ft_strdup
	printf("--empty string--\nft_strdup: |%s|\nstrdup:    |%s|\n\n", (str2 = ft_strdup(s_empty)), (str3 = strdup(s_empty)));
	free(str2);
	free(str3);
	printf("--long string--\nft_strdup: |%s|\n\nstrdup:    |%s|\n", (str2 = ft_strdup(s_long)), (str3 = strdup(s_long)));
	free(str2);
	free(str3);


	close(fd);
	close(fd1);
	close(fd2);
	close(fd3);
	free(str);
	free(str1);
	free(str_stdin);
	return (0);
}
