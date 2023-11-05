#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_string(int num) {
    int len = snprintf(NULL, 0, "%d", num);
    char *str = malloc(len + 1);
    if (str == NULL) {
        return 0;
    }
    snprintf(str, len + 1, "%d", num);
    return str;
}

int bin_to_dec(int bin) {
    char *str = to_string(bin);
    size_t length_str = strlen(str);
    char *bintable = malloc(strlen(str) + 1);
    int iter = 1;
    if (bintable == NULL) {
        return 0;
    }
    bintable[strlen(str)] = iter;
    for (size_t count = length_str; count > 0; count--) {
        int current = str[count];
        // Return with -1 if input is not a binary number
        if (current != 0 && current != 1) {
            return -1;
        }
    }
    return 1;
}

int *genbintable(char *binary) {
    size_t strlen_binary = strlen(binary);
    int *bintable = malloc(strlen_binary + 1);
    if (bintable == NULL) {
        return 0;
    }
    for (size_t count = 0; count < strlen_binary; count++) {
        bintable[strlen_binary - count - 1] = (1 << count);
        printf("fn bintable: %d\n", bintable[strlen_binary - count - 1]);
    }
    printf("\n");
    return bintable;
}

int main() {
    char binary[3] = {'a', 'b', 'c'};
    int *bintable = genbintable(binary);
    for (int i = 0; i < 3; i++) {
        printf("bintable[%d]: %d\n", i, bintable[i]);
    }
    printf("%d\n", bin_to_dec(61));
    return 1;
};
