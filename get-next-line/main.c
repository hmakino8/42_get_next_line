#include "get_next_line.h"
#include <libc.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char *line;
	int fd, fd2, fd3, cnt;

	fd = open("./files/gnl_instructions.txt", O_RDONLY);
	fd2 = open("./files/odd_num.txt", O_RDONLY);
	fd3 = open("./files/even_num.txt", O_RDONLY);
  
	cnt = 4;
	while (cnt--)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
}
