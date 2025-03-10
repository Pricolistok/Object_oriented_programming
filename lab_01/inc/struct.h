#ifndef LAB_01_STRUCT_H__
#define LAB_01_STRUCT_H__

#include <cstdlib>

typedef struct transfer_param
{
    double dx;
    double dy;
    double dz;
} transfer_param;

typedef struct scale_param
{
    double kx;
    double ky;
    double kz;
} scale_param;

typedef struct rotate_param
{
    double angle_x;
    double angle_y;
    double angle_z;
} rotate_param;


typedef union params
{
    transfer_param transferParam;
    scale_param scaleParam;
    rotate_param rotateParam;
} params;


typedef struct point
{
    double x;
    double y;
    double z;
} point;

typedef struct connection
{
    int index_dot_1;
    int index_dot_2;

} connection;


typedef struct dataset
{
    size_t cnt_points = 0;
    point *points;

    size_t cnt_connections = 0;
    connection *connections;

    bool full_data = false;
} dataset;



#endif
