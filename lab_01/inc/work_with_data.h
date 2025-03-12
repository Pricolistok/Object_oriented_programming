#ifndef LAB_01_WORK_WITH_DATA_H
#define LAB_01_WORK_WITH_DATA_H

#include <cstdio>
#include <cstdlib>
#include "../inc/errors.h"
#include "../inc/struct.h"
#include "cmath"

int transfer_dots(data_points_t &data_set_points, const transfer_param_t transferParam);
double transformation_param_transfer(const double data, const double param);
double transformation_param_scale(const double data, const double param);
int scale_dots(data_points_t &dataset_points, const scale_param_t scaleParam);
void transformation_param_rotate(point_t &data, const trigonometry_data_t &trigonometry_data);
int rotate_dots(data_points_t &dataset_points, const rotate_param_t rotateParam);
void transform_angles(angle_rad_t &angle_mod, const rotate_param_t &rotateParam);
double transform_angle(const double angle);
void scale_dot(point_t &point, const scale_param &scaleParam);
void transfer_dot(point_t &point, const transfer_param_t &transferParam);


#endif
