%: %.c
    gcc sources/$@.c -o bin/$@ -Wall -Werror -lm
