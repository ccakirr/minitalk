# Minitalk

A simple client-server communication program that transmits messages using only UNIX signals.

## 📋 Description

Minitalk is a project that demonstrates inter-process communication (IPC) using UNIX signals. The program consists of a server (`listener`) and a client (`speaker`) that communicate by encoding text messages into binary and transmitting them bit-by-bit using `SIGUSR1` and `SIGUSR2` signals.

### How it works:

- **Server (listener)**: Displays its PID and waits to receive messages
- **Client (speaker)**: Takes a message and sends it to the server using the server's PID
- Each character is broken down into 8 bits
- `SIGUSR1` represents bit `0`
- `SIGUSR2` represents bit `1`
- Server reconstructs the message from received bits and displays it

## 🚀 Features

- ✅ Reliable message transmission with acknowledgment system
- ✅ Bit-level manipulation for character encoding
- ✅ Asynchronous signal handling
- ✅ Support for extended ASCII characters
- ✅ Clean error handling

## 🛠️ Installation

```bash
# Clone the repository
git clone https://github.com/ccakirr/minitalk.git
cd minitalk

# Compile the project
make
```

This will create two executables: `listener` (server) and `speaker` (client).

## 📖 Usage

### Starting the Server

```bash
./listener
```

The server will display its PID:

```
Server PID: 12345
```

### Sending a Message

```bash
./speaker [SERVER_PID] "Your message here"
```

Example:

```bash
./speaker 12345 "Hello, World!"
```

The message will appear on the server terminal.

## 🔧 Compilation

Available Makefile rules:

- `make` - Compile both server and client
- `make clean` - Remove object files
- `make fclean` - Remove object files and executables
- `make re` - Recompile everything

## 📚 Technical Details

### Signal Flow

1. Client converts each character to binary (8 bits)
2. For each bit:
   - Sends `SIGUSR1` for `0`
   - Sends `SIGUSR2` for `1`
3. Server receives signal and reconstructs the bit
4. Server sends acknowledgment back to client
5. After 8 bits, server displays the character

### Libraries Used

- `libft` - Custom C library
- `ft_printf` - Custom printf implementation
- Standard signal handling functions

## 🎓 Learning Outcomes

This project teaches:

- UNIX signal handling
- Inter-process communication
- Bit manipulation
- Asynchronous programming
- Signal safety considerations

## ⚙️ Requirements

- Unix-based operating system (Linux, macOS)
- GCC compiler
- Make

## 📝 Project Structure

```
minitalk/
├── listener.c          # Server implementation
├── speaker.c           # Client implementation
├── Makefile           # Build configuration
├── libft/             # Custom C library
└── ft_printf/         # Custom printf implementation
```

## 🐛 Error Handling

The program handles:

- Invalid PID
- Signal transmission failures
- Memory allocation errors
- Invalid arguments

## 👨‍💻 Author

**Caner Çakır**

- GitHub: [@ccakirr](https://github.com/ccakirr)

## 📄 License

This project is part of the 42 School curriculum.

---

_Made with ❤️ as part of 42 Istanbul_
