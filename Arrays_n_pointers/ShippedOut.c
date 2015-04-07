#include<stdio.h>
#include<stdlib.h>
#include "myData.h"

int main(){

	int choice;
	float retValue;
	int *input;
	while(TRUE){

		printf("Enter your choice to calculate tones of products shipped \n");
		printf("Menu : \n");
		printf("\tEnter 1 to get the yearly shipping : \n");
		printf("\tEnter 2 to get shipping for category C type of products : \n");
		printf("\tEnter 3 to get shipping for a specific month of The year : \n");
		printf("\tEnter 4 to Exit : ");
		scanf("%d", &choice);
		input= &choice;
		char *time[12]  = {"January","February","March","April","May","June","July","August","September","October","November","December"};
		
	while(*input<0 || *input>4)	{
		printf("Invalid Entry\n");
		printf("Menu : \n");
		printf("\tEnter 1 to get the yearly shipping : \n");
		printf("\tEnter 2 to get shipping for category C type of products : \n");
		printf("\tEnter 3 to get shipping for a specific month of The year : \n");
		printf("\tEnter 4 to Exit : ");
		scanf("%d", &choice);
		input= &choice;
		
		}

			switch (*input) {
				case 1:
					printf("The yearly total shipping is %5.3f\n",totalShipped(shippedOut));
					break;
				case 2:
					printf("Category C product's shipping is %5.3f\n",catagCShipping(shippedOut));
					break;
				case 3:{
				int regNum;
				printf("Enter The month of the year to get it's total shipping for every Customer : \n");
				scanf("%d",&regNum);
				int *month=&regNum;
					while(*month<1 || *month>12){
					printf("Invalid month number \n");
					printf("Please enter number between 1 and 12 :");
					scanf("%d",&regNum);
					month=&regNum;
					}
				retValue=monthlyShipping(shippedOut,*month);
				printf("The total shipping for the month of %s is %5.3f :\n", time[*month-1], retValue);
					break;
				}
				case 4:
					exit(0);
					break;
				default:
					break;
			}
	}
	return 0;
}


float totalShipped(const float shippedOut[][6][12]){

	float yearlyTotal=0;
	int customer, product, month;
	for (customer = 0; customer < CUSTOMERS; customer++) {
		for (product = 0; product < PRODUCTS; product++) {
			for (month = 0; month < MONTHS; month++) {
				yearlyTotal+= *(*(*(shippedOut+customer)+product)+month);
			}
		}

	}

	 return yearlyTotal;
}


float catagCShipping(const float shippedOut[][6][12]){

	float weeklyTotal=0;
	int customer, product, month;
	//The second for loop helps to traverse the last two records of the second dimension
	for (customer = 0; customer < CUSTOMERS; customer++){
		for (product = 4; product < PRODUCTS; product++)  {
			for (month = 0;  month < MONTHS; month++) {
				weeklyTotal+=*(*(*(shippedOut+customer)+product)+month);
			}
		}
	}

	return weeklyTotal;

}

float monthlyShipping(const float shippedOut[][6][12],int n){

	int month=n-1; //assumes the user is not aware of array structure positions its elements from 0 to n-1 for array of size n
	float monthlyTotal=0;
	int product, customer;
	for (customer = 0; customer < CUSTOMERS; customer++) {
		for ( product = 0; product < PRODUCTS; product++) {
				monthlyTotal+= *(*(*(shippedOut+customer)+product)+month);//month will be fixed in the pointer arithmetic
		}
	}

	return monthlyTotal;

}
