#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char * read_extend (int fd, char *buff, char* remainder)
{
	ssize_t read_bytes;
	
	read_bytes = 1;
    while (read_bytes > 0 && gnl_strchr(remainder,'\n') == -1)
	{
        read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes > 0)
		{
		buff[read_bytes] = '\0';
        remainder = gnl_strjoin (remainder, buff);
		}
    }
	return (remainder);
}
char *get_next_line(int fd)
{
    static char* remainder;
    char* buff;
	char* line;

    if (fd == -1) 
        return (NULL);
	buff = (char *) malloc( sizeof(char)*(BUFFER_SIZE + 1));
    if(!buff)
        return (NULL); 
    remainder = read_extend (fd, buff, remainder);
	free (buff);
	line = chop_line(remainder);
    remainder = chop_remainder(remainder);
    return (line);
}
/*
int compare(const char* a, const char* b) {
    if (a == b) {
        return 1;
    }
    if (!a || !b) {
        return 0;
    }
    int i = 0;
    while (1) {
        if (a[i] != b[i]) {
            return 0;
        }
		if (!a[i]) {
			return 1;
		}
        i++;
    }
    return 1;
}

// fonction pour tester
int main()
{
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        return (1);
    }

    char* result1 = get_next_line(fd);
    // result1 --> "hello\n"
    int res1 = compare(result1, "hello\n\0");
    printf("result 1 = %d\n", res1);
	printf("%s\n", result1);

    char* result2 = get_next_line(fd);
    // result2 --> "world\n"
    int res2 = compare(result2, "world\n");
    printf("result 2 = %d\n", res2);
	printf("'%s'\n", result2);

    char* result3 = get_next_line(fd);
    // result3 --> "ok\n"
    int res3 = compare(result3, "ok\n");
    printf("result 3 = %d\n", res3);

    char* result4 = get_next_line(fd);
    // result4 --> ""
    int res4 = compare(result4, "");
    printf("result 4 = %d\n", res4);

    return(0);
}

int main()
{
    int fd = open("test2.txt", O_RDONLY);
    if (fd == -1) {
        return (1);
    }

    char* result1 = get_next_line(fd);
    // result1 --> "hello\n"
    int res1 = compare(result1, "\n");
    printf("result 1 = %d\n", res1);
	printf("%s\n", result1);

    char* result2 = get_next_line(fd);
    // result2 --> "world\n"
    int res2 = compare(result2, "tototo\n");
    printf("result 2 = %d\n", res2);
	printf("'%s'\n", result2);

    char* result3 = get_next_line(fd);
    // result3 --> "ok\n"
    int res3 = compare(result3, "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
    printf("result 3 = %d\n", res3);

    char* result4 = get_next_line(fd);
    // result4 --> ""
    int res4 = compare(result4, "");
    printf("result 4 = %d\n", res4);

    return(0);
}
*/