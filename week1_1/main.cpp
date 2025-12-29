//复数计算
//z=(3+4i)*(5+6i)/((7-8i)*(9+2i))
#include<stdio.h>

typedef struct {
	float realpart;
	float imagpart;
}Complex;

//赋值
void assign(Complex* A, float real, float imag);
//A+B
void add(Complex* A,Complex B,Complex C);
//A-B
void minus(Complex* A, Complex B,Complex C);
//A*B
void multiply(Complex* A, Complex B,Complex C);
//A/B
void divide(Complex* A, Complex B,Complex C);

int main() {
	//输入待计算的复数
	Complex z1, z2, z3, z4;
	//存储最终的复数
	Complex z;
	//赋值
	/*for (int i = 0; i < 4; i++) {
		assign();
	}*/
	assign(&z1,3,4);
	assign(&z2,5,6);
	assign(&z3,7,-8);
	assign(&z4, 9, 2);
	
	multiply(&z,z1,z2);
	divide(&z, z, z3);
	divide(&z, z, z4);


	printf("%f %f",z.realpart,z.imagpart);
	
}

void assign(Complex* A, float real, float imag) {
	A->realpart = real;
	A->imagpart = imag;
}

void add(Complex* A, Complex B,Complex C) {
	A->realpart = B.realpart + C.realpart;
	A->imagpart = B.imagpart + C.imagpart;
}

void minus(Complex* A, Complex B, Complex C) {
	A->realpart = B.realpart - C.realpart;
	A->imagpart = B.imagpart - C.imagpart;
}

void multiply(Complex* A, Complex B, Complex C) {
	A->realpart = B.realpart * C.realpart - B.imagpart * C.realpart;
	A->imagpart = B.realpart * C.imagpart + C.realpart * B.imagpart;
}

void divide(Complex* A, Complex B, Complex C) {
	A->realpart = (B.realpart * C.realpart+B.imagpart*C.imagpart)/(C.realpart*C.realpart+C.imagpart*C.imagpart);
	A->imagpart = (B.imagpart * C.realpart+B.realpart * C.imagpart ) / (C.realpart * C.realpart + C.imagpart * C.imagpart);
}