#include "../inc/work_with_data.h"

bool validate_nums(const char *data, size_t len_data)
{
    bool dot = false;

    if (len_data == 0)
        return false;

    for (size_t i = 0; i < len_data; i++)
    {
        if (isdigit(data[i]))
            continue;
        else if (data[i] == '.' && !dot)
            dot = true;
        else
            return false;
    }

    return true;
}