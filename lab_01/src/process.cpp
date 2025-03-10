#include "../inc/process.h"
#include "../inc/maindrawer.h"
#include "../inc/work_with_data.h"
#include "../inc/errors.h"
#include <cstdio>
#include <cstdlib>





int transform_data(dataset &data, params data_params, mode_reset_data mode_reset)
{
    int error_code = OK;

    if (!data.full_data)
    {
        error_code = read_data_from_file(data);
        if (error_code == OK)
            data.full_data = true;
    }

    if (error_code != OK)
        return error_code;

    switch (mode_reset)
    {
        case TRANSFER:
            transfer_dots(data.points, data.cnt_points, data_params.transferParam);
            break;
        case SCALE:
            scale_dots(data.points, data.cnt_points, data_params.scaleParam);
            break;
        case ROTATE:
            rotate_dots(data.points, data.cnt_points, data_params.rotateParam);
            break;
        case DRAW:
            break;
    }
    return error_code;
}


