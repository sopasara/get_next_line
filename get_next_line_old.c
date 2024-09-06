/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syucheon <syucheon@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:14:09 by syucheon          #+#    #+#             */
/*   Updated: 2024/08/16 16:39:13 by syucheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

# define BUFFER_SIZE 24

char	*get_next_line(int fd)
{
	int	bytes_read;
	static int counter = 0;
	int	how_big;
	int	temp;
	char	potential_line[BUFFER_SIZE];
	char	*str;
	int	put_str;
	static char	*fat;

	bytes_read = read(fd,	potential_line, BUFFER_SIZE);
	printf("result is %d\n", bytes_read);

	if (counter == 0)
	{
		how_big = 0;
		while 	(potential_line[how_big] != '\0' &&	potential_line[how_big] != '\n')
			how_big++; 	
		
		str = (char *)malloc(how_big);
	 
		while 	(potential_line[counter] != '\0' &&	potential_line[counter] != '\n')
		{
			str[counter] =	potential_line[counter];
			counter++;
		}
		str[counter] = '\0';

	
	}
	else if (counter != 0)
	{
		how_big = counter + 1;
		while 	(potential_line[how_big] != '\0' &&	potential_line[how_big] != '\n')
			how_big++; 	
		temp = how_big - counter;
		str = (char *)malloc(temp);

		counter = counter + 1;	 
		put_str = 0;
		while 	(potential_line[counter] != '\0' &&	potential_line[counter] != '\n')
		{
			str[put_str] = potential_line[counter];
			counter++;
			put_str++;
		}
		str[put_str] = '\0';
	}
	return (str);
}

int	main(void)
{
	int fd;
	fd = open("text.h", O_RDONLY);
	printf("fd is %d\n", fd);
	printf("get_next_line gives me %s\n", get_next_line(fd));
	printf("get_next_line gives me %s\n", get_next_line(fd));
	printf("get_next_line gives me %s\n", get_next_line(fd));
	printf("get_next_line gives me %s\n", get_next_line(fd));
	printf("get_next_line gives me %s\n", get_next_line(fd));
}
