/******************************************************************************
 * @file builtin_cd.c
 * @author Paweł Czarny
 * @brief Implementacja polecenia cd.
 ******************************************************************************/

#include <unistd.h>
#include <stdio.h>

#include "builtins.h"

/**
 * @brief Zmienia aktualny katalog roboczy.
 *
 * Aktualnie obsługiwana jest tylko postać:
 *
 * cd <ścieżka>
 *
 * @param cmd Polecenie wraz z argumentami.
 *
 * @return
 * - 0 przy sukcesie,
 * - 1 przy błędzie.
 */
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
