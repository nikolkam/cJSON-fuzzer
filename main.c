#include "cjson/cJSON.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    cJSON *json;
    size_t offset = 4;
    unsigned char *copied;
    char *printed_json = NULL;
    int minify, require_termination, formatted, buffered;

    if(size == 0) return 0;

    json = cJSON_ParseWithOpts((const char*)data + offset, NULL, require_termination);

    if(json == NULL) return 0;

    

    if(printed_json != NULL) free(printed_json);

    if(minify)
    {
        copied = (unsigned char*)malloc(size);
        if(copied == NULL) return 0;

        memcpy(copied, data, size);

        cJSON_Minify((char*)copied + offset);

        free(copied);
    }

    cJSON_Delete(json);

    return 0;
}