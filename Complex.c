#include "Complex.h"


///getters
double getRealPart(t_complex m)
{
    return m.real;
}

double getImaginaryPart(t_complex m)
{
    return m.imaginary;
}

///setters
void setRealPart(t_complex *m, double n)
{
    m->real = n;
}

void setImaginaryPart(t_complex *m, double n)
{
    m->imaginary = n;
}

///function to dump a complex number in cartesian form
void displayCompForm(t_complex comp_num)
{
    printf("%.2f i %.2f\n", comp_num.real, comp_num.imaginary);
}

///function to add two complex numbers
t_complex Add(t_complex a, t_complex b)
{
    t_complex sum;
    sum.real = a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;

    return sum;
}

///function to substract two complex numbers
t_complex Sub(t_complex a, t_complex b)
{
    t_complex dif;
    dif.real = a.real - b.real;
    dif.imaginary = a.imaginary - b.imaginary;

    return dif;
}

///function to multiply two complex numbers
t_complex Multiply(t_complex A, t_complex B)
{
    t_complex product;
    product.real = (A.real*B.real - A.imaginary*B.imaginary);
    product.imaginary = (A.real*B.imaginary + A.imaginary*B.real);

    return product;
}

///function to divide two complex numbers
t_complex Divide(t_complex A, t_complex B)
{
    t_complex quotient, conjugate;
    double R;

    //define the conjugate as the opposite of the complex part of the denominator
    conjugate.real = B.real;
    conjugate.imaginary = -(B.imaginary);

    //multiply by the conjugate
    quotient = Multiply(A, conjugate);

    //define mathematically the real part
    R = (B.real*B.real + B.imaginary*B.imaginary);

    //divide both parts by R
    quotient.real /= R;
    quotient.imaginary /= R;

    return quotient;

}

///function to initialize the array
void InitializeArray(t_complex array[SIZE])
{
    int i;

    for(i=0; i<SIZE; i++)
    {
        array[i].real =0;
        array[i].imaginary = 0;
    }

    /*
    t_complex temp;
    for(i=0; i<2; i++)
    {
        scanf("%lf", &temp.real);
        scanf("%lf", &temp.imaginary);
        setRealPart(&array[i], temp.real);
        setImaginaryPart(&array[i], temp.imaginary);

    }
    */

}

///function to display the array
void displayArray(t_complex array[SIZE])
{
    int i;

    printf("\n\n-----------------------\n");
    for(i=0; i<SIZE; i++)
    {
        printf("number %d\n", i+1);
        displayCompForm(array[i]);    //use of the other display function
    }
    printf("-----------------------\n");
}

///function to check if the array is full
int IsFull(t_complex array[SIZE])
{
    int i, counter=0;
    for(i=0; i<SIZE; i++)
    {
        //loop all elements in the array and check if value is equal to 0
        if((array[i].real==0)&&(array[i].imaginary==0)){
            counter++; //increment flag
        }

    }
    if(counter==0)  //can't use bool in c
        return 1;
    else
        return 0;
}

///function to insert an element in the array
void Insert(t_complex array[SIZE], int index)
{
    t_complex new_insert;
    int i, isfull;
    double a, b;

    //input of the new number
    printf("Select the real part: ");
    scanf("%lf", &a);
    printf("Select the complex part: ");
    scanf("%lf", &b);

    setRealPart(&new_insert, a);
    setImaginaryPart(&new_insert, b);

    //check with the function above
    isfull = IsFull(array);

    if(isfull==1)
        printf("The array is full, cannot add new elements\n");
    else
    {
        //shifting operation
        for(i=SIZE-1; i>=index; i--)
        {
            array[i+1]=array[i];
        }

        array[index] = new_insert;

    }

}

///function to check if the array is empty
int IsEmpty(t_complex array[SIZE])
{
    int i, counter=0;
    for(i=0; i<SIZE; i++)
    {
        if((array[i].real!=0)&&(array[i].imaginary!=0)){
            counter++;
        }

    }


    if(counter==0)
        return 1;
    else
        return 0;

}

///function to delete an element in the array
void Delete(t_complex array[SIZE], int index)
{

    int i, isempty;

    //check with the function above
    isempty = IsEmpty(array);
    if(isempty==1)
        printf("The array is empty\n");
    else
    {
        //shifting operation
        for(i=index; i<=SIZE-1; i++)
        {
            array[i]=array[i+1];
        }
    }

}

///function for the menu
int menu()
{
    int choice;

    printf("1.add two Complex\n");
    printf("2.sub two Complex\n");
    printf("3.multiply two Complex\n");
    printf("4.divide two Complex\n");
    printf("5.Insert a new element to the array\n");
    printf("6.Delete an element from the array\n");
    printf("7.quit\n");


    do {
    printf("Your choice: ");
    scanf("%d",&choice);

    if ((choice<1)||(choice>7))
        printf("please insert a correct value\n");

    }while ((choice<1)||(choice>7));

    return choice;

}



