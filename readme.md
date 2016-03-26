C compiler
========

An implementation of a C compiler that takes C90 source code as input 
and produces MIPS assembly as output. The output can be linked and 
assembled to binary using tools such as gcc. The binary is then ready to 
be run on any MIPS CPU or MIPS emulator and should produce the same results as 
a binary purely compiled with gcc. 

Flex 2.6.0 and Bison 3.0.4 are used for implementing lexer and parser 
respectively. Older versions might work as well. The actual code generation
is performed using C++11.

Build
-------------------

Run `make bin/c_compiler`

Running 
-------------------

The `bin/c_compiler` executable takes C90 preprocessed source 
code on `stdin` and produces MIPS assembly on `stdout`

