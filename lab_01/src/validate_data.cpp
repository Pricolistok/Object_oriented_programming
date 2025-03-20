#include "../inc/validate_data.h"
#include "../inc/errors.h"
#include "../inc/struct.h"

int validate_connection(const connection_t &connection, const int cnt_points)
{
    int error_code = OK;
    if (connection.index_dot_1 >= cnt_points || connection.index_dot_2 > cnt_points)
        error_code = ERROR_VALUE_IN_FILE;
    return error_code;
}

int validate_connections(const data_connections_t &dataConnections, const size_t cnt_points)
{
    size_t iter = 0;
    int error_code = OK;
    if (!dataConnections.connections)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        while (error_code == OK && iter < dataConnections.cnt_connections)
        {
            error_code = validate_connection(dataConnections.connections[iter], cnt_points);
            iter++;
        }
    }
    return error_code;
}

int validate_dataset_connections(const data_connections_t &dataConnections, const data_points_t &dataPoints)
{
    int error_code = OK;
    if (dataConnections.cnt_connections <= 0)
        error_code = ERROR_VALUE_IN_FILE;
    else
        error_code = validate_connections(dataConnections, dataPoints.cnt_points);
    return error_code;
}


int validate_dataset(const dataset_t &dataset)
{
    return validate_dataset_connections(dataset.dataConnections, dataset.dataPoints);
}
