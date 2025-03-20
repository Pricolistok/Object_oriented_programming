#include <cstdio>
#include <cstdlib>
#include "struct.h"


#ifndef LAB_01_VALIDATE_DATA_H
#define LAB_01_VALIDATE_DATA_H

int validate_connection(const connection_t &connection, const int cnt_points);
int validate_connections(const data_connections_t &dataConnections, const size_t cnt_points);
int validate_dataset_connections(const data_connections_t &dataConnections, const data_points_t &dataPoints);
int validate_dataset(const dataset_t &dataset);

#endif
