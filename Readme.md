
# Readme

Deixo aqui alguns códigos de resolução de exercícios do livro **Estruturas de Dados Usando C**, do *Tenembaum, Langsam e Augenstein*. Edição de 1995. 




# Run

### Com GCC

```shell
gcc main.c -o main
gcc -Wall -Wextra -Werror main.c -o main
gcc -Wall -Wextra -Werror -g3 main.c -o main

# GDB 
gcc main.c -o main -g3
```

### Com TCC
```shell
tcc -run main.c
tcc stack.c -run main.c
```

### References

https://github.com/TheAlgorithms/C/tree/master/data_structures/stack
https://iafisher.com/blog/2020/06/type-safe-generics-in-c
https://www.andreinc.net/2010/09/30/generic-data-structures-in-c#hacking-with-the-preprocessor
https://ece.uwaterloo.ca/~dwharder/icsrts/Tutorials/Tools/