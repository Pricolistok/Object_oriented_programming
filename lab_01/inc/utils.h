#ifndef LAB_01_UTILS_H
#define LAB_01_UTILS_H

#include <cstdio>
#include <cstdlib>
#include "struct.h"


int read_len_from_file(size_t &cnt_data, FILE *file_source);

int read_connection_from_file(connection_t &connection, FILE *file_source);
int read_array_connections(connection_t *connections, FILE *file_source, const size_t cnt_connections);
int read_connections(connection_t *&connections, FILE *file_source, const size_t cnt_connections);
int read_dataset_connections(data_connections_t &data_connections, FILE *file_source);

int read_point_from_file(point_t &point, FILE *file_source);
int read_array_points(point_t *points, FILE *file_source, const size_t cnt_points);
int read_points(point_t *&points, FILE *file_source, const size_t cnt_points);
int read_dataset_points(data_points_t &data, FILE *file_source);

int read_dataset_from_file(data_points_t &dataPoints, data_connections_t &dataConnections, FILE *file_source);
int read_dataset(dataset_t &dataset, const char *file_name);


int validate_connection(const connection_t &connection, const size_t cnt_points);
int validate_connections(const connection_t *connections, const size_t cnt_points);
int validate_dataset_connections(const data_connections_t dataset, const size_t cnt_points);
void copy_cnt_points(size_t &cnt_points, const data_points_t &dataset);
int validate_dataset(const dataset_t &dataset);

void free_points_arr(const data_points_t &data);
void free_connections_arr(const data_connections_t &data);
void free_points_draw(data_points_draw_t &dataset);
void free_connections_draw(data_connections_t &dataset);
void free_dataset(dataset_t &dataset);


#endif
