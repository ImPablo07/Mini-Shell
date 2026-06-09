#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"

/**
 * @brief Wykonuje pojedyncze polecenie.
 *
 * @param cmd Polecenie do wykonania.
 * @return Kod zakończenia procesu.
 */
int execute_command(t_command *cmd);

#endif
