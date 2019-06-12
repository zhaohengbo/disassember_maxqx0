#ifndef DECODE_H_INCLUDED
#define DECODE_H_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    decode_success = 0,
    decode_unknown = 1,
    decode_error = 2
} decode_status;

#endif // DECODE_H_INCLUDED
