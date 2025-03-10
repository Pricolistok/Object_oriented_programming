#ifndef LAB_01_UTILS_H
#define LAB_01_UTILS_H

#include <cstdio>
#include <cstdlib>
#include "struct.h"

#define FILE_SOURCE "data/data_cube.txt"

typedef enum mode_write_len
{
    CNT_POINTS,
    CNT_CONNECTIONS
} mode_write_len;


int read_len_from_file(size_t &cnt_data, FILE *file_source);
int read_data_connection(connection_t *connections, FILE *file_source, size_t cnt_connections);
int read_data_points(point_t *points, FILE *file_source, size_t cnt_points);
int read_data_from_file(dataset_t &data);


#endif
