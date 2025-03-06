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


#endif
