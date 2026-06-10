/******************************************************************************
 * @file executor.c
 * @brief Wykonywanie pojedynczych poleceń.
 ******************************************************************************/

#include <unistd.h>
#include <sys/wait.h>

#include "executor.h"

/**
 * @brief Wykonuje pojedyncze polecenie.
 *
 * @param cmd Polecenie.
 * @return Kod zakończenia procesu.
 */
int execute_command(
    t_shell *shell,
    t_command *cmd)
{
    pid_t pid;

    if (!cmd || !cmd->argv[0])
        return (1);

    if (is_builtin(cmd->argv[0]))
        return (
            execute_builtin(shell, cmd)
        );
    
#ifdef DEBUG
    print_execution(cmd);
#endif
    
    int status;

    pid = fork();

    if (pid == -1)
        return (1);

    if (pid == 0)
    {
        execvp(cmd->argv[0], cmd->argv);

        perror("execvp");
        _exit(EXIT_FAILURE);
    }

    return (wait_for_child(pid));
}
