#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char isbn[20];
    int publication_year;
    char genre[50];
    unsigned int available_copies;
} Book;

static inline void print_book_details(const Book *b);
static inline int is_book_available(const Book *b);

static inline void print_book_details(const Book *b) {
    if (b == NULL) return;
    printf("Title           : %s\n", b->title);
    printf("Author          : %s\n", b->author);
    printf("ISBN            : %s\n", b->isbn);
    printf("Publication Year: %d\n", b->publication_year);
    printf("Genre           : %s\n", b->genre);
    printf("Available Copies: %u\n", b->available_copies);
    printf("--------------------------------------\n");
}

static inline int is_book_available(const Book *b) {
    return b != NULL && b->available_copies > 0;
}

int main() {
    Book library[3] = {
        {"The Pragmatic Programmer", "Andrew Hunt", "978-0201616224", 1999, "Software Engineering", 5},
        {"Clean Code", "Robert C. Martin", "978-0132350884", 2008, "Programming", 0},
        {"1984", "George Orwell", "978-0451524935", 1949, "Dystopian Fiction", 3}
    };

    for (int i = 0; i < 3; ++i) {
        print_book_details(&library[i]);
        if (is_book_available(&library[i])) {
            printf("Status: Book is available.\n");
        } else {
            printf("Status: Book is not available.\n");
        }
        printf("\n");
    }

    return 0;
}
