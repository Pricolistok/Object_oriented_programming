#ifndef LAB_01_PROCESS_H__
#define LAB_01_PROCESS_H__

#include "../inc/struct.h"
#include "../inc/consts.h"

int copy_connection(connection_t &data_result, connection_t &data_source, int cnt_dots);
void transform_point_to_projection(point_projection_t &point_draw, const point_t &point_source);
int transform_points_to_projection(data_points_projection_t &data_projection, const data_points_t &data_source);
int transform_connections_to_projection(data_connections_t &data_result, const data_connections_t &data_source, const data_points_t &dataPoints);
int transform_data_to_projection(dataset_projection_t &data_projection, const dataset_t &data_source);
int load_file(dataset_t &dataset, const char *filename);
int transform_points_array_to_projection(point_projection_t *&data_projection_points, const int cnt_points_projections, const int cnt_points_source, const point_t *data_source_points);
void init_points(data_points_t &dataPoints);
void init_connections(data_connections_t &dataConnections);
void copy_dataset_projection(dataset_projection_t &data_projection, const data_points_projection_t &pointsProjection, const data_connections_t &dataConnections);
void copy_dataset(dataset_t &dataset, const dataset_t &dataset_source);
void copy_tmp_points_dataset(data_points_projection_t &data_points_projection, const data_points_projection_t &tmp_data_points);
void copy_tmp_connections_dataset(data_connections_t &data_connections_draw, const data_connections_t &tmp_data_connections);
dataset_t init_dataset();
int copy_cnt_points(data_points_projection_t &data_result, const data_points_t &data_source);
int copy_cnt_connections(data_connections_t &data_result, const data_connections_t &data_source);
int copy_cnt_points(int &cnt_result, const int &cnt_source);


#endif
