#ifndef LAB_01_STRUCT_H__
#define LAB_01_STRUCT_H__

typedef struct params
{
    union
    {
        double dx;
        double dy;
        double dz;
    } transfer_param;
    union
    {
        double kx;
        double ky;
        double kz;
    } scale_param;
    union
    {
        double angle_x;
        double angle_y;
        double angle_z;
    } rotate_param;
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

} dataset;



#endif
