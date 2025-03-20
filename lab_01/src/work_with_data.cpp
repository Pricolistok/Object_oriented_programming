#include "../inc/work_with_data.h"


double transformation_param_transfer(const double data, const double param)
{
    return data + param;
}

void move_dot(point_t &point, const transfer_param_t &transferParam)
{
    point.x = transformation_param_transfer(point.x, transferParam.dx);
    point.y = transformation_param_transfer(point.y, transferParam.dy);
    point.z = transformation_param_transfer(point.z, transferParam.dz);
}

int move_dots(data_points_t &dataset_points, const transfer_param_t &transferParam)
{
    int error_code = OK;
    if (!dataset_points.points)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        for (size_t i = 0; i < dataset_points.cnt_points; i++)
            move_dot(dataset_points.points[i], transferParam);
    }
    return error_code;
}

int move_dataset(dataset_t &dataset, const transfer_param_t &transferParam)
{
    return move_dots(dataset.dataPoints, transferParam);
}


double transformation_param_scale(const double data, const double param)
{
    return data * param;
}

void scale_dot(point_t &point, const scale_param_t &scaleParam)
{
    point.x = transformation_param_scale(point.x, scaleParam.kx);
    point.y = transformation_param_scale(point.y, scaleParam.ky);
    point.z = transformation_param_scale(point.z, scaleParam.kz);
}

int scale_dots(data_points_t &dataset_points, const scale_param_t &scaleParam)
{
    int error_code = OK;
    if (!dataset_points.points)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        for (size_t i = 0; i < dataset_points.cnt_points; i++)
            scale_dot(dataset_points.points[i], scaleParam);
    }
    return error_code;
}

int scale_dataset(dataset_t &dataset, const scale_param_t &scaleParam)
{
    return scale_dots(dataset.dataPoints, scaleParam);
}


void transformation_param_rotate(point_t &data, const trigonometry_dataset_t &trigonometry_data)
{
    double y1 = data.y * trigonometry_data.cosX - data.z * trigonometry_data.sinX;
    double z1 = data.y * trigonometry_data.sinX + data.z * trigonometry_data.cosX;

    double x2 = data.x * trigonometry_data.cosY + z1 * trigonometry_data.sinY;
    double z2 = z1 * trigonometry_data.cosY - data.x * trigonometry_data.sinY;

    double x3 = x2 * trigonometry_data.cosZ - y1 * trigonometry_data.sinZ;
    double y3 = x2 * trigonometry_data.sinZ + y1 * trigonometry_data.cosZ;

    data.x = x3;
    data.y = y3;
    data.z = z2;
}


double transform_angle(const double angle)
{
    return angle * M_PI / 180;
}

void transform_angles(angle_rad_t &angle_mod, const rotate_param_t &rotateParam)
{
    angle_mod.radX = transform_angle(rotateParam.angle_x);
    angle_mod.radY = transform_angle(rotateParam.angle_y);
    angle_mod.radZ = transform_angle(rotateParam.angle_z);
}

void set_trigonometry(double &cos_data, double &sin_data, double angle)
{
    cos_data = cos(angle);
    sin_data = sin(angle);
}

void set_trigonometry_dataset(trigonometry_dataset_t &trigonometry_dataset, const angle_rad_t &angle_mod)
{
    set_trigonometry(trigonometry_dataset.cosX, trigonometry_dataset.sinX, angle_mod.radX);
    set_trigonometry(trigonometry_dataset.cosY, trigonometry_dataset.sinY, angle_mod.radY);
    set_trigonometry(trigonometry_dataset.cosZ, trigonometry_dataset.sinZ, angle_mod.radZ);
}


int rotate_dots(data_points_t &dataset_points, const rotate_param_t &rotateParam)
{
    int error_code = OK;
    angle_rad_t angle_mod;
    trigonometry_dataset_t trigonometry_data;
    if (!dataset_points.points)
        error_code = ERROR_ADD_MEMORY;
    else
    {
        transform_angles(angle_mod, rotateParam);
        set_trigonometry_dataset(trigonometry_data, angle_mod);
        for (size_t i = 0; i < dataset_points.cnt_points; i++)
            transformation_param_rotate(dataset_points.points[i], trigonometry_data);
    }
    return error_code;
}

int rotate_dataset(dataset_t &dataset, const rotate_param_t &rotateParam)
{
    return rotate_dots(dataset.dataPoints, rotateParam);
}

