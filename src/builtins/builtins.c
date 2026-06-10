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

int execute_builtin(
    t_shell *shell,
    t_command *cmd)
{
    if (!cmd || !cmd->argv[0])
        return (1);

    if (strcmp(cmd->argv[0], "echo") == 0)
        return (builtin_echo(cmd));

    if (strcmp(cmd->argv[0], "pwd") == 0)
        return (builtin_pwd());

    if (strcmp(cmd->argv[0], "cd") == 0)
        return (builtin_cd(cmd));

    if (strcmp(cmd->argv[0], "env") == 0)
        return (builtin_env(shell));

    if (strcmp(cmd->argv[0], "exit") == 0)
        return (builtin_exit(cmd));

    return (1);
}
