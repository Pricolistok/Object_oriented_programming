#ifndef LAB_01_STRUCT_H__
#define LAB_01_STRUCT_H__

#include <cstdlib>

typedef union params
{
    struct
    {
        double dx;
        double dy;
        double dz;
    } transfer_param;
    struct
    {
        double kx;
        double ky;
        double kz;
    } scale_param;
    struct
    {
        double angle_x;
        double angle_y;
        double angle_z;
    } rotate_param;
}params;


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
