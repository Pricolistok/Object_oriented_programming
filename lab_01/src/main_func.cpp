#include "../inc/main_func.h"
#include "../inc/process.h"
#include "../inc/utils.h"
#include "../inc/work_with_data.h"
#include <cstdio>
#include <cstdlib>

int mode_transform_data(dataset_t &dataset, const params_t &data_params, const mode_reset_data mode_transform)
{
    int error_code = OK;
    switch (mode_transform)
    {
        case TRANSFER:
            error_code = transfer_dots(dataset.dataPoints, data_params.transferParam);
            break;
        case SCALE:
            error_code = scale_dots(dataset.dataPoints, data_params.scaleParam);
            break;
        case ROTATE:
            error_code = rotate_dots(dataset.dataPoints, data_params.rotateParam);
            break;
        case REDRAW:
            free_dataset(dataset);
            error_code = work_with_file(dataset, FILE_SOURCE);
            break;
        case LOAD:
            error_code = work_with_file(dataset, FILE_SOURCE);
            break;

    }
    return error_code;
}

int transform_data(dataset_draw_t &data_paint, const params_t &data_params, const mode_reset_data mode_transform)
{
    int error_code = OK;

    static dataset_t dataset;

    if (mode_transform == FREE)
    {
        free_dataset(dataset);
        return error_code;
    }

    error_code = mode_transform_data(dataset, data_params, mode_transform);

    if (error_code == OK)
        error_code = translate_data_for_paint(data_paint, dataset);

    return error_code;
}
