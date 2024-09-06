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

# define BUFFER_SIZE 5

char	*get_next_line(int fd)
{
	int	bytes_read;
	static int counter = 0;
	int	how_big;
	int	temp;
	char	potential_line_buffer[BUFFER_SIZE];
	static char	unough_line[BUFFER_SIZE];
	char	*str;
	int	put_str;
	static char	*fat;
	static int n = 0;
	int size_fat;
	static int	i = 0;
	static int	fatty = 0;

	bytes_read = read(fd,	potential_line_buffer, BUFFER_SIZE);
	printf("result is %d\n", bytes_read);

	// if nao for a ultima leitura
	
		how_big = 0;
		while 	(how_big < BUFFER_SIZE)
		{
			if (potential_line_buffer[how_big] == '\n')
				n++;
			how_big++;
			if (n >= 1)
				size_fat++;
		}
	// if n > 0 
		if (n == 0) // changed the int initiation to static int so I can join other buffer to this if necessary
		{	
			unough_line = (char *)malloc(how_big + 1);
			temp = 0; 
			while (temp < how_big) // wrong, it will loop forever
			{
				unough_line[i] = potential_line_buffer[(temp)];
				i++;
				temp++;
			}
			unough_line[i] = '\0';

		else if (n != 0) // changed the int initiation to static int so I can 
		{	
			fat = (char *)malloc(size_fat + 1); 
			while (size_fat)
			{
				fat[i] = potential_line_buffer[(how_big - size_fat)];
				i++;
				size_fat--;
			}
			fat[i] = '\0';	

			// store fat


			if (counter == 0) // not sure about this condition
			{
				temp = 0;
				while 	(potential_line_buffer[temp] != '\n' && temp < BUFFER_SIZE)
					temp++;

				str = (char *)malloc(temp + 1);

				while 	(potential_line_buffer[counter] != '\n' && potential_line_buffer[counter] != '\0')
				{
					str[counter] = potential_line_buffer[counter];
					counter++;
				}
				str[counter] = '\0';
			}
			else if (counter != 0)
			{
				temp = counter;
				counter = counter + 1;
				while 	(potential_line_buffer[temp] != '\n' && potential_line_buffer[temp] != '\0')
					temp++; 	
				
				str = (char *)malloc(temp + 1);
	 
				put_str = 0;
				while 	(potential_line_buffer[counter] != '\n' && potential_line_buffer[counter] != '\0')
				{
					str[put_str] = potential_line_buffer[counter];
					counter++;	
					put_str++;
				}
				str[put_str] = '\0';
			}

		}
		else
		{ 
			unough_line = (char *)malloc(BUFFER_SIZE + 1);
			temp = 0;
			while (temp < BUFFER_SIZE && potential_line_buffer[temp] != '\n')
			{
				unough_line[temp] =	potential_line_buffer[temp];
				temp++;
			}
			unough_line[temp + 1] = '\0';
		}
	
	return (str);
	return (fat);
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


