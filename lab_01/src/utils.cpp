#include "../inc/utils.h"


void free_dataset_points_arr(data_points_t &data)
{
    free(data.points);
}

void free_dataset_connections(data_connections_t &data)
{
    free(data.connections);
}

void free_dataset_points_projection(data_points_projection_t &data_projection)
{
    free(data_projection.points);
}

void free_dataset(dataset_t &dataset)
{
    free_dataset_points_arr(dataset.dataPoints);
    free_dataset_connections(dataset.dataConnections);
}

void free_dataset_projection(dataset_projection_t &dataset_projection)
{
    free_dataset_points_projection(dataset_projection.dataPoints);
    free_dataset_connections(dataset_projection.dataConnections);
}

connection_t *add_memory_for_connections(size_t cnt_connections)
{
    if (cnt_connections <= 0)
        return NULL;
    return (connection_t*)malloc(sizeof(connection_t) * cnt_connections);
}

point_t *add_memory_for_point(size_t cnt_points)
{
    if (cnt_points <= 0)
        return NULL;
    return (point_t*)malloc(sizeof(point_t) * cnt_points);
}

point_projection_t *add_memory_for_point_projection(size_t cnt_points)
{
    if (cnt_points <= 0)
        return NULL;
    return (point_projection_t *)malloc(sizeof(point_projection_t) * cnt_points);
}

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
