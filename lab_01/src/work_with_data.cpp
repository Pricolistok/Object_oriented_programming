#include "../inc/work_with_data.h"


double transformation_param_transfer(double data, double param)
{
    return data + param;
}


void transfer_dots(point_t *points, size_t cnt_points, transfer_param_t transferParam)
{
    for (size_t i = 0; i < cnt_points; i++)
    {
        points[i].x = transformation_param_transfer(points[i].x, transferParam.dx);
        points[i].y = transformation_param_transfer(points[i].y, -transferParam.dy);
        points[i].z = transformation_param_transfer(points[i].z, transferParam.dz);
    }
}

double transformation_param_scale(double data, double param)
{
    return data * param;
}


void scale_dots(point_t *points, size_t cnt_points, scale_param_t scaleParam)
{
    for (size_t i = 0; i < cnt_points; i++)
    {
        points[i].x = transformation_param_scale(points[i].x, scaleParam.kx);
        points[i].y = transformation_param_scale(points[i].y, scaleParam.ky);
        points[i].z = transformation_param_scale(points[i].z, scaleParam.kz);
    }
}

void transformation_param_rotate(point_t &data, rotate_param_t param)
{
    double radX = param.angle_x * M_PI / 180;
    double radY = param.angle_y * M_PI / 180;
    double radZ = param.angle_z * M_PI / 180;

    double cosX = cos(radX), sinX = sin(radX);
    double cosY = cos(radY), sinY = sin(radY);
    double cosZ = cos(radZ), sinZ = sin(radZ);

    double y1 = data.y * cosX - data.z * sinX;
    double z1 = data.y * sinX + data.z * cosX;

    double x2 = data.x * cosY + z1 * sinY;
    double z2 = z1 * cosY - data.x * sinY;

    double x3 = x2 * cosZ - y1 * sinZ;
    double y3 = x2 * sinZ + y1 * cosZ;

    data.x = x3;
    data.y = y3;
    data.z = z2;
}


void rotate_dots(point_t *points, size_t cnt_points, rotate_param_t rotateParam)
{
    for (size_t i = 0; i < cnt_points; i++)
        transformation_param_rotate(points[i], rotateParam);
}

