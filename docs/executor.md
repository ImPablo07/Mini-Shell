# Executor Module
## Cel modułu

Moduł Executor odpowiada za wykonywanie poleceń przygotowanych przez Parser.

Jego zadania obejmują:

- wykonywanie poleceń zewnętrznych,
- wykonywanie poleceń wbudowanych (builtins),
- obsługę procesów potomnych,
- obsługę przekierowań wejścia i wyjścia,
- obsługę pipe'ów,
- zarządzanie kodami zakończenia procesów.

## Architektura

Przepływ wykonywania poleceń

Input
↓
Lexer
↓
Parser
↓
Executor
├── Builtins
├── External Commands
├── Redirections
└── Pipes

## Wykonywanie poleceń zewnętrznych
