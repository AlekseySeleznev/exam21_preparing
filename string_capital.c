/*
[2 April 2022]
how to fix?
input: 1234string123123string
output: 1234String123123String
expected output: 1234String123123string

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char *text, symbol = 'a';
    text = malloc(1*sizeof(char));
    int position = 0;

    while (symbol != '\n') {
        scanf("%c", &symbol);
        text[position] = symbol;
        text = realloc(text, 1*sizeof(char));
        position ++;
    }

    if (text[0] >= 97 && text[0] <= 122)
        text[0] = text[0] - 32;

    for (int i = 1; i < position; i++) {
        if ((text[i-1] >=33 && text[i-1] <=64) || (text[i-1] >=91 && text[i-1] <=96) || (text[i-1] >=123 && text[i-1] <=126) || (text[i-1] == 32))
            if (text[i] >= 97 && text[i] <= 122)
                text[i] = text[i] - 32;
    }

    for (int i = 0; i < position; i++) 
        printf("%c", text[i]);

    return 0;
}
