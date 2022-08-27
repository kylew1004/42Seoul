#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char    *input;
    int     fd;
    if (argc < 2)
        return (0);
    printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
    fd = open(argv[1], O_RDONLY);
    input = get_next_line(fd);
    while (input && *input != '\0')
    {
        printf("%s", input);
        free(input);
        input = get_next_line(fd);
    }
    printf("%s", input);
    close(fd);
    return (0);
}