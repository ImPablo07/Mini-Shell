#include <stdlib.h>
#include <stdio.h>

#include "builtins.h"

int builtin_exit(t_command *cmd)
{
    int status;

    status = 0;

    if (cmd->argv[1])
        status = atoi(cmd->argv[1]);

    printf("exit\n");

    exit(status);
}
