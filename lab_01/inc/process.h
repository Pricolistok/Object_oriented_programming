#ifndef LAB_01_PROCESS_H__
#define LAB_01_PROCESS_H__

#include "../inc/struct.h"
#include "../inc/consts.h"


int transform_data(dataset_draw_t &dataset_paint, const params_t &data_params, const command mode_transform);
void transform_point_to_draw(point_draw_t &point_draw, const point_t point_source);
int transform_points_for_draw(data_points_draw_t &data_draw, const data_points_t &data_source);
int transform_connections_to_draw(data_connections_t &data_tmp, const data_connections_t &data_source, const data_points_t &dataPoints);
void free_points_arr(const data_points_t &data);
void free_connections_arr(const data_connections_t &data);
int transform_data_for_paint(dataset_draw_t &data_draw, const dataset_t &data_source);
int work_with_file(dataset_t &dataset, const char *filename);


#endif
