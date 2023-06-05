#include <stdio.h>
#include "funciones.h"

float calcular_det(float mat_a[3][3]) {
    float det;
    
    det = (mat_a[0][0] * mat_a[1][1] * mat_a[2][2]) +
          (mat_a[0][1] * mat_a[1][2] * mat_a[2][0]) +
          (mat_a[0][2] * mat_a[1][0] * mat_a[2][1]) -
          (mat_a[0][2] * mat_a[1][1] * mat_a[2][0]) -
          (mat_a[0][1] * mat_a[1][0] * mat_a[2][2]) -
          (mat_a[0][0] * mat_a[1][2] * mat_a[2][1]);
    
    return det;
}

void calcular_pos(float mat_a[3][3], float mat_b[3]) {
    float det_matriz = calcular_det(mat_a);
    
    if (det_matriz == 0) {
        printf("El sistema de ecuaciones no tiene solución única.\n");
        return;
    }

    float det_x[3][3] = {
        {mat_b[0], mat_a[0][1], mat_a[0][2]},
        {mat_b[1], mat_a[1][1], mat_a[1][2]},
        {mat_b[2], mat_a[2][1], mat_a[2][2]}
    };
    
    float det_y[3][3] = {
        {mat_a[0][0], mat_b[0], mat_a[0][2]},
        {mat_a[1][0], mat_b[1], mat_a[1][2]},
        {mat_a[2][0], mat_b[2], mat_a[2][2]}
    };
    
    float det_z[3][3] = {
        {mat_a[0][0], mat_a[0][1], mat_b[0]},
        {mat_a[1][0], mat_a[1][1], mat_b[1]},
        {mat_a[2][0], mat_a[2][1], mat_b[2]}
    };
    
    float det_x_val = calcular_det(det_x);
    float det_y_val = calcular_det(det_y);
    float det_z_val = calcular_det(det_z);
    
    float x = det_x_val / det_matriz;
    float y = det_y_val / det_matriz;
    float z = det_z_val / det_matriz;
    
    printf("Las posiciones son:\n");
    printf("x = %0.2f\n", x);
    printf("y = %0.2f\n", y);
    printf("z = %0.2f\n", z);
}