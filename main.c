#include "get_next_line.h"
#include "stdio.h"

int main(int argc, char **argv)
{
    char    *str;
    int fd;

    fd = open(argv[1], O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
	return (0);
}
