#include "../inc/read_data.h"
#include "../inc/errors.h"
#include "../inc/utils.h"


int read_len_from_file(size_t &cnt_data, FILE *file_source)
{
    int rc, error_code = OK;

    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    else
    {
        rc = fscanf(file_source, "%zu", &cnt_data);
        if (rc != 1)
            error_code = ERROR_VALUE_IN_FILE;
        else if (cnt_data <= 0)
            error_code = ERROR_LEN_DATA;
    }
    return error_code;
}

int read_point_from_file(point_t &point, FILE *file_source)
{
    int error_code = OK, rc;
    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    else
    {
        rc = fscanf(file_source, "%lf %lf %lf", &point.x, &point.y, &point.z);
        if (rc != 3)
            error_code = ERROR_VALUE_IN_FILE;
    }
    return error_code;
}

int read_array_points(point_t *points, FILE *file_source, const size_t cnt_points)
{
    int error_code = OK;

    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    else if (!points)
        error_code = ERROR_ADD_MEMORY;
    if (error_code != OK)
        return error_code;

    size_t iter = 0;

    while (error_code == OK && iter < cnt_points)
    {
        error_code = read_point_from_file(points[iter], file_source);
        iter++;
    }
    return error_code;
}

int read_points(point_t *&points, FILE *file_source, const size_t cnt_points)
{
    int error_code = OK;
    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    else
    {
        points = add_memory_for_point(cnt_points);
        if (!points)
            error_code = ERROR_OPEN_FILE;
        else
        {
            error_code = read_array_points(points, file_source, cnt_points);
            if (error_code != OK)
                free_points_array(points);
        }
    }
    return error_code;
}

int read_dataset_points(data_points_t &dataPoints, FILE *file_source)
{
    int error_code = OK;
    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    else
    {
        error_code = read_len_from_file(dataPoints.cnt_points, file_source);
        if (error_code == OK)
            error_code = read_points(dataPoints.points, file_source, dataPoints.cnt_points);
    }
    return error_code;
}

int read_connection_from_file(connection_t &connection, FILE *file_source)
{
    if (!file_source)
        return ERROR_OPEN_FILE;
    int rc, error_code = OK;

    rc = fscanf(file_source, "%d %d", &connection.index_dot_1, &connection.index_dot_2);
    if (rc != 2)
        error_code = ERROR_VALUE_IN_FILE;
    if (connection.index_dot_1 < 0 || connection.index_dot_2 < 0)
        error_code = ERROR_VALUE_IN_FILE;

    return error_code;
}


int read_array_connections(connection_t *connections, FILE *file_source, const size_t cnt_connections)
{
    int error_code = OK;
    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    else if (!connections)
        error_code = ERROR_ADD_MEMORY;
    if (error_code != OK)
        return error_code;

    size_t iter = 0;

    while (error_code == OK && iter < cnt_connections)
    {
        error_code = read_connection_from_file(connections[iter], file_source);
        iter++;
    }
    return error_code;
}

int read_connections(connection_t *&connections, FILE *file_source, const size_t cnt_connections)
{
    int error_code = OK;
    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    else
    {
        connections = add_memory_for_connections(cnt_connections);
        if (!connections)
            error_code = ERROR_ADD_MEMORY;
        else
        {
            error_code = read_array_connections(connections, file_source, cnt_connections);
            if (error_code != OK)
                free_connections_array(connections);
        }
    }
    return error_code;
}


int read_dataset_connections(data_connections_t &data_connections, FILE *file_source)
{
    int error_code = OK;

    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    else
    {
        error_code = read_len_from_file(data_connections.cnt_connections, file_source);
        if (error_code == OK)
            error_code = read_connections(data_connections.connections, file_source, data_connections.cnt_connections);
    }

    return error_code;
}


int read_dataset_from_file(data_points_t &dataPoints, data_connections_t &dataConnections, FILE *file_source)
{
    int error_code = OK;
    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    else
    {
        error_code = read_dataset_points(dataPoints, file_source);
        if (error_code == OK)
        {
            error_code = read_dataset_connections(dataConnections, file_source);
            if (error_code != OK)
                free_dataset_points_arr(dataPoints);
        }
    }

    return error_code;
}


int read_dataset(dataset_t &dataset, const char *file_name)
{
    int error_code = OK;

    if (!file_name)
        return ERROR_OPEN_FILE;

    FILE *file_source = fopen(file_name, "r");
    if (!file_source)
        error_code = ERROR_OPEN_FILE;
    else
    {
        error_code = read_dataset_from_file(dataset.dataPoints, dataset.dataConnections, file_source);
        fclose(file_source);
    }

    return error_code;
}
