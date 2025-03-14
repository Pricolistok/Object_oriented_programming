#ifndef LAB_01_PROCESS_H__
#define LAB_01_PROCESS_H__

#include "../inc/struct.h"
#include "../inc/consts.h"

//#define FILE_SOURCE "data/data_cube.txt"
#define FILE_SOURCE "data/data_pyramid.txt"
//#define FILE_SOURCE "data/data_cat.txt"


int transform_data(dataset_draw_t &data, const params_t &data_params, const mode_reset_data mode_reset);
int reset_data(dataset_t &dataset, const params_t &data_params, const mode_reset_data mode_reset);
void translate_point(point_draw_t &point_draw, const point_t point);
int translate_points(data_points_draw_t &data_draw, const data_points_t &data);
int translate_connections(data_connections_t &data_draw, const data_connections_t &data);
void free_points_arr(const data_points_t &data);
void free_connections_arr(const data_connections_t &data);
int translate_data_for_paint(dataset_draw_t &data_draw, const dataset_t &data);


#endif
