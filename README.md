*This project has been created as part of the 42 curriculum by @sywee.*

# Minitalk

## Description

Minitalk is a small client/server data exchange program. The client sends a string to the server, and the server prints it. Communication uses **only UNIX signals** (`SIGUSR1` and `SIGUSR2`).

**Goal:** learn how UNIX signals work and how to transmit data through them.

**How it works:**

| Step | Program | Action |
|------|---------|--------|
| 1 | Server | Prints its PID, then waits for signals (`pause`) |
| 2 | Client | Takes the server PID and a string |
| 3 | Client | Sends each character bit by bit, MSB first: `SIGUSR1` = `1`, `SIGUSR2` = `0` |
| 4 | Server | Rebuilds each character from 8 signals and prints it |
| 5 | Client | Sends a final `'\0'`; the server prints a newline |

**Example (`'A'` = `01000001`):**

```
SIGUSR2 SIGUSR1 SIGUSR2 SIGUSR2 SIGUSR2 SIGUSR2 SIGUSR2 SIGUSR1  ->  'A'
```

**Technical choices:**

- `sigaction` with `SA_SIGINFO`: the handler receives the sender's PID (`si_pid`).
- Server state (current bit, current character, client PID) is kept in one global struct `g_data`. A global is needed because a signal handler cannot receive custom arguments.
- If a new client PID is detected, the server resets its state, so several clients can send strings in a row.
- `usleep(1000)` between signals: signals of the same type are not queued, so the client must leave time for the server to process each one.

## Instructions

**Compile:**

```bash
make
```

This builds the `server` and `client` executables.

**Run:**

```bash
# Terminal 1
./server
# Server PID: 12345

# Terminal 2
./client 12345 "Hello, Minitalk!"
```

The server prints:

```
Hello, Minitalk!
```

**Makefile rules:**

| Rule | Effect |
|------|--------|
| `make` / `make all` | Build `server` and `client` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executables |
| `make re` | Full rebuild |

## Resources

**References:**

- `man 2 signal`, `man 2 sigaction`, `man 2 kill`, `man 2 pause`, `man 2 usleep`
- `man 7 signal`: overview of signals and their behavior
- Bitwise operators in C: shifts (`>>`, `<<`) and masks (`&`, `|`)

**AI usage:**

<!-- Fill in honestly: which tasks, which parts of the project. Example below. -->

- AI was used for: <e.g. understanding how `sigaction` and `siginfo_t` work, generating this README structure>.
- AI was **not** used for: <e.g. writing the client/server logic>.
- All AI-generated content was reviewed, tested, and is fully understood by the author(s).