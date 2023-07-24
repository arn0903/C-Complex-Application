#include "Complex.h"

int main()
{

    //variable declaration
    int answer, restart, index1, index2;
    t_complex num1, num2, res;
    t_complex Cpl_numbers[SIZE];


    //initialize all elements of the array to 0
    InitializeArray(Cpl_numbers);
    do
    {
        //get answer from menu
        answer=menu();

        //initialize the result variable
        setRealPart(&res, 0);
        setImaginaryPart(&res, 0);

        //switch menu in function of the user answer
        switch(answer)
        {

        //menu 1: Addition
        case 1:
            printf("\nOperation selected Addition\nWhich numbers do you want to add?\nNumber 1: ");
            scanf("%d", &index1);   //input index of element from the array
            printf("Number 2: ");
            scanf("%d", &index2);
            num1 = Cpl_numbers[index1-1];  //set the two operands
            num2 = Cpl_numbers[index2-1];

            //call for Add function
            res=Add(num1, num2);

            //display results
            printf("\n");
            printf("The result is :\n");
            displayCompForm(res);
            printf("\n");
            displayArray(Cpl_numbers);
            printf("\n");

            restart=1;
            break;


        //menu 2: Substraction
        case 2:
            printf("\nOperation selected Substraction\nWhich numbers do you want to sub?\nNumber 1: ");
            scanf("%d", &index1);
            printf("Number 2: ");
            scanf("%d", &index2);
            num1 = Cpl_numbers[index1-1];
            num2 = Cpl_numbers[index2-1];

            //call for Sub function
            res=Sub(num1, num2);

            printf("\n");
            printf("The result is :\n");
            displayCompForm(res);
            displayArray(Cpl_numbers);
            printf("\n");

            restart=1;
            break;


        //menu 3: Multiplication
        case 3:
            printf("\nOperation selected Multiplication\nWhich numbers do you want to multiply?\nNumber 1: ");
            scanf("%d", &index1);
            printf("Number 2: ");
            scanf("%d", &index2);
            num1 = Cpl_numbers[index1-1];
            num2 = Cpl_numbers[index2-1];

            //call for Multiply function
            res=Multiply(num1, num2);

            printf("\n");
            printf("The result is :\n");
            displayCompForm(res);
            displayArray(Cpl_numbers);
            printf("\n");

            restart=1;
            break;


        //menu 4: Division
        case 4:
            printf("\nOperation selected Division\nWhich numbers do you want to divide?\nNumber 1: ");
            scanf("%d", &index1);
            printf("Number 2: ");
            scanf("%d", &index2);
            num1 = Cpl_numbers[index1-1];
            num2 = Cpl_numbers[index2-1];

            //call for Division function
            res=Divide(num1, num2);

            printf("\n");
            printf("The result is :\n");
            displayCompForm(res);
            displayArray(Cpl_numbers);
            printf("\n");

            restart=1;
            break;


        //menu 5: Insertion
        case 5:
            do
            {
                printf("Insert a new element to which location : ");
                scanf("%d", &index1); //input new element
            }
            while(index1<=0||index1>SIZE); //verify it's in the correct range

            //call for Insert function
            Insert(Cpl_numbers, index1-1);
            displayArray(Cpl_numbers);
            printf("\n");

            restart=1;
            break;


        //menu 6: Delete
        case 6:

            do
            {
                printf("Delete an element from which location : ");
                scanf("%d", &index1);
            }
            while(index1<=0||index1>SIZE);

            //call for Delete function
            Delete(Cpl_numbers, index1-1);
            displayArray(Cpl_numbers);
            printf("\n");

            restart=1;
            break;


        //menu 7: Quit
        case 7:
            printf("Goodbye\n");
            restart=0;
            break;


        //default case
        default:
            printf("Error");

        }

    }
    while (restart==1); //loop to do operations consecutively


    return 0;
}
/*
Complex Application
by Arnaud Becker
202232323
Ajou University
*/
