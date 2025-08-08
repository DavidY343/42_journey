# My 42 Madrid Journey

A snapshot of my adventure at 42 Madrid—exploring from low-level C fundamentals to graphics, networking, and system deployment. Below you'll find a summary of each project and the key skills I gained.

## Projects Overview

- **libft** – The foundational C library: I reimplemented core C functions (`ft_strlen`, `ft_memcpy`, etc.), cementing my understanding of pointers, memory management, and writing reusable, clean code.

- **ft_printf** – A custom version of `printf` with support for format specifiers (`%d`, `%s`, `%x`, etc.). Through this, I mastered `va_list`, parsing formats, and handling flags, precision, and field width.

- **get_next_line** – A function that reads a file descriptor line by line, regardless of buffer size. I improved skills in memory allocation, buffer management, static variables, and edge-case handling.

- **pipex** – I replicated basic shell piping: setting up processes using `fork`, using `execve`, and creating pipes to connect commands. Learned about process control and inter-process communication.

- **philo** (Dining Philosophers) – A concurrency challenge requiring threads, mutexes, and synchronization to avoid deadlocks and race conditions—boosting my understanding of thread-safe programming.

- **push_swap** – A sorting challenge using only a restricted set of stack operations, aiming to minimize moves. This honed my algorithmic strategy skills and stack manipulation under constraints.

- **so_long** – A simple 2D game using MiniLibX where a player collects items and exits a maze. I practiced graphics rendering, event handling, game logic, and dynamic memory for assets.

- **cub3d** – A lightweight 3D raycasting game engine (inspired by Wolfenstein 3D), where I learned about 3D math, raycasting algorithms, texture mapping, and real-time graphics basics in C.

- **minishell** – A mini Unix shell implemented from scratch, supporting command parsing, built-ins, environment variables, and redirections. This deepened my understanding of parsing, process management, and shell internals.

- **ft_irc** – A simplified version of an IRC (Internet Relay Chat) server and client in C. I tackled socket programming, networking protocols, concurrent client handling, and the basics of client-server architecture.

- **piscine** – The intensive coding bootcamp that kick-started my journey. Over a month I tackled a wide range of small projects and exercises—from C basics to Linux CLI tools—building a strong foundation and learning to think algorithmically and debug effectively.

- **inception** – The final capstone where I built a Dockerized infrastructure stack (web server, database, etc.) to run a web app. I mastered containerization, service orchestration, and deployment best practices.

---

## How to Navigate This Repository

1. Each project folder (e.g., `minishell/`, `cub3d/`) includes its own `Makefile`.
2. Feel free to explore the source code, test cases, and your own notes to trace how your skills evolved—from low-level programming to system-level design and deployment.
3. The `inception/` directory offers a complete Docker-based service infrastructure, showcasing integration and production-level thinking.

---

Thanks for visiting my 42 Madrid journey! Feel free to explore any project to see how I grew in problem solving, system programming, and deployment through each milestone.
