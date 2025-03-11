#include "../inc/process.h"
#include "../inc/maindrawer.h"
#include "../inc/utils.h"
#include "../inc/work_with_data.h"
#include "../inc/errors.h"
#include <cstdio>
#include <cstdlib>


void reset_data(data_points_t &dataPoints, const params_t &data_params, const mode_reset_data mode_reset)
{
    switch (mode_reset)
    {
        case TRANSFER:
            transfer_dots(dataPoints.points, dataPoints.cnt_points, data_params.transferParam);
            break;
        case SCALE:
            scale_dots(dataPoints.points, dataPoints.cnt_points, data_params.scaleParam);
            break;
        case ROTATE:
            rotate_dots(dataPoints.points, dataPoints.cnt_points, data_params.rotateParam);
            break;
        case DRAW:
            break;
    }
}

void translate_point(point_draw_t &point_draw, const point_t point)
{
    point_draw.x = point.x;
    point_draw.y = point.y;
}

int translate_points(data_points_paint_t &data_draw, const data_points_t &data)
{
    int error_code = OK;
    data_draw.points = (point_draw_t *) malloc(sizeof(point_draw_t) * data.cnt_points);
    if (data_draw.points)
    {
        data_draw.cnt_points = data.cnt_points;
        for (size_t i = 0; i < data.cnt_points; i++)
            translate_point(data_draw.points[i], data.points[i]);
    }
    else
        error_code = ERROR_ADD_MEMORY;
    return error_code;
}


int translate_connections(data_connections_t &data_draw, const data_connections_t &data)
{
    int error_code = OK;
    data_draw.connections = (connection_t *) malloc(sizeof(connection_t ) * data.cnt_connections);
    if (data_draw.connections)
    {
        data_draw.cnt_connections = data.cnt_connections;
        for (size_t i = 0; i < data.cnt_connections; i++)
            data_draw.connections[i] = data.connections[i];
    }
    else
        error_code = ERROR_ADD_MEMORY;
    return error_code;
}

void free_points_paint_arr(const data_points_paint_t data)
{
    free(data.points);
}

void free_points_arr(const data_points_t data)
{
    free(data.points);
}

void free_connections_arr(const data_connections_t data)
{
    free(data.connections);
}

int translate_data_for_paint(dataset_draw_t &data_draw, const dataset_t &data)
{
    int error_code = OK;
    error_code = translate_points(data_draw.dataPoints, data.dataPoints);
    if (error_code == OK)
    {
        error_code = translate_connections(data_draw.dataConnections, data.dataConnections);
        if (error_code != OK)
        {
            free_points_paint_arr(data_draw.dataPoints);
            free_points_arr(data.dataPoints);
            free_connections_arr(data.dataConnections);
        }
    }
    else
    {
        free_points_arr(data.dataPoints);
        free_connections_arr(data.dataConnections);
    }
    return error_code;
}

int transform_data(dataset_draw_t &data_paint, const params_t &data_params, const mode_reset_data mode_reset)
{
    int error_code = OK;

    dataset_t data;
    if (!data_paint.full_data)
        error_code = read_data_from_file(data);

    if (error_code == OK)
    {
        reset_data(data.dataPoints, data_params, mode_reset);
        error_code = translate_data_for_paint(data_paint, data);
        if (error_code != OK)
        {
            data_paint.full_data = true;
            free_points_arr(data.dataPoints);
            free_connections_arr(data.dataConnections);
        }
    }
    return error_code;
}
