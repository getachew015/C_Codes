#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Invoice_Header.h"

//global variable on static memory of the application to hold information of the in memory database
int numOfInvoice=0, invoiceID=0, accessToDB=0;
struct invoice *tempInv;//temporary invoice for creating a new invoice dynamically
struct invoice *invList;//a structure variable to hold List of invoices in the HEAP of the application

void newInvoice(){
	numOfInvoice+=1;
	invoiceID+=1;
	tempInv = (struct invoice *) malloc(numOfInvoice* sizeof(struct invoice));
		//Accept user input for the record
		printf("This is invoice number InvNo-%d of the Daily Sales\n", invoiceID);
		tempInv->invId=invoiceID;
		printf("Insert the date mm/dd/yy : ");
		scanf("%s", tempInv->date);
		printf("Insert the Name of the Sales agent : ");
		scanf("%s",tempInv->salesAgent);
		printf("Insert custId : ");
		scanf("%s", tempInv->custId);
		printf("Insert ItemId : ");
		scanf("%s", tempInv->itemId);
		printf("Insert the Unit price : ");
		scanf("%f", &tempInv->unitPrice);
		printf("Insert the quantity Ordered : ");
		scanf("%f",&tempInv->quantityOrdered);

}

void addInvoice2(struct invoice *tempInv2){
	numOfInvoice+=1;
	invoiceID+=1;
	accessToDB+=1;
	if (numOfRecords()==0){
		invList=(struct invoice *) malloc(numOfRecords()* sizeof(struct invoice));
		memcpy(invList,tempInv2,sizeof(struct invoice));
	}
	else{
		invList=(struct invoice *)realloc(invList, numOfRecords()*sizeof(struct invoice));
		memcpy((invList+numOfRecords()-1),tempInv2,sizeof(struct invoice));

	}

}


void addInvoice(){
	accessToDB+=1;
	if (numOfRecords()==0){
		newInvoice();
		invList=(struct invoice *) malloc(numOfRecords()* sizeof(struct invoice));
		memcpy(invList,tempInv,sizeof(struct invoice));
		free(tempInv);
	}
	else{
		newInvoice();
		invList=(struct invoice *)realloc(invList, numOfRecords()*sizeof(struct invoice));
		memcpy((invList+numOfRecords()-1),tempInv,sizeof(struct invoice));
		free(tempInv);
	}

}

int sizeOfDataBase(){
	return numOfInvoice*sizeof(struct invoice);
}
void printDataBase(){

	int i=0;
	printf("**********************************************************************************************************************\n");
	printf("Inv-Num \tDate 	  \tSales-Agent  \tCust-Id\t \tItem-ID\tUnit-Price\tQuantity-Ordered\tTotal\n");
	for (i = 0; i < numOfRecords(); i++) {
		printf("%d\t\t",(invList+i)->invId);
		printf("%s\t",(invList+i)->date);
		printf("%s\t \t",(invList+i)->salesAgent);
		printf("%s\t\t",(invList+i)->custId);
		printf("%s\t",(invList+i)->itemId);
		printf("%5.2f\t\t",(invList+i)->unitPrice);
		printf("%5.2f\t\t\t",(invList+i)->quantityOrdered);
		printf("%5.2f\n",(invList+i)->unitPrice*(invList+i)->quantityOrdered);
	}
	printf("**********************************************************************************************************************\n");

}
void deleteInvoice(int invNum){
	accessToDB+=1;
//case-1 when there is only one record
	if(numOfRecords()==1){
		numOfInvoice--;
		free(invList);}
//case-2 Delete the last record
	else if(invNum==numOfInvoice-1){
		numOfInvoice--;
		invList=(struct invoice *)realloc(invList, numOfRecords()*sizeof(struct invoice));
	}
//case-3 Delete from any where from the record list in between first and last record
	else{
		/*overwrite the target memory block(the one to be deleted) of the structure list
		 *with the next memory block of the structure list. And this will create one duplicate record
		 * at the end of the database. Then reallocate a new memory block by decreasing size of DB
		 * by one. This will efficiently hold the contiguous memory block with out no garbage value in between
		 * the records and increases memory usage.
		 */

		int i;
		for (i = invNum; i < numOfRecords()-1; ++i) {
			(invList+i)->invId=(invList+i+1)->invId;
			strcpy((invList+i)->date,(invList+i+1)->date);
			strcpy((invList+i)->salesAgent,(invList+i+1)->salesAgent);
			strcpy((invList+i)->custId,(invList+i+1)->custId);
			strcpy((invList+i)->itemId,(invList+i+1)->itemId);
			(invList+i)->unitPrice=(invList+i+1)->unitPrice;
			(invList+i)->quantityOrdered=(invList+i+1)->quantityOrdered;
		}
		numOfInvoice--;
		invList=(struct invoice *)realloc(invList, numOfRecords()*sizeof(struct invoice));

	}
}
int numOfRecords(){
	return numOfInvoice;
}

int numOfAccessToDB(){
	return accessToDB;

}

void clean(){//this is to clean in memory db
free(invList);
}
