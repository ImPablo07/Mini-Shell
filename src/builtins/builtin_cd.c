#include <unistd.h>
#include <stdio.h>

#include "builtins.h"

int builtin_cd(t_command *cmd)
{
    if (!cmd->argv[1])
    {
        fprintf(stderr,
                "cd: missing argument\n");
        return (1);
    }

    if (chdir(cmd->argv[1]) != 0)
    {
        perror("cd");
        return (1);
    }

    return (0);
}
