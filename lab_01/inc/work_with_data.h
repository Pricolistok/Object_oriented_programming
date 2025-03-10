#ifndef LAB_01_WORK_WITH_DATA_H
#define LAB_01_WORK_WITH_DATA_H

#include <cstdio>
#include <cstdlib>
#include "../inc/errors.h"
#include "../inc/struct.h"
#include "cmath"

void transfer_dots(point_t *points, size_t cnt_points, transfer_param_t transferParam);
double transformation_param_transfer(double data, double param);
double transformation_param_scale(double data, double param);
void scale_dots(point_t *points, size_t cnt_points, scale_param_t scaleParam);
void transformation_param_rotate(point_t &data, rotate_param_t param);
void rotate_dots(point_t *points, size_t cnt_points, rotate_param_t rotateParam);

#endif
