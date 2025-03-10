#ifndef LAB_01_STRUCT_H__
#define LAB_01_STRUCT_H__

#include <cstdlib>


typedef struct transfer_param
{
    double dx;
    double dy;
    double dz;
} transfer_param_t;


typedef struct scale_param
{
    double kx;
    double ky;
    double kz;
} scale_param_t;


typedef struct rotate_param
{
    double angle_x;
    double angle_y;
    double angle_z;
} rotate_param_t;


typedef union params
{
    transfer_param_t transferParam;
    scale_param_t scaleParam;
    rotate_param_t rotateParam;
} params_t;


typedef struct point
{
    double x;
    double y;
    double z;
} point_t;

typedef struct connection
{
    int index_dot_1;
    int index_dot_2;

} connection_t;

typedef struct data_points
{
    size_t cnt_points = 0;
    point_t *points;
} data_points_t;

typedef struct data_connections
{
    size_t cnt_connections = 0;
    connection *connections;
} data_connections_t;


typedef struct dataset
{
    data_points_t dataPoints;
    data_connections_t dataConnections;
    bool full_data = false;
} dataset_t;


#endif
