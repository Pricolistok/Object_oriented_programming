#include "../inc/process.h"
#include "../inc/maindrawer.h"
#include "../inc/utils.h"
#include "../inc/work_with_data.h"
#include "../inc/errors.h"
#include "../inc/read_data.h"
#include "../inc/validate_data.h"
#include <cstdio>
#include <cstdlib>


void transform_point_to_draw(point_draw_t &point_draw, const point_t point_source)
{
    point_draw.x = point_source.x;
    point_draw.y = point_source.y;
}

int transform_points_for_draw(data_points_draw_t &data_draw, const data_points_t &data_source)
{
    int error_code = OK;
    data_draw.points = (point_draw_t *) malloc(sizeof(point_draw_t) * data_source.cnt_points);
    if (!data_draw.points)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        data_draw.cnt_points = data_source.cnt_points;
        for (size_t i = 0; i < data_source.cnt_points; i++)
            transform_point_to_draw(data_draw.points[i], data_source.points[i]);
    }
    return error_code;
}

int copy_connection(connection_t &data_tmp, connection_t &data_source, size_t cnt_dots)
{
    int error_code = OK;
    if (data_source.index_dot_1 < cnt_dots && data_source.index_dot_2 < cnt_dots && data_source.index_dot_1 >= 0 && data_source.index_dot_2 >= 0)
        data_tmp = data_source;
    else
        error_code = ERROR_VALUE_IN_FILE;
    return error_code;
}

int transform_connections_to_draw(data_connections_t &data_tmp, const data_connections_t &data_source, const data_points_t &dataPoints)
{
    int error_code = OK;
    size_t iter = 0;
    data_tmp.connections = (connection_t *) malloc(sizeof(connection_t ) * data_source.cnt_connections);
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
            free(data_source.connections);
    }
    return error_code;
}


void copy_tmp_points(data_points_draw_t &data_points_draw, const data_points_draw_t &tmp_data_points)
{
    data_points_draw = tmp_data_points;
}

void copy_tmp_connections(data_connections_t &data_connections_draw, const data_connections_t &tmp_data_connections)
{
    data_connections_draw = tmp_data_connections;
}


int transform_data_for_paint(dataset_draw_t &data_draw, const dataset_t &data_source)
{
    int error_code = OK;
    dataset_draw_t tmp;
    error_code = transform_points_for_draw(tmp.dataPoints, data_source.dataPoints);
    if (error_code == OK)
    {
        error_code = transform_connections_to_draw(tmp.dataConnections, data_source.dataConnections, data_source.dataPoints);
        if (error_code != OK)
            free_points_draw(tmp.dataPoints);
        else
        {
            free_points_draw(data_draw.dataPoints);
            free_connections_arr(data_draw.dataConnections);
            copy_tmp_points(data_draw.dataPoints, tmp.dataPoints);
            copy_tmp_connections(data_draw.dataConnections, tmp.dataConnections);
        }
    }
    return error_code;
}

int work_with_file(dataset_t &dataset, const char *filename)
{
    int error_code = read_dataset(dataset, filename);
    if (error_code == OK)
        error_code = validate_dataset(dataset);
    return error_code;
}

