#include "../inc/main_func.h"
#include "../inc/process.h"
#include "../inc/utils.h"
#include "../inc/work_with_data.h"

int transform_data(dataset_projection_t &dataset_projection, const request_t &request)
{
    int error_code = OK;

    static dataset_t dataset = init_dataset();

    switch (request.command)
    {
        case DRAW:
            error_code = transform_data_to_projection(dataset_projection, dataset);
            break;
        case MOVE:
            error_code = move_dataset(dataset, request.transferParam);
            break;
        case SCALE:
            error_code = scale_dataset(dataset, request.scaleParam);
            break;
        case ROTATE:
            error_code = rotate_dataset(dataset, request.rotateParam);
            break;
        case LOAD:
            error_code = load_file(dataset, request.filename);
            break;
        case FREE:
            free_dataset(dataset);
            free_dataset_projection(dataset_projection);
            break;
        default:
            break;
    }

    return error_code;
}
