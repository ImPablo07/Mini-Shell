/******************************************************************************
 * @file builtins.h
 * @author Paweł Czarny
 * @brief Deklaracje funkcji wbudowanych MiniShell.
 *
 * Moduł odpowiada za:
 * - identyfikację poleceń wbudowanych,
 * - wykonywanie poleceń wbudowanych,
 * - obsługę poleceń modyfikujących stan shella.
 ******************************************************************************/

#ifndef BUILTINS_H
# define BUILTINS_H

# include "parser.h"
# include "minishell.h"

/**
 * @brief Sprawdza, czy polecenie jest builtinem.
 *
 * @param cmd Nazwa polecenia.
 *
 * @return
 * - 1 jeśli polecenie jest builtinem,
 * - 0 w przeciwnym przypadku.
 */
int is_builtin(char *cmd);

/**
 * @brief Implementacja polecenia echo.
 *
 * @param cmd Struktura polecenia.
 *
 * @return Kod zakończenia.
 */
int builtin_echo(t_command *cmd);

/**
 * @brief Implementacja polecenia pwd.
 *
 * @return Kod zakończenia.
 */
int builtin_pwd(void);

/**
 * @brief Implementacja polecenia cd.
 *
 * @param cmd Struktura polecenia.
 *
 * @return Kod zakończenia.
 */
int builtin_cd(t_command *cmd);

/**
 * @brief Implementacja polecenia env.
 *
 * @param shell Struktura shella.
 *
 * @return Kod zakończenia.
 */
int builtin_env(t_shell *shell);

/**
 * @brief Implementacja polecenia exit.
 *
 * @param cmd Struktura polecenia.
 *
 * @return Kod zakończenia.
 */
int builtin_exit(t_command *cmd);

/**
 * @brief Wykonuje odpowiedni builtin.
 *
 * Funkcja pełni rolę dispatchera.
 *
 * @param shell Struktura shella.
 * @param cmd Polecenie do wykonania.
 *
 * @return Kod zakończenia.
 */
int execute_builtin(t_shell *shell, t_command *cmd);

#endif
