# C++/Rust comparison of basic lin. alg. routines
## To build the C++ program:
* "cd" into the "cpp" directory.
* Make a new directory for building everything (e.g., "build").
* Enter "cmake .."
* Enter "cmake --build ."
* And, just like that, everything should be built!
-------------------------------
## To build the Rust program:
* "cd" into the "rust" directory.
* Enter "cargo build" (append a "--release" to optimize things).
* The binary should then be located somewhere within the "target" directory. If you don't feel like looking for it, entering "cargo run" from the project root will attempt to build the project and immediately run the program.
