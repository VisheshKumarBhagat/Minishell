# 🐚 MiniShell – A Minimalist Linux Shell

MiniShell is a simple command-line interpreter built in C. It supports executing external programs, handling built-in commands, I/O redirection, and pipelines—similar to a basic Unix shell.

> ✅ Internship Project by Aryan | 🖥️ Built for Ubuntu/Linux using C

---

## 📌 Features

- ✅ **Built-in Commands**: `cd`, `pwd`, `exit`
- ✅ **External Commands**: e.g., `ls`, `gcc`, `cat`
- ✅ **Input Redirection**: `< filename`
- ✅ **Output Redirection**: `> filename`
- ✅ **Command Pipelines**: `cmd1 | cmd2`
- 🛠️ **Manual Command Parsing**
- 🔁 **Process Handling** via `fork()`, `exec()`, `wait()`

---

## 🚀 Getting Started

### ⚙️ Prerequisites

- Ubuntu/Linux environment (or WSL on Windows)
- GCC compiler (`sudo apt install build-essential`)
- Basic knowledge of terminal and C

---

### 📁 Clone or Move to Project Directory

If you're using WSL and want to store the project in your **Windows D: drive**:

```bash
cd /mnt/d
mkdir minishell
cd minishell
```

---

### 🛠️ Step 1: Add Project Files

Ensure you have the following files in the folder:

- `minishell.c`
- `utils.c`
- `utils.h`
- `Makefile`

> Want ready-made files? Ask and I’ll zip & send them!

---

### 🧱 Step 2: Compile the Shell

Run the following command in your terminal:

```bash
make
```

✅ If successful, a binary file named `minishell` will be created in your current directory.

---

### 🧪 Step 3: Run the Shell

Now start your custom shell with:

```bash
./minishell
```

You’ll see a custom prompt like this:

```bash
minishell>
```

Now you can run shell commands such as:

```bash
ls -l
cd ..
pwd
cat < input.txt
ls > out.txt
cat file.txt | grep hello
```

---

## 📦 Project Structure

```
.
├── minishell.c       # Main loop, input handler, command routing
├── utils.c           # Helper functions: parsing, trim, redirection, etc.
├── utils.h           # Header for utility function declarations
├── Makefile          # Build instructions
└── README.md         # This file!
```

---

## ⚙️ Example Commands

| Command                   | Description                        |
|--------------------------|------------------------------------|
| `cd folder`              | Change directory                   |
| `pwd`                    | Print current directory            |
| `exit`                   | Exit the shell                     |
| `ls -l`                  | External command                   |
| `cat < input.txt`        | Input redirection                  |
| `ls > out.txt`           | Output redirection                 |
| `cat f.txt \| grep test` | Pipe output to another command     |

