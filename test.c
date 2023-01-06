#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MSGSIZE 17
char* msg1 = "hello, world #1\n";
char* msg2 = "hello, world #2\n";
char* msg3 = "hello, world #3\n";

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int main()
{
    char inbuf[MSGSIZE];
    int p[2], i;
  
    if (pipe(p) < 0)
        exit(1);
  
    /* continued */
    /* write pipe */
  
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
  
    for (i = 0; i < 3; i++) {
        /* read pipe */
        read(p[0], inbuf, MSGSIZE);
        write(1, inbuf, ft_strlen(inbuf));
    }
    return 0;
}