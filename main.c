#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint64_t *genbintable(char *binary);

char *to_string(uint64_t num) {
    uint64_t len = snprintf(NULL, 0, "%llu", num);
    char *str = malloc(len + 1);
    if (str == NULL) {
        return 0;
    }
    snprintf(str, len + 1, "%llu", num);
    return str;
}

uint64_t bin_to_dec(uint64_t bin) {
    char *str = to_string(bin);
    size_t length_str = strlen(str);
    uint64_t *bintable = genbintable(str);
    uint64_t result = 0;
    for (size_t iter = 0; iter < length_str; iter++) {
        if (str[iter] - '0' != 0 && str[iter] - '0' != 1) {
            return -1;
        }
        result += (str[iter] - '0') * (bintable[iter]);
    }
    return result;
}

uint64_t *genbintable(char *binary) {
    size_t strlen_binary = strlen(binary);
    uint64_t *bintable = malloc(strlen_binary + 1);
    if (bintable == NULL) {
        return 0;
    }
    for (size_t count = 0; count < strlen_binary; count++) {
        bintable[strlen_binary - count - 1] = (1 << count);
    }
    return bintable;
}

int main() {
    printf("%llu\n", bin_to_dec(101010110101010010100110100101));
    return 1;
};
