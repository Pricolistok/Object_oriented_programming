#ifndef LAB_01_WORK_WITH_DATA_H
#define LAB_01_WORK_WITH_DATA_H

#include <cstdio>
#include <cstdlib>
#include "../inc/errors.h"
#include "../inc/struct.h"
#include "cmath"

int move_dots(data_points_t &dataset_points, const transfer_param_t &transferParam);
double transformation_param_transfer(const double data, const double param);
double transformation_param_scale(const double data, const double param);
int scale_dots(data_points_t &dataset_points, const scale_param_t &scaleParam);
void transformation_param_rotate(point_t &point, const trigonometry_dataset_t &trigonometry_data);
int rotate_dots(data_points_t &dataset_points, const rotate_param_t &rotateParam);
void transform_angles(angle_rad_t &angle_mod, const rotate_param_t &rotateParam);
double transform_angle(const double angle);
void scale_dot(point_t &point, const scale_param &scaleParam);
void set_trigonometry(double &cos_data, double &sin_data, double angle);
void set_trigonometry_dataset(trigonometry_dataset_t &trigonometry_dataset, const angle_rad_t &angle_mod);
void move_dot(point_t &point, const transfer_param_t &transferParam);
int move_dataset(dataset_t &dataset, const transfer_param_t &transferParam);
int rotate_dataset(dataset_t &dataset, const rotate_param_t &rotateParam);
int scale_dataset(dataset_t &dataset, const scale_param_t &scaleParam);
int rotate_array_dots(data_points_t &dataset_points, const rotate_param_t &rotateParam);


#endif
