#include "../inc/work_with_data.h"


double transformation_param_transfer(const double data, const double param)
{
    return data + param;
}

void transfer_dot(point_t &point, const transfer_param_t &transferParam)
{
    point.x = transformation_param_transfer(point.x, transferParam.dx);
    point.y = transformation_param_transfer(point.y, -transferParam.dy);
    point.z = transformation_param_transfer(point.z, transferParam.dz);
}

void transfer_dots(point_t *points, const size_t cnt_points, const transfer_param_t transferParam)
{
    for (size_t i = 0; i < cnt_points; i++)
        transfer_dot(points[i], transferParam);
}


double transformation_param_scale(const double data, const double param)
{
    return data * param;
}

void scale_dot(point_t &point, const scale_param &scaleParam)
{
    point.x = transformation_param_scale(point.x, scaleParam.kx);
    point.y = transformation_param_scale(point.y, scaleParam.ky);
    point.z = transformation_param_scale(point.z, scaleParam.kz);
}

void scale_dots(point_t *points, const size_t cnt_points, const scale_param_t scaleParam)
{
    for (size_t i = 0; i < cnt_points; i++)
        scale_dot(points[i], scaleParam);
}

void transformation_param_rotate(point_t &data, const trigonometry_data_t &trigonometry_data)
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
//    printf("%lf %lf %lf\n", rotateParam.angle_x, rotateParam.angle_y, rotateParam.angle_z);
    angle_mod.radX = transform_angle(rotateParam.angle_x);
    angle_mod.radY = transform_angle(rotateParam.angle_y);
    angle_mod.radZ = transform_angle(rotateParam.angle_z);
}

void set_trigonometry_data(trigonometry_data_t &trigonometry_data, const angle_rad_t &angle_mod)
{
    trigonometry_data.cosX = cos(angle_mod.radX);
    trigonometry_data.sinX = sin(angle_mod.radX);

    trigonometry_data.cosY = cos(angle_mod.radY);
    trigonometry_data.sinY= sin(angle_mod.radY);

    trigonometry_data.cosZ = cos(angle_mod.radZ);
    trigonometry_data.sinZ = sin(angle_mod.radZ);
}


void rotate_dots(point_t *points, const size_t cnt_points, const rotate_param_t rotateParam)
{
    angle_rad_t angle_mod;
    trigonometry_data_t trigonometry_data;
    transform_angles(angle_mod, rotateParam);
    set_trigonometry_data(trigonometry_data, angle_mod);
    for (size_t i = 0; i < cnt_points; i++)
        transformation_param_rotate(points[i], trigonometry_data);
}

