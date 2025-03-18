#include "../inc/utils.h"


void free_points_arr(const data_points_t &data)
{
    free(data.points);
}

void free_connections_arr(const data_connections_t &data)
{
    free(data.connections);
}

void free_points_draw(data_points_draw_t &dataset)
{
    free(dataset.points);
}

void free_dataset(dataset_t &dataset)
{
    free_points_arr(dataset.dataPoints);
    free_connections_arr(dataset.dataConnections);
}

void free_dataset_draw(dataset_draw_t &dataset)
{
    free_points_draw(dataset.dataPoints);
    free_connections_arr(dataset.dataConnections);
}
