#include "../inc/validate_data.h"
#include "../inc/errors.h"
#include "../inc/struct.h"

int validate_connection(const connection_t &connection, const size_t cnt_points)
{
    if (connection.index_dot_1 < cnt_points && connection.index_dot_2 < cnt_points)
        return OK;
    return ERROR_VALUE_IN_FILE;
}

int validate_connections(const connection_t *connections, const size_t cnt_points)
{
    size_t iter = 0;
    int error_code = OK;
    if (!connections)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        while (error_code == OK && iter < cnt_points)
        {
            error_code = validate_connection(connections[iter], cnt_points);
            iter++;
        }
    }
    return error_code;
}

int validate_dataset_connections(const data_connections_t dataset, const size_t cnt_points)
{
    return validate_connections(dataset.connections, cnt_points);
}


void copy_cnt_points(size_t &cnt_points, const data_points_t &datasetPoints)
{
    cnt_points = datasetPoints.cnt_points;
}

int validate_dataset(const dataset_t &dataset)
{
    size_t cnt_points;
    copy_cnt_points(cnt_points, dataset.dataPoints);
    return validate_dataset_connections(dataset.dataConnections, cnt_points);
}