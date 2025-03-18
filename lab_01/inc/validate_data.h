#include <cstdio>
#include <cstdlib>
#include "struct.h"


#ifndef LAB_01_VALIDATE_DATA_H
#define LAB_01_VALIDATE_DATA_H

int validate_connection(const connection_t &connection, const size_t cnt_points);
int validate_connections(const connection_t *connections, const size_t cnt_points);
int validate_dataset_connections(const data_connections_t dataset, const size_t cnt_points);
void copy_cnt_points(size_t &cnt_points, const data_points_t &dataset);
int validate_dataset(const dataset_t &dataset);

#endif
