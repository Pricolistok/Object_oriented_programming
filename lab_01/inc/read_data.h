#ifndef LAB_01_READ_DATA_H
#define LAB_01_READ_DATA_H

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
int read_dataset_points(data_points_t &dataPoints, FILE *file_source);

int read_dataset_from_file(data_points_t &dataPoints, data_connections_t &dataConnections, FILE *file_source);
int read_dataset(dataset_t &dataset, const char *file_name);

#endif //LAB_01_READ_DATA_H
