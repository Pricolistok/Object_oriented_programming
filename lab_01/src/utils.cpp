#include "../inc/utils.h"
#include "../inc/errors.h"
#include "../inc/struct.h"

int read_len_from_file(dataset &data, FILE *file_source)
{
    int rc, error_code = OK;
    int len_data_buffer;
    rc = fscanf(file_source, "%d", &len_data_buffer);
    if (rc != 1)
        error_code = ERROR_VALUE_IN_FILE;
    else if (len_data_buffer <= 0)
        error_code = ERROR_LEN_DATA;
    else
        data.cnt_points = len_data_buffer;
    return error_code;
}

int read_data_points(dataset &data, FILE *file_source)
{
    int rc, error_code = OK;
    double x_from_file = 0, y_from_file = 0, z_from_file = 0;
    size_t iter = 0;

    error_code = read_len_from_file(data, file_source);

    while (iter < data.cnt_points && error_code == OK)
    {
        rc = fscanf(file_source, "%lf %lf %lf", &x_from_file, &y_from_file, &z_from_file);
        if (rc != 3)
            error_code = ERROR_VALUE_IN_FILE;
        data.points->x = x_from_file;
        data.points->y = y_from_file;
        data.points->z = z_from_file;
        iter++;
    }
    return error_code;
}

int read_data_connection(dataset &data, FILE *file_source)
{
    int rc, error_code = OK;
    int dot_1 = 0, dot_2 = 0;
    size_t iter = 0;

    error_code = read_len_from_file(data, file_source);

    while (iter < data.cnt_connections && error_code == OK)
    {
        rc = fscanf(file_source, "%d %d", &dot_1, &dot_2);
        if (rc != 3)
            error_code = ERROR_VALUE_IN_FILE;
        data.connections->index_dot_1 = dot_1;
        data.connections->index_dot_2 = dot_2;
        iter++;
    }
    return error_code;
}


int read_data_from_file(dataset data)
{
    int error_code = OK;

    FILE *file_source = fopen(FILE_SOURCE, "r");
    if (!file_source)
        error_code = ERROR_OPEN_FILE;

    error_code = read_data_points(data, file_source);
    if (error_code)
        error_code = read_data_connection(data, file_source);
    
    return error_code;
}
