#include <string.h>

#include "builtins.h"

int is_builtin(char *cmd)
{
    if (!cmd)
        return (0);

    return (
        strcmp(cmd, "echo") == 0
        || strcmp(cmd, "pwd") == 0
        || strcmp(cmd, "cd") == 0
        || strcmp(cmd, "env") == 0
        || strcmp(cmd, "exit") == 0
    );
}
