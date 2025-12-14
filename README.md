# ENCRYPTOR: C Encryption Suite


## What This Encryptor Does
This program performs basic character-based encryption on text input using a deterministic transformation. It is designed as a learning project in C, demonstrating string handling, character manipulation, and file I/O without external libraries.

## What This Encryptor Does Not Do
This encryptor is not cryptographically secure and should not be used to protect sensitive or confidential data. It does not implement industry-standard encryption algorithms, key management, or secure randomness. Its purpose is educational, not security-critical.

## How to Compile and Run
Compile (GCC):
gcc encryptor.c -o encryptor

Run:
./encryptor

Follow the on-screen prompts to input text and generate the encrypted output.

## About the Project
Encryptor is a modular encryption program written entirely in C.  
It currently supports substitution-cipher encryption with:

- Random key generation  
- Persistent key saving and loading  
- A growing multi-file structure for expansion  

The goal is to build a clean, extendable encryption toolkit.

---

## Tech Stack

- **C**
- Standard C libraries (`stdio.h`, `stdlib.h`, `ctype.h`, `string.h`, `time.h`)

_No external dependencies._

---

## Project Structure

```

ENCRYPTOR-ENCRYPTION-SUITE/
│
├── src/
│   ├── encryptor.c      (main program)
│   ├── keygen.c         (key generation logic)
│   ├── fileio.c         (load/save key)
│
├── include/
│   ├── encryptor.h
│   ├── keygen.h
│   ├── fileio.h
│
├── key.txt              (auto-generated substitution key)
├── Makefile
└── README.md

````

---

## Getting Started

### Prerequisites

You need:

- A C compiler (GCC or Clang)
- `make`

On Ubuntu / WSL:

```bash
sudo apt update
sudo apt install build-essential
````

---

## Build the Program

From the project root:

```bash
make
```

This creates:

```
./encryptor
```

---

## Usage

Run the program:

```bash
./encryptor
```

The program will:

* Load an existing key from `key.txt`
* Or generate a new random key if none exists
* Offer the option to regenerate a key
* Prompt you for plaintext
* Output encrypted ciphertext

Example:

```
Loaded key: QWERTYUIOPASDFGHJKLZXCVBNM
plaintext: hello world
ciphertext: itssg vgksr
```

---

## Roadmap

* [ ] Add decryption capability
* [ ] Add Caesar cipher module
* [ ] Create a menu-driven UI
* [ ] Add support for multiple saved keys
* [ ] Build additional encryption modules
* [ ] Expand documentation for each module
* [ ] Add performance tests

---

## Contributing

1. Fork the repository
2. Create your feature branch
3. Commit your changes
4. Push to your branch
5. Submit a pull request

---

## License

Distributed under the MIT License.
See `LICENSE` for details.

---

## Contact

Maintainer: **RAUL**
GitHub: [https://github.com/raulopez579](https://github.com/raulopez579)

---

## Acknowledgments

* CS50 for foundational C knowledge
* C Standard Library maintainers
* Future contributors



