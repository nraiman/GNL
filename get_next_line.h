
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char *get_next_line(int fd);
int gnl_strlen(char *str);
int gnl_strchr(char* str, char c);
char	*gnl_strjoin(char *s1, char *s2);
char    *chop_line(char *remainder);
char* chop_remainder(char * remainder);
