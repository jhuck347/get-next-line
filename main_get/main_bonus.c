#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int fd1, fd2;
    char *line1, *line2;

    if (argc != 3)
    {
        printf("Uso: %s <archivo1> <archivo2>\n", argv[0]);
        return (1);
    }

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    if (fd1 == -1 || fd2 == -1)
    {
        perror("Error al abrir archivos");
        return (1);
    }

    printf("Leyendo de %s y %s simultáneamente:\n\n", argv[1], argv[2]);

    while (1)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);

        if (!line1 && !line2)
            break;

        if (line1)
        {
            printf("Archivo 1: %s", line1);
            free(line1);
        }

        if (line2)
        {
            printf("Archivo 2: %s", line2);
            free(line2);
        }
    }

    close(fd1);
    close(fd2);
    return (0);
}
