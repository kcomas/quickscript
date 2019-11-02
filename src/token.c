
#include "token.h"

static inline token_state *token_state_init(size_t len) {
    token_state *state = calloc(1, sizeof(token_state) + (sizeof(uint8_t) * len));
    state->len = len;
    return state;
}

token_state *tokenize_file_init(const char *path, char **const err) {
    struct stat info;
    if (stat(path, &info) == -1) {
        *err = "Unable To Find File";
        return NULL;
    }
    token_state *ts = token_state_init(info.st_size);
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        *err = "Unable To Open File";
        free(ts);
        return NULL;
    }
    ssize_t total = read(fd, ts->str, info.st_size);
    if (total != info.st_size) {
        *err = "Unable To Read File";
        free(ts);
        close(fd);
        return NULL;
    }
    close(fd);
    return ts;
}
