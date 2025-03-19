#include "../inc/main_func.h"
#include "../inc/process.h"
#include "../inc/utils.h"
#include "../inc/work_with_data.h"
#include <cstdio>
#include <cstdlib>

int transform_data(dataset_draw_t &dataset_paint, const request_t &request)
{
    int error_code = OK;

    static dataset_t dataset = init_dataset();

    switch (request.command)
    {
        case TRANSFER:
            error_code = transfer_dataset(dataset, request.transferParam);
            break;
        case SCALE:
            error_code = scale_dataset(dataset, request.scaleParam);
            break;
        case ROTATE:
            error_code = rotate_dataset(dataset, request.rotateParam);
            break;
        case RELOAD:
            free_dataset(dataset);
            error_code = work_with_file(dataset, request.filename);
            break;
        case LOAD:
            error_code = work_with_file(dataset, request.filename);
            break;
        case DRAW:
            error_code = transform_data_for_paint(dataset_paint, dataset);
            break;
        case FREE:
            free_dataset(dataset);
            free_dataset_draw(dataset_paint);
            break;
        default:
            break;
    }

    return error_code;
}
