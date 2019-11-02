
#include "token.h"

int main(void) {
    char *err;
    token_state* ts = tokenize_file_init("./examples/fib.qs", &err);
    if (ts == NULL) {
        printf("%s\n", err);
        free(ts);
        return 1;
    }
    free(ts);
    return 0;
}
