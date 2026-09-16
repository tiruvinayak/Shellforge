# ShellForge

A custom Linux shell built from scratch in **C11**, focused on understanding how a Unix/Linux shell works internally.

ShellForge implements the core stages of shell operation — command tokenization, parsing, expansion, built-in commands, process execution, and command history — using low-level Linux system programming concepts.

---

## 🚀 Project Overview

ShellForge is a Unix-like command-line shell developed as a systems programming project.

The main goal of this project is to understand what happens internally when a user enters a command into a Linux terminal.

Instead of relying on an existing shell implementation, ShellForge builds the shell components from the ground up.

### Command Processing Pipeline

```text
User Input
    │
    ▼
┌─────────────┐
│   Lexer     │
│ Tokenization│
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   Parser    │
│ Command AST │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ Expansion    │
│ Variables    │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│  Built-ins  │
│ / Executor  │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ Linux       │
│ Processes   │
└─────────────┘
