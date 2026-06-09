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
int execute_command(t_command *cmd)
{
    pid_t pid;
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

    waitpid(pid, &status, 0);

    if (WIFEXITED(status))
        return (WEXITSTATUS(status));

    return (1);
}
