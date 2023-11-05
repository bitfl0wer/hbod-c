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
    for (size_t count = 0; count < length_str; count++) {
        int current = str[count];
        if (current != 0 && current != 1) {
            return -1;
        }
    }
    return 1;
}

int main() {
    printf("%d", bin_to_dec(61));
    return 1;
};
