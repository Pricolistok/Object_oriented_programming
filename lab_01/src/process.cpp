#include "../inc/process.h"
#include "../inc/maindrawer.h"
#include "../inc/utils.h"
#include "../inc/work_with_data.h"
#include "../inc/errors.h"
#include <cstdio>
#include <cstdlib>


void translate_point(point_draw_t &point_draw, const point_t point)
{
    point_draw.x = point.x;
    point_draw.y = point.y;
}

int translate_points(data_points_draw_t &data_draw, const data_points_t &data)
{
    int error_code = OK;
    data_draw.points = (point_draw_t *) malloc(sizeof(point_draw_t) * data.cnt_points);
    if (!data_draw.points)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        data_draw.cnt_points = data.cnt_points;
        for (size_t i = 0; i < data.cnt_points; i++)
            translate_point(data_draw.points[i], data.points[i]);
    }
    return error_code;
}


int translate_connections(data_connections_t &data_draw, const data_connections_t &data)
{
    int error_code = OK;
    data_draw.connections = (connection_t *) malloc(sizeof(connection_t ) * data.cnt_connections);
    if (!data_draw.connections)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        data_draw.cnt_connections = data.cnt_connections;
        for (size_t i = 0; i < data.cnt_connections; i++)
            data_draw.connections[i] = data.connections[i];
    }
    return error_code;
}

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

void free_connections_draw(data_connections_t &dataset)
{
    free(dataset.connections);
}

void copy_tmp_points(data_points_draw_t &data_draw, const data_points_draw_t &tmp)
{
    data_draw = tmp;
}

void copy_tmp_connections(data_connections_t &data_draw, const data_connections_t &tmp)
{
    data_draw = tmp;
}



int translate_data_for_paint(dataset_draw_t &data_draw, const dataset_t &data)
{
    int error_code = OK;
    dataset_draw_t tmp;
    error_code = translate_points(tmp.dataPoints, data.dataPoints);
    if (error_code == OK)
    {
        error_code = translate_connections(tmp.dataConnections, data.dataConnections);
        if (error_code != OK)
            free_points_draw(tmp.dataPoints);
        else
        {
            free_points_draw(data_draw.dataPoints);
            free_connections_draw(data_draw.dataConnections);
            copy_tmp_points(data_draw.dataPoints, tmp.dataPoints);
            copy_tmp_connections(data_draw.dataConnections, tmp.dataConnections);
        }
    }
    return error_code;
}

void free_dataset(dataset_t &dataset)
{
    free_points_arr(dataset.dataPoints);
    free_connections_arr(dataset.dataConnections);
}
