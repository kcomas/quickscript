
#include "token.h"

static inline token_state *token_state_init(size_t len) {
    token_state *state = calloc(1, sizeof(token_state) + (sizeof(uint8_t) * len));
    state->len = len;
    return state;
}
