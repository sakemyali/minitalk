# Minitalk

A small Unix IPC (inter-process communication) project that demonstrates sending messages between a client and a server using POSIX signals (SIGUSR1 and SIGUSR2).

This repository contains a compact implementation of a server that receives characters bit-by-bit via signals and a client that transmits messages to the server by encoding each character into signals.

## Why this project is useful

- Teaches low-level IPC using signals (SIGUSR1 / SIGUSR2) and `sigaction` with `SA_SIGINFO`.
- Lightweight, dependency-free C implementation suitable for learning systems programming concepts.
- Includes a small `ft_printf` implementation used by the project.

## Features

- Server prints received characters to stdout and acknowledges receipt.
- Client encodes each character as a sequence of signals and waits for acknowledgements.
- Makes use of a custom `ft_printf` library contained in `printf/`.

## Repository layout

- `Makefile` — top-level Makefile to build `server` and `client`.
- `files/` — source files and headers for the client/server logic:
  - `files/server.c` — server implementation
  - `files/client.c` — client implementation
  - `files/minitalk.c` — helper functions (signal setup, safe kill)
  - `files/utils.c` — utility functions (e.g. `ft_atoi`)
  - `files/minitalk.h` — shared header
- `printf/` — small `ft_printf` implementation used by both programs

## Requirements

- POSIX-compatible OS (Linux, macOS, *BSD)
- A C compiler (the Makefile uses `cc`)
- `make`

## Quick start — build

From the repository root:

```bash
make
```

This will build both `server` and `client`. The `Makefile` also builds the `printf/` library automatically.

Useful make targets:

```bash
make        # build both server and client
make server # build only the server
make client # build only the client
make clean  # remove object files
make fclean # remove binaries and printf archive
make re     # fclean + all
```

## Usage examples

1. Start the server (it will print its PID):

```bash
./server
# Output: Server's PID is: 12345
```

2. In another terminal, send a message from the client to the server using the printed PID:

```bash
./client 12345 'Hello, server!'
```

Notes:
- The client requires exactly two arguments: the server PID and the message (see `files/client.c`).
- The server runs an infinite loop and prints received characters as they arrive.

## How it works (brief)

- The client encodes each character bit-by-bit and sends SIGUSR1 for a 1 bit and SIGUSR2 for a 0 bit.
- The server's `sigaction` handler reconstructs bytes from incoming signals and prints characters. After each bit/character, the server sends acknowledgements back to the client.
- See `files/server.c`, `files/client.c`, and `files/minitalk.c` for implementation details.

## Where to get help

- Open an issue: https://github.com/sakemyali/minitalk/issues
- For questions about the implementation, inspect the source files in `files/` and `printf/`.