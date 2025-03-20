#ifndef LAB_01_UTILS_H
#define LAB_01_UTILS_H

#include <cstdio>
#include <cstdlib>
#include "struct.h"

void free_dataset_points(data_points_t &data);
void free_dataset_connections(data_connections_t &data);
void free_dataset_points_projection(data_points_projection_t &data_projection);
void free_dataset(dataset_t &dataset);
void free_dataset_projection(dataset_projection_t &dataset_projection);
connection_t *add_memory_for_connections(size_t cnt_connections);
point_t *add_memory_for_point(size_t cnt_points);
point_projection_t *add_memory_for_point_projection(size_t cnt_points);
void free_points_array(point_t *points);
void free_points_projection_array(point_projection_t *points);
void free_connections_array(connection_t *connections);


#endif
