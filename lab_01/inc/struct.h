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
    size_t cnt_points;
    point_t *points;
} data_points_t;

typedef struct data_connections
{
    size_t cnt_connections;
    connection *connections;
} data_connections_t;


typedef struct dataset
{
    data_points_t dataPoints;
    data_connections_t dataConnections;
} dataset_t;


typedef struct angle_rad
{
    double radX;
    double radY;
    double radZ;
} angle_rad_t;


typedef struct trigonometry_data
{
    double cosX;
    double sinX;
    double cosY;
    double sinY;
    double cosZ;
    double sinZ;
} trigonometry_data_t;


typedef struct point_draw
{
    double x;
    double y;
} point_draw_t;


typedef struct data_points_draw
{
    size_t cnt_points;
    point_draw_t *points;
} data_points_draw_t;


typedef struct dataset_draw
{
    data_points_draw dataPoints;
    data_connections_t dataConnections;
    bool full_data = false;
} dataset_draw_t;

#endif
