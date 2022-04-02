#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(char *array);
void delete_specific(char *array, char *phrase, int *flag);

int main() {
    char text1[1000]="hello i'm groot";
    char text2[1000]="groot hello i'm groot";
    char text3[1000]="hello groot i'm";

    char to_delete[] = "groot";
    int flag = 0;
    //scanf("%[^\n]s",text);
    
    printf("TEST 1:");
    delete_specific(text1, to_delete, &flag);
    printf("TEST 2:");
    delete_specific(text2, to_delete, &flag);
    printf("TEST 3:");
    delete_specific(text3, to_delete, &flag);
    
    return 0;
}

void print_array(char *array) {
    int array_length = strlen(array);
    for (int i = 0; i < array_length; i ++) {
        printf("%c", array[i]);
    }
}

void delete_specific(char *array, char *phrase, int *flag) {
    int array_length = strlen(array);
    int phrase_length = strlen(phrase);
    int count=0;
    int i;
    for (i=0; i < array_length; i++) {
        for (int j = 0; j < phrase_length; j++) {
            if (array[i] == phrase[j])
                if ((array[i+1] == phrase[j+1] && count < phrase_length) || j+1 == phrase_length)
                count ++;
        }
    }


    printf("\ninput phrase: %s\n", array);
    if (count == phrase_length) {
        *flag = 1;
        printf("SUCESS!\n\n");
    }
}
