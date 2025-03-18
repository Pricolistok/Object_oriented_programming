#ifndef LAB_01_MAIN_FUNC_H
#define LAB_01_MAIN_FUNC_H

#include "../inc/struct.h"
#include "../inc/consts.h"

//#define FILE_SOURCE "data/data_cube.txt"
#define FILE_SOURCE "data/data_pyramid.txt"
//#define FILE_SOURCE "data/data_cat.txt"


int mode_transform_data(dataset_t &dataset, const params_t &data_params, const command mode_transform);
int transform_data(dataset_draw_t &data_paint, const params_t &data_params, const command mode_transform);



#endif
