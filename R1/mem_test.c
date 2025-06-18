#include <stdio.h>
#include <string.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS << 3

typedef struct {
    unsigned long long double_word[NO_WORDS];
} arr_t __attribute__((aligned(SIZE_WORDS)));

arr_t store_byte_data[8] = { {0} };
arr_t store_byte_expected_data[8] = {
    {0x00000000000000EF, 0x0000000000000000},
    {0x000000000000BE00, 0x0000000000000000},
    {0x0000000000AD0000, 0x0000000000000000},
    {0x00000000DE000000, 0x0000000000000000},
    {0x000000EF00000000, 0x0000000000000000},
    {0x0000BE0000000000, 0x0000000000000000},
    {0x00AD000000000000, 0x0000000000000000},
    {0xDE00000000000000, 0x0000000000000000}
};

arr_t store_half_word_data[8] = { {0} };
arr_t store_half_word_expected_data[8] = {
    {0x000000000000BEEF, 0x0000000000000000},
    {0x0000000000ADBE00, 0x0000000000000000},
    {0x00000000DEAD0000, 0x0000000000000000},
    {0x000000EFDE000000, 0x0000000000000000},
    {0x0000BEEF00000000, 0x0000000000000000},
    {0x00ADBE0000000000, 0x0000000000000000},
    {0xDEAD000000000000, 0x0000000000000000},
    {0xDE00000000000000, 0x00000000000000EF}
};

arr_t store_word_data[8] = { {0} };
arr_t store_word_expected_data[8] = {
    {0x00000000DEADBEEF, 0x0000000000000000},
    {0x000000DEADBEEF00, 0x0000000000000000},
    {0x0000DEADBEEF0000, 0x0000000000000000},
    {0x00DEADBEEF000000, 0x0000000000000000},
    {0xF00DC0DE00000000, 0x0000000000000000},
    {0x0DC0DE0000000000, 0x00000000000000F0},
    {0xC0DE000000000000, 0x000000000000F00D},
    {0xDE00000000000000, 0x0000000000F00DC0}
};

arr_t store_double_word_data[8] = { {0} };
arr_t store_double_word_expected_data[8] = {
    {0xDEADBEEFF00DC0DE, 0x0000000000000000},
    {0xADBEEFF00DC0DE00, 0x00000000000000DE},
    {0xBEEFF00DC0DE0000, 0x000000000000DEAD},
    {0xEFF00DC0DE000000, 0x0000000000DEADBE},
    {0xF00DC0DE00000000, 0x00000000DEADBEEF},
    {0x0DC0DE0000000000, 0x000000DEADBEEFF0},
    {0xC0DE000000000000, 0x0000DEADBEEFF00D},
    {0xDE00000000000000, 0x00DEADBEEFF00DC0}
};

int store_byte_test() {
    unsigned char bytes[8] = {0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE};
    for (int i = 0; i < 8; i++) {
        unsigned char *p = (unsigned char *)&store_byte_data[i];
        p[i] = bytes[i];
    }
    for (int i = 0; i < 8; i++) {
        if (memcmp(&store_byte_data[i], &store_byte_expected_data[i], sizeof(arr_t)) != 0) {
            return 0;
        }
    }
    return 1;
}

int store_half_word_test() {
    unsigned short values[8] = {0xBEEF, 0xADBE, 0xDEAD, 0xEFDE, 0xBEEF, 0xADBE, 0xDEAD, 0xEFDE};
    for (int i = 0; i < 8; i++) {
        unsigned char *p = (unsigned char *)&store_half_word_data[i];
        *(unsigned short *)(p + i) = values[i];
    }
    for (int i = 0; i < 8; i++) {
        if (memcmp(&store_half_word_data[i], &store_half_word_expected_data[i], sizeof(arr_t)) != 0) {
            return 0;
        }
    }
    return 1;
}

int store_word_test() {
    unsigned int values[8] = {
        0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF,
        0xF00DC0DE, 0xF00DC0DE, 0xF00DC0DE, 0xF00DC0DE
    };
    for (int i = 0; i < 8; i++) {
        unsigned char *p = (unsigned char *)&store_word_data[i];
        *(unsigned int *)(p + i) = values[i];
    }
    for (int i = 0; i < 8; i++) {
        if (memcmp(&store_word_data[i], &store_word_expected_data[i], sizeof(arr_t)) != 0) {
            return 0;
        }
    }
    return 1;
}

int store_double_word_test() {
    const unsigned long long value = 0xDEADBEEFF00DC0DEULL;
    for (int i = 0; i < 8; i++) {
        unsigned char *ptr = (unsigned char *)&store_double_word_data[i];
        memcpy(ptr + i, &value, sizeof(value));
    }
    for (int i = 0; i < 8; i++) {
        if (memcmp(&store_double_word_data[i], &store_double_word_expected_data[i], sizeof(arr_t)) != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int all_pass = 1;

    all_pass &= store_byte_test();
    all_pass &= store_half_word_test();
    all_pass &= store_word_test();
    all_pass &= store_double_word_test();

    printf(all_pass ? "All tests passed!\n" : "Some tests failed.\n");
    return all_pass ? 0 : 1;
}
