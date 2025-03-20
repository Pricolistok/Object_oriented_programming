#include "../inc/process.h"
#include "../inc/maindrawer.h"
#include "../inc/utils.h"
#include "../inc/work_with_data.h"
#include "../inc/errors.h"
#include "../inc/read_data.h"
#include "../inc/validate_data.h"
#include <cstdio>
#include <cstdlib>


void transform_point_to_projection(point_projection_t &point_draw, const point_t &point_source)
{
    point_draw.x = point_source.x;
    point_draw.y = point_source.y;
}

int transform_points_array_to_projection(data_points_projection_t &data_projection, const data_points_t &data_source)
{
    int error_code = OK;

    if (!data_projection.points || !data_source.points)
        error_code = ERROR_ADD_MEMORY;
    else if (data_projection.cnt_points <= 0 || data_source.cnt_points <= 0)
        error_code = ERROR_LEN_DATA;
    if (error_code != OK)
        return error_code;

    for (size_t i = 0; i < data_source.cnt_points; i++)
        transform_point_to_projection(data_projection.points[i], data_source.points[i]);

    return error_code;
}

int transform_points_to_projection(data_points_projection_t &data_projection, const data_points_t &data_source)
{
    int error_code = OK;
    data_projection.points = add_memory_for_point_projection(data_source.cnt_points);
    if (!data_projection.points)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        data_projection.cnt_points = data_source.cnt_points;
        error_code = transform_points_array_to_projection(data_projection, data_source);
    }
    return error_code;
}

int copy_connection(connection_t &data_tmp, connection_t &data_source, int cnt_dots)
{
    int error_code = OK;
    if (data_source.index_dot_1 < cnt_dots && data_source.index_dot_2 < cnt_dots && data_source.index_dot_1 >= 0 && data_source.index_dot_2 >= 0)
        data_tmp = data_source;
    else
        error_code = ERROR_VALUE_IN_FILE;
    return error_code;
}

int transform_connections_to_projection(data_connections_t &data_tmp, const data_connections_t &data_source, const data_points_t &dataPoints)
{
    int error_code = OK;
    size_t iter = 0;
    data_tmp.connections = add_memory_for_connections(data_source.cnt_connections);
    if (!data_tmp.connections)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        data_tmp.cnt_connections = data_source.cnt_connections;
        while (error_code == OK && iter < data_source.cnt_connections)
        {
            error_code = copy_connection(data_tmp.connections[iter], data_source.connections[iter], dataPoints.cnt_points);
            iter++;
        }
        if (error_code != OK)
            free_connections_array(data_source.connections);
    }
    return error_code;
}


void copy_tmp_points(data_points_projection_t &data_points_projection, const data_points_projection_t &tmp_data_points)
{
    data_points_projection = tmp_data_points;
}

void copy_tmp_connections(data_connections_t &data_connections_draw, const data_connections_t &tmp_data_connections)
{
    data_connections_draw = tmp_data_connections;
}


void copy_dataset_projection(dataset_projection_t &data_projection, const dataset_projection_t &source)
{
    copy_tmp_points(data_projection.dataPoints, source.dataPoints);
    copy_tmp_connections(data_projection.dataConnections, source.dataConnections);
}


int transform_data_to_projection(dataset_projection_t &data_projection, const dataset_t &data_source)
{
    int error_code = OK;
    dataset_projection_t tmp;
    error_code = transform_points_to_projection(tmp.dataPoints, data_source.dataPoints);
    if (error_code == OK)
    {
        error_code = transform_connections_to_projection(tmp.dataConnections, data_source.dataConnections,
                                                         data_source.dataPoints);
        if (error_code != OK)
            free_dataset_points_projection(tmp.dataPoints);
        else
        {
            free_dataset_projection(data_projection);
            copy_dataset_projection(data_projection, tmp);
        }
    }
    return error_code;
}

int check_points(data_points_t &dataPoints)
{
    return dataPoints.points == NULL;
}

int check_connections(data_connections_t &dataConnections)
{
    return dataConnections.connections == NULL;
}

void copy_dataset(dataset_t &dataset, const dataset_t &dataset_source)
{
    if (!check_points(dataset.dataPoints))
        free_dataset_points(dataset.dataPoints);
    if (!check_connections(dataset.dataConnections))
        free_dataset_connections(dataset.dataConnections);
    dataset.dataPoints = dataset_source.dataPoints;
    dataset.dataConnections = dataset_source.dataConnections;
}


int load_file(dataset_t &dataset, const char *filename)
{
    dataset_t tmp;
    int error_code = read_dataset(tmp, filename);
    if (error_code == OK)
    {
        error_code = validate_dataset(tmp);
        if (error_code == OK)
            copy_dataset(dataset, tmp);
        else
            free_dataset(tmp);
    }
    return error_code;
}

void init_points(data_points_t &dataPoints)
{
    dataPoints.cnt_points = 0;
    dataPoints.points = NULL;
}

void init_connections(data_connections_t &dataConnections)
{
    dataConnections.cnt_connections = 0;
    dataConnections.connections = NULL;
}

dataset_t init_dataset()
{
    dataset_t dataset;
    init_points(dataset.dataPoints);
    init_connections(dataset.dataConnections);
    return dataset;
}

