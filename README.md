# ErgodoxEZ_Convertor
To solve the mirror-image problem of my ergodoxEZ.
 
This tool is based on `Windows` and `Linux`, and compiled successfully under `VS2017` and `Ubuntu16.04` with gcc version 5.4.0
## How to use
+ Download sourcecode.
+ In Linux, execute:
```
g++ ./main.cpp -o ergoconv
```
+ In Windows, compile sourcecode with `VS2017` or other IDE/compiler.

## Usage
+ Windwos
```
convertor [file.c]
```
+ Linux
```
./ergoconv [file.c]
```
Where `file.c` represents the original keymap file generated online. 
The converted keymap file `keymap.c` will be generated after the program complete its execution  successfully.

