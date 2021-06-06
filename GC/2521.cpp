#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double ** create_vector(double x, double y, double z) {
	double ** m = (double **) malloc(sizeof(double *));
	m[0] = (double *) malloc(sizeof(double) * 4);
	m[0][0] = x;
	m[0][1] = y;
	m[0][2] = z;
	m[0][3] = 1;
	return m;
}

double x_rot[][4] = {{1,  0,  0, 0},
					 {0, -1, -1, 0},
					 {0, -1, -1, 0},
					 {0,  0,  0, 1}};

void x_rotation_matrix(double angle) {
	double radians = 2 * M_PI / 360 * angle;
	double cos_ = cos(radians);
	double sin_ = sin(radians);
	x_rot[1][1] = cos_;
	x_rot[1][2] = sin_;
	x_rot[2][1] = -sin_;
	x_rot[2][2] = cos_;
}

double y_rot[][4] =	{{-1, 0, -1, 0},
					 { 0, 1,  0, 0},
					 {-1, 0, -1, 0},
					 { 0, 0,  0, 1}};

void y_rotation_matrix(double angle) {
	double radians = 2 * M_PI / 360 * angle;
	double cos_ = cos(radians);
	double sin_ = sin(radians);
	y_rot[0][0] = cos_;
	y_rot[0][2] = -sin_;
	y_rot[2][0] = sin_;
	y_rot[2][2] = cos_;
}

double ** matrix_multiplication(double ** mat1, double mat2[][4]) {
	double ** mat = (double **) malloc(sizeof(double *) * 1);
	for (int i = 0; i < 1; i++) {
		mat[i] = (double *) malloc(sizeof(double) * 4);
	}
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				mat[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return mat;
}

int R, LA, LO;

double get_value(double v) {
	if (abs(v) < 2e-7){
		return 0;
	}
	return v;
}

int main() {
	while (scanf("%d %d %d ", &R, &LA, &LO) != EOF) {
		double ** pointer = create_vector(0, 0, -R);
		x_rotation_matrix(LA);
		y_rotation_matrix(-LO);
		pointer = matrix_multiplication(pointer, x_rot);
		pointer = matrix_multiplication(pointer, y_rot);
		double * res = pointer[0];
		res[0] = get_value(res[0]);
		res[1] = get_value(res[1]);
		res[2] = get_value(res[2]);
		printf("%0.2lf %0.2lf %0.2lf\n", res[0], res[1], res[2]);
	}
	return 0;
}