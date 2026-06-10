#include <stdio.h>

#include "builtins.h"

int builtin_echo(t_command *cmd)
{
    int i;

    i = 1;

    while (cmd->argv[i])
    {
        printf("%s", cmd->argv[i]);

        if (cmd->argv[i + 1])
            printf(" ");

        i++;
    }

    printf("\n");

    return (0);
}
