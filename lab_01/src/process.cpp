#include "../inc/process.h"
#include "../inc/maindrawer.h"
#include "../inc/errors.h"
#include <cstdio>
#include <cstdlib>


void print_all(dataset &data, params data_params, mode_reset_data mode_reset)
{
    int error_code = OK;
    switch (mode_reset)
    {
        case TRANSFER:
            printf("%lf -  dX\n", data_params.transfer_param.dx);
            printf("%lf -  dY\n", data_params.transfer_param.dy);
            printf("%lf -  dZ\n", data_params.transfer_param.dz);
            break;
        case SCALE:
            printf("%lf -  kX\n", data_params.scale_param.kx);
            printf("%lf -  kY\n", data_params.scale_param.ky);
            printf("%lf -  kZ\n", data_params.scale_param.kz);
            break;
        case ROTATE:
            printf("%lf -  rX\n", data_params.rotate_param.angle_x);
            printf("%lf -  rY\n", data_params.rotate_param.angle_y);
            printf("%lf -  rZ\n", data_params.rotate_param.angle_y);
            break;
    }

    if (!data.full_data)
    {
        error_code = read_data_from_file(data);
        if (error_code != OK)
            data.full_data = true;
    }}

