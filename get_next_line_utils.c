# include <stdlib.h>

int gnl_strlen(char *str)
{
    int i;
    i = 0;
    if (!str) 
    {
        return (i);
    }
    while (str[i])
        i++;
    return (i);
}

int gnl_strchr(char* str, char c) 
{
    int i;
    i = 0;
    if (!str) 
    {
        return (-1);
    }
    while (str[i]) 
    {
        if (str[i] == c) 
            return i;
        i++;
    }
    return -1;
}

char    *gnl_strjoin(char *s1, char *s2)
{
    char    *str;
    int i;
    int j;

    str = (char *)malloc(sizeof(*s1) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    if (s1)
    {
        while (s1[i])
        {
            str[j++] = s1[i];
            i++;
        }
    }
    i = 0;
    if (s2)
    {
        while (s2[i])
        {
            str[j++] = s2[i];
            i++;
        }
    }
    str[j] = '\0';
    if (s1)
        free (s1);
    return (str);
}

char    *chop_line(char *remainder)
{
    int length;
    char    *line;
    if (!remainder)
        return (NULL);

    length = 0;
    while( remainder[length] && remainder[length] != '\n')
        length++;
    if(remainder[length] == '\n')
        length++;
    if (length == 0)
        return(NULL);
    line = (char *)malloc((length + 1)*(sizeof (char)));
    if(!line)
        return(NULL);
    length = 0;
    while( remainder[length] && remainder[length] != '\n') 
    {
        line[length] = remainder[length];
        length++;
    }
    if(remainder[length] == '\n')
    {
        line[length] = '\n';
        length++;
    }
    line[length] = '\0';
    return (line);
}

char    *chop_remainder(char *remainder)
{
    int length;
    int i;
    char    *new_remainder;
    if (!remainder)
        return (NULL);

    length = 0;
    while( remainder[length] && remainder[length] != '\n')
        length++;
    if(remainder[length] == '\n')
        length++;
    if (!remainder[length]) 
    {
        free(remainder);
        return (NULL);
    }
    new_remainder = (char *)malloc((gnl_strlen(remainder) - length + 1)*(sizeof (char)));
    if(!new_remainder)
        return(NULL);
    i = 0;
    while( remainder[length + i]) 
    {
        new_remainder[i] = remainder[length + i];
        i++;
    }
    new_remainder[i] = '\0';
    free(remainder);
    return (new_remainder);
}
