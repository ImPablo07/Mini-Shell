/******************************************************************************
 * @file builtin_pwd.c
 * @author Paweł Czarny
 * @brief Implementacja polecenia pwd.
 ******************************************************************************/

#include <stdio.h>
#include <unistd.h>

#include "builtins.h"

/**
 * @brief Wyświetla aktualny katalog roboczy.
 *
 * Funkcja korzysta z getcwd().
 *
 * @return
 * - 0 przy sukcesie,
 * - 1 przy błędzie.
 */
int builtin_pwd(void)
{
    char cwd[4096];

    if (getcwd(cwd, sizeof(cwd)))
    {
        printf("%s\n", cwd);
        return (0);
    }

    return (1);
}
