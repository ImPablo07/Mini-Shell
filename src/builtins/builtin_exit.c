/******************************************************************************
 * @file builtin_exit.c
 * @author Paweł Czarny
 * @brief Implementacja polecenia exit.
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include "builtins.h"

/**
 * @brief Kończy działanie MiniShell.
 *
 * Jeżeli podano argument liczbowy,
 * zostaje on użyty jako kod wyjścia.
 *
 * @param cmd Polecenie wraz z argumentami.
 *
 * @return Funkcja nie powinna wrócić,
 * ponieważ wywołuje exit().
 */
int builtin_exit(t_command *cmd)
{
    int status;

    status = 0;

    if (cmd->argv[1])
        status = atoi(cmd->argv[1]);

    printf("exit\n");

    exit(status);
}
