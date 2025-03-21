#include "../inc/utils.h"
#include "../inc/errors.h"


void free_points_array(point_t *points)
{
    free(points);
}

void free_points_projection_array(point_projection_t *points)
{
    free(points);
}

void free_connections_array(connection_t *connections)
{
    free(connections);
}


void free_dataset_points(data_points_t &data)
{
    free_points_array(data.points);
}

void free_dataset_connections(data_connections_t &data)
{
    free_connections_array(data.connections);
}

void free_dataset_points_projection(data_points_projection_t &data_projection)
{
    free_points_projection_array(data_projection.points);
}

void free_dataset(dataset_t &dataset)
{
    free_dataset_points(dataset.dataPoints);
    free_dataset_connections(dataset.dataConnections);
}

void free_dataset_projection(dataset_projection_t &dataset_projection)
{
    free_dataset_points_projection(dataset_projection.dataPoints);
    free_dataset_connections(dataset_projection.dataConnections);
}

int malloc_for_connection_dataset(data_connections_t &data_tmp, const data_connections_t &data_source)
{
    return malloc_for_connections(data_tmp.connections, data_source.cnt_connections);
}


int malloc_for_connections(connection_t *&connections, size_t cnt_connections)
{
    int error_code = OK;
    if (cnt_connections <= 0)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        connections = (connection_t *) malloc(sizeof(connection_t) * cnt_connections);
        if (!connections)
            error_code = ERROR_ADD_MEMORY;
    }
    return error_code;
}


int malloc_for_point(point_t *&points, size_t cnt_points)
{
    int error_code = OK;
    if (cnt_points <= 0)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        points = (point_t *) malloc(sizeof(point_t) * cnt_points);
        if (!points)
            error_code = ERROR_ADD_MEMORY;
    }

    return error_code;
}

int malloc_for_projection_dataset(data_points_projection_t &data_projection, const data_points_t &data_source)
{
    return malloc_for_point_projection(data_projection.points, data_source.cnt_points);
}

int malloc_for_point_projection(point_projection_t *&points_projection, size_t cnt_points)
{
    int error_code = OK;
    if (cnt_points <= 0)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        points_projection = (point_projection_t *) malloc(sizeof(point_projection_t) * cnt_points);
        if (!points_projection)
            error_code = ERROR_ADD_MEMORY;
    }
    return error_code;
}
