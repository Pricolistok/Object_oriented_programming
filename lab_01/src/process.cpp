#include "../inc/process.h"
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

    dataset *data = (dataset *)malloc(sizeof(dataset));
    read_data_from_file(data);
    printf("%zu - l\n", data->cnt_points);
}

