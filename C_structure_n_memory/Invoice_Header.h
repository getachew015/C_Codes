#define TRUE 1

void printDataBase();
void newInvoice();
int sizeOfDataBase();
void addInvoice();
void addInvoice2();
void deleteInvoice();
int numOfAccessToDB();
int numOfRecords();
void menu();
void clean();


struct invoice {
	int invId;
	char date[10];
	char salesAgent[30];
	char custId[7];
	char itemId[7];
	float unitPrice;
	float quantityOrdered;

};



