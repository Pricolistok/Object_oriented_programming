#ifndef LAB_01_PROCESS_H__
#define LAB_01_PROCESS_H__

#include "../inc/struct.h"
#include "../inc/utils.h"
#include "../inc/consts.h"

int transform_data(dataset_t &data, params_t data_params, mode_reset_data mode_reset);
void reset_data(data_points_t &dataPoints, params_t data_params, mode_reset_data mode_reset);

#endif
