# get_next_line

### Prototype
```C
char	*get_next_line(int fd);
```
### Turn in files
- [`get_next_line.c`](https://github.com/hmakino8/42_get_next_line/blob/main/get-next-line/get_next_line.c)
- [`get_next_line_utils.c`](https://github.com/hmakino8/42_get_next_line/blob/main/get-next-line/get_next_line_utils.c)
- [`get_next_line.h`](https://github.com/hmakino8/42_get_next_line/blob/main/get-next-line/get_next_line.h)

### Description
write a function which returns a line read from a file descriptor, without the newline.

## How it works
1. ### prepare text files like below.
- gnl_instructions.txt
```
• Calling your function get_next_line in a loop.
• This function should return the line that has just been read.
• If there is nothing　else to read or if an error has occurred it should return NULL
• libft is not allowed for this project.
• Your program must compile with the flag -D BUFFER_SIZE=xx.
• The program will be compiled in this way:
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.
```
- odd_num.txt
```
1
3
5
```
- even_num.txt
```
2
4
6
```
2. ### Write a main function like below　
- main.c
```C
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
```
3. ### Compile and run
```sh
$ gcc get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=1024
$ ./a.out
```
You should get a result like below
```
1
• Calling your function get_next_line in a loop.
2
• This function should return the line that has just been read.
3
• If there is nothing　else to read or if an error has occurred it should return NULL
4
• libft is not allowed for this project.
5
• Your program must compile with the flag -D BUFFER_SIZE=xx.
6
• The program will be compiled in this way:
7
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.
(null)(null)
```
