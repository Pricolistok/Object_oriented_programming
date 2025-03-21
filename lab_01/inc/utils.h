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
int malloc_for_connections(connection_t *&connections, size_t cnt_connections);
int malloc_for_point(point_t *&points, size_t cnt_points);
int malloc_for_point_projection(point_projection_t *&points_projection, size_t cnt_points);
void free_points_array(point_t *points);
void free_points_projection_array(point_projection_t *points);
void free_connections_array(connection_t *connections);
int malloc_for_projection_dataset(data_points_projection_t &data_projection, const data_points_t &data_source);
int malloc_for_connection_dataset(data_connections_t &data_tmp, const data_connections_t &data_source);


#endif
