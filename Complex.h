#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct Complex
{
    double real;
    double imaginary;
}t_complex;

//getters and setters
double getRealPart(t_complex m);
double getImaginaryPart(t_complex m);
void setRealPart(t_complex *m, double n);
void setImaginaryPart(t_complex *m, double n);

//display
void displayCompForm(t_complex comp_num);
void displayArray(t_complex array[SIZE]);

//operations
t_complex Add(t_complex a, t_complex b);
t_complex Sub(t_complex a, t_complex b);
t_complex Multiply(t_complex A, t_complex B);
t_complex Divide(t_complex A, t_complex B);

//array operations
void InitializeArray(t_complex array[SIZE]);
void Insert(t_complex array[SIZE], int index);
int IsFull(t_complex array[SIZE]);
int IsEmpty(t_complex array[SIZE]);
void Delete(t_complex array[SIZE], int index);

int menu();
#endif // COMPLEX_H_INCLUDED
