#include "../inc/process.h"
#include "../inc/maindrawer.h"
#include "../inc/utils.h"
#include "../inc/work_with_data.h"
#include "../inc/errors.h"
#include <cstdio>
#include <cstdlib>



void reset_data(data_points_t &dataPoints, params_t data_params, mode_reset_data mode_reset)
{
    switch (mode_reset)
    {
        case TRANSFER:
            transfer_dots(dataPoints.points, dataPoints.cnt_points, data_params.transferParam);
            break;
        case SCALE:
            scale_dots(dataPoints.points, dataPoints.cnt_points, data_params.scaleParam);
            break;
        case ROTATE:
            rotate_dots(dataPoints.points, dataPoints.cnt_points, data_params.rotateParam);
            break;
        case DRAW:
            break;
    }
}


int transform_data(dataset_t &data, params_t data_params, mode_reset_data mode_reset)
{
    int error_code = OK;

    if (!data.full_data)
    {
        error_code = read_data_from_file(data);
        if (error_code == OK)
            data.full_data = true;
    }

    if (error_code == OK)
        reset_data(data.dataPoints, data_params, mode_reset);

    return error_code;
}


