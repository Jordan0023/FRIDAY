#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "minixml.h"

int main(void)
{
    static const char input[] = "<element attribute=";
    const size_t input_len = sizeof(input) - 1;
    char *exact = malloc(input_len);
    struct xmlparser parser;

    if (exact == NULL)
        return 2;
    memcpy(exact, input, input_len);
    memset(&parser, 0, sizeof(parser));
    parser.xmlstart = exact;
    parser.xmlsize = (int)input_len;

    fprintf(stderr, "Parsing %zu-byte unterminated XML buffer\n", input_len);
    parsexml(&parser);
    free(exact);
    return 0;
}
