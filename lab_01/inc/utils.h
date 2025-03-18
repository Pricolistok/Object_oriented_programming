#ifndef LAB_01_UTILS_H
#define LAB_01_UTILS_H

#include <cstdio>
#include <cstdlib>
#include "struct.h"

void free_points_arr(const data_points_t &data);
void free_connections_arr(const data_connections_t &data);
void free_points_draw(data_points_draw_t &dataset);
void free_dataset(dataset_t &dataset);
void free_dataset_draw(dataset_draw_t &dataset);


#endif
