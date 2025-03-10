#include "../inc/errors.h"
#include "../inc/struct.h"
#include "../inc/utils.h"

// out var in

int read_len_from_file(size_t &cnt_data, FILE *file_source)
{
    int rc, error_code = OK;
    int len_data_buffer;

    if (file_source == NULL)
        error_code = ERROR_OPEN_FILE;

    if (error_code == OK)
    {
        rc = fscanf(file_source, "%d", &len_data_buffer);
        if (rc != 1)
            error_code = ERROR_VALUE_IN_FILE;
        else if (len_data_buffer <= 0)
            error_code = ERROR_LEN_DATA;
        else
            cnt_data = len_data_buffer;
    }
    return error_code;
}


int read_data_points(point *points, FILE *file_source, size_t cnt_points)
{
    int error_code = OK;
    if (file_source == NULL)
        error_code = ERROR_OPEN_FILE;

    int rc;
    double x_from_file = 0, y_from_file = 0, z_from_file = 0;
    size_t iter = 0;

    while (error_code == OK && iter < cnt_points)
    {
        rc = fscanf(file_source, "%lf %lf %lf", &x_from_file, &y_from_file, &z_from_file);
        if (rc != 3)
            error_code = ERROR_VALUE_IN_FILE;
        else
        {
            points[iter].x = x_from_file;
            points[iter].y = y_from_file;
            points[iter].z = z_from_file;
            iter++;
        }
    }
    return error_code;
}

int read_data_connection(connection *connections, FILE *file_source, size_t cnt_connections)
{
    int error_code = OK;

    if (file_source == NULL)
        error_code = ERROR_OPEN_FILE;

    int rc;
    int dot_1 = 0, dot_2 = 0;
    size_t iter = 0;

    while (iter < cnt_connections && error_code == OK)
    {
        rc = fscanf(file_source, "%d %d", &dot_1, &dot_2);
        if (rc != 2)
            error_code = ERROR_VALUE_IN_FILE;
        else
        {
            connections[iter].index_dot_1 = dot_1;
            connections[iter].index_dot_2 = dot_2;
        }
        iter++;
    }
    return error_code;
}


int read_data_from_file(dataset &data)
{
    int error_code = OK;
    size_t len_buffer = 0;

    FILE *file_source = fopen(FILE_SOURCE, "r");
    if (!file_source)
        error_code = ERROR_OPEN_FILE;

    if (!error_code)
        error_code = read_len_from_file(len_buffer, file_source);

    if (!error_code)
    {
        data.cnt_points = len_buffer;
        data.points = (point *) malloc(sizeof(point) * len_buffer);
        if (data.points)
            error_code = read_data_points(data.points, file_source, len_buffer);
        else
            error_code = ERROR_ADD_MEMORY;
    }

    if (!error_code)
        error_code = read_len_from_file(len_buffer, file_source);

    if (!error_code)
    {
        data.cnt_connections = len_buffer;
        data.connections= (connection *)malloc(sizeof(connection) * len_buffer);
        if (data.connections)
            error_code = read_data_connection(data.connections, file_source, len_buffer);
        else
        {
            error_code = ERROR_ADD_MEMORY;
            free(data.points);
        }
    }
    fclose(file_source);
    return error_code;
}
