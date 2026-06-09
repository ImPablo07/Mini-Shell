/******************************************************************************
 * @file executor_utils.c
 * @brief Funkcje pomocnicze executora.
 ******************************************************************************/

#include <sys/wait.h>

#include "executor.h"

/**
 * @brief Oczekuje na zakończenie procesu potomnego.
 *
 * @param pid PID procesu potomnego.
 * @return Kod zakończenia procesu.
 */
int wait_for_child(pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);

    if (WIFEXITED(status))
        return (WEXITSTATUS(status));

    return (1);
}
