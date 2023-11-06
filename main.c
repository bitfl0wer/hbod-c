#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint64_t *genbintable(char *binary);

uint64_t bin_to_dec(char *bin) {
    size_t length_str = strlen(bin);
    uint64_t *bintable = genbintable(bin);
    uint64_t result = 0ULL;
    for (size_t iter = 0ULL; iter < length_str; iter++) {
        if (bin[iter] - '0' != 0ULL && bin[iter] - '0' != 1ULL) {
            return -1ULL;
        }
        result += (bin[iter] - '0') * (bintable[iter]);
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
    printf("%llu\n", bin_to_dec("1111111111111111111111111111111"));
    return 1;
};
