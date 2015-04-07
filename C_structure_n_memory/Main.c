/*
 * Main.c
 *
 *  Created on: Sep 27, 2014
 *      Author: dagim
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Invoice_Header.h"

struct invoice inv[10]={
		{1,"09-19-14","Roody", "ASD05","OBJ01",142.23,1500.25},
		{2,"09-20-14","Thomas", "ASD04","OBJ02",155.36,1800.25},
		{3,"09-21-14","Nikki", "ASD02","OBJ09",268.23,2700.25},
		{4,"09-22-14","Georgo", "ASX01","OBJ04",236.22,8200.25},
		{5,"09-23-14","Marcelo", "ASX02","OBJ01",142.23,9500.25},
		{6,"09-24-14","Bill", "ASX04","OBJ03",242.23,9000.25},
		{7,"09-25-14","Tiffany", "ASY02","OBJ09",266.23,2000.25},
		{8,"09-26-14","Mathew", "ASY03","OBJ05",198.23,1600.25},
		{9,"09-27-14","James", "ASY01","OBJ03", 152.23,1990.25},
		{10,"09-28-14","Nikki", "ASY05","OBJ04",172.23,9500.25},
	};
int *input;
int main(){

	
	while(TRUE){
		
		menu();

		while(*input< 1 || *input>7)	{
			printf("Invalid choice made ! \n");
			menu();
		}

			switch (*input) {
				case 1:
					if(numOfRecords()==0)
						printf("Invalid Operation On Empty DataBase !\n");
					else
						printDataBase();
					break;
				case 2:
					printf("The DataBase has Currently %d Records : \n", numOfRecords());
					break;
				case 3:
					printf("Current Size of the Database is %d Bytes : \n", sizeOfDataBase() );
					break;
				case 4:{
					int number;
					printf("Enter 1 to load Previous Record From file or Enter 2 to Add a New Invoice : ");
					scanf("%d",&number);
					while(number < 1 || number > 2){
					printf("Invalid Choice Made \n Please enter either 1 or 2 : ");
					scanf("%d", &number);
					}
					if(number==2)
					addInvoice();
					else{
						int i=0;
						for (i = 0; i < 10; ++i) {
							addInvoice2(inv+i);//iterate through the array of structs
						}
					}

					break;
				}
				case 5:{
					if(numOfRecords()==0)
						printf("Invalid Operation On Empty DataBase !\n");
					else {
					int number;
					printf("Insert invoice Id to Delete associated Record : ");
					scanf("%d",&number);
					while(number < 1 || number > numOfRecords()){
						printf("Invalid Invoice Id \n Please insert numbers between 1 and %d : ", numOfRecords());
						scanf("%d", &number);
					}
					deleteInvoice(number-1);
					printf("Record Number %d Has been sucessfully Deleted \n", number);}
				}
					break;
				case 6:
					
					printf("The Database has been modified %d times : \n", numOfAccessToDB() );
					break;
				case 7:
					clean();//cleans all memory blocks before exit
					exit(0);
					break;
				default:
					break;
			}
	}

	return 0;
}

	void menu(){
		int choice=0;
		
		printf("Enter your choice to Operate On The Invoice Database \n");
		printf("Menu : \n");
		printf("\tEnter 1 to Print Invoices in the Database: \n");
		printf("\tEnter 2 to Print Number Of Invoices : \n");
		printf("\tEnter 3 to Print Size Of DataBase : \n");
		printf("\tEnter 4 to Add a new Invoice : \n");
		printf("\tEnter 5 to Delete Invoice : \n");
		printf("\tEnter 6 to Print Print Number Of Access to the DataBase : \n");
		printf("\tEnter 7 to Exit : \t");
		scanf("%d", &choice);
		input= &choice;
}

