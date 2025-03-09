#include "../inc/process.h"
#include "../inc/maindrawer.h"
#include <cstdio>
#include <cstdlib>


void print_all(params data_params)
{
    printf("%lf -  dX\n", data_params.transfer_param.dx);
    printf("%lf -  dY\n", data_params.transfer_param.dy);
    printf("%lf -  dZ\n", data_params.transfer_param.dz);

    printf("%lf -  kX\n", data_params.scale_param.kx);
    printf("%lf -  kY\n", data_params.scale_param.ky);
    printf("%lf -  kZ\n", data_params.scale_param.kz);

    printf("%lf -  rX\n", data_params.rotate_param.angle_x);
    printf("%lf -  rY\n", data_params.rotate_param.angle_y);
    printf("%lf -  rZ\n", data_params.rotate_param.angle_y);

    dataset data;

    read_data_from_file(data);

    printf("%zu - l\n", data.cnt_points);
//    drawWidget.len = data.cnt_points;
//    for (size_t i = 0; i < data.cnt_points; i++)
//    {
//        drawWidget.x_data[i] = data.points[i].x;
//        drawWidget.y_data[i] = data.points[i].y;
//        printf("%lf %lf %lf\n", data.points[i].x, data.points[i].y, data.points[i].z);
    printf("%zu - l\n", data.cnt_connections);
    for (size_t i = 0; i < data.cnt_connections; i++)
        printf("%d %d\n", data.connections[i].index_dot_1, data.connections[i].index_dot_2);

}

