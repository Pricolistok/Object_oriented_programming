#include "../inc/errors.h"
#include "../inc/struct.h"
#include "../inc/utils.h"

// out var in

int read_len_from_file(size_t &cnt_data, FILE *file_source)
{
    int rc, error_code = OK;
    int len_data_buffer;

    if (file_source)
    {
        rc = fscanf(file_source, "%d", &len_data_buffer);
        if (rc != 1)
            error_code = ERROR_VALUE_IN_FILE;
        else if (len_data_buffer <= 0)
            error_code = ERROR_LEN_DATA;
        else
            cnt_data = len_data_buffer;
    }
    else
        error_code = ERROR_OPEN_FILE;
    return error_code;
}


int read_data_points(point_t *points, FILE *file_source, const size_t cnt_points)
{
    int error_code = OK;
    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    if (!points)
        error_code = ERROR_ADD_MEMORY;

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

int read_data_connection(connection_t *connections, FILE *file_source, const size_t cnt_connections)
{
    int error_code = OK;

    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    if (!connections)
        error_code = ERROR_ADD_MEMORY;

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

int work_with_arr_points(data_points_t &data, FILE *file_source)
{
    int error_code = OK;
    if (file_source)
    {
        data.points = (point_t *) malloc(sizeof(point_t) * data.cnt_points);
        if (data.points)
        {
            error_code = read_data_points(data.points, file_source, data.cnt_points);
            if (error_code != OK)
                free(data.points);
        }
        else
            error_code = ERROR_ADD_MEMORY;
    }
    else
        error_code = ERROR_OPEN_FILE;
    return error_code;
}


int work_with_points(data_points_t &data, FILE *file_source)
{
    int error_code = OK;
    size_t len_buffer;
    if (file_source)
    {
        error_code = read_len_from_file(len_buffer, file_source);
        if (error_code == OK)
        {
            data.cnt_points = len_buffer;
            error_code = work_with_arr_points(data, file_source);
        }
    }
    else
        error_code = ERROR_OPEN_FILE;
    return error_code;
}

int work_with_arr_connections(data_connections_t &data, FILE *file_source)
{
    int error_code = OK;
    if (file_source)
    {
        data.connections = (connection_t *) malloc(sizeof(connection_t) * data.cnt_connections);
        if (data.connections)
        {
            error_code = read_data_connection(data.connections, file_source, data.cnt_connections);
            if (error_code != OK)
                free(data.connections);
        }
        else
            error_code = ERROR_ADD_MEMORY;
    }
    else
        error_code = ERROR_OPEN_FILE;
    return error_code;
}


int work_with_connections(data_connections_t &data, FILE *file_source)
{
    int error_code = OK;
    size_t len_buffer;

    if (file_source)
    {
        error_code = read_len_from_file(len_buffer, file_source);
        if (error_code == OK)
        {
            data.cnt_connections = len_buffer;
            error_code = work_with_arr_connections(data, file_source);
        }
    }
    else
        error_code = ERROR_OPEN_FILE;

    return error_code;
}

int work_with_all_data(data_points_t &dataPoints, data_connections_t &dataConnections, FILE *file_source)
{
    int error_code = OK;
    if (file_source)
    {
        error_code = work_with_points(dataPoints, file_source);
        if (error_code == OK)
            error_code = work_with_connections(dataConnections, file_source);
    }
    else
        error_code = ERROR_OPEN_FILE;
    return error_code;
}

int read_data_from_file(dataset_t &data)
{
    int error_code = OK;

    FILE *file_source = fopen(FILE_SOURCE, "r");
    if (!file_source)
        error_code = ERROR_OPEN_FILE;

    error_code = work_with_all_data(data.dataPoints, data.dataConnections, file_source);

    fclose(file_source);
    return error_code;
}
