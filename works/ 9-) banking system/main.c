#include <stdio.h>
#include <string.h>

union Person
{
    char name[50];
    char address[50];
    int phone;
};
union Loan
{
    float arr[3];
    float loanValue;
};

struct BankAccount
{
    union Person Customer;
    union Loan loans[3]; //0 amount, 1 isterestRate, 2 period
};


int listCustomers(); //returns 0 if there is no file or customer
void addCustomer (union Person Customer); //adding customer with given union Customer
float calculateLoan(float amount, int period, float interestRate);
void getReport(struct BankAccount customers[50]);
int newLoan ();

int clearBuffer();	//this function checks if the buffer is clean, if it's not clean it cleans it


void setCustomerCounter();
int getCustomerCounter();

void setLoanCounter(int customerId);
int getLoanCounter(int customerId);

int isFile(char *fileName);

struct BankAccount customers[50];

int main()
{
    int isExit = 0, select;
    int newId = getCustomerCounter();

    printf("=====================================\n");
    printf("Welcome to the Bank Management System\n");
    while(!isExit)
    {

            printf("=====================================\n");
            printf("    1. List All Customers\n");
            printf("    2. Add New Customer\n");
            printf("    3. New Loan Application\n");
            printf("    4. Report Menu\n");
            printf("    5. Exit System\n");
            scanf("%d", &select);

        if(select == 1)
        {
            int listStuation = listCustomers();
            if(listStuation == 0)
                printf("There is no customer");
        }
        else if(select == 2)
            addCustomer(customers[newId].Customer);
        else if(select == 3)
            newLoan();
        else if(select == 4)
            getReport(customers);
        else if(select == 5);
            isExit = 1;

    }


}

void getReport(struct BankAccount customers[50])
{
    FILE *f;
    int idCount, newLineNum, newLineCounter, loanCounter, pos;
    char tempC, c;

    char name[50];
    char address[50];
    int phone;
    float loanArr[3];

    f = fopen("customer.txt", "r");
    fscanf(f, "%d ", &idCount);

    for(int id=0; id<idCount; id++)
    {
        pos = 0;
        loanCounter = 0;
        newLineCounter = 0;

        newLineNum= 5*(id+1)-1;

        fscanf(f, "%s\n", name);
        fscanf(f, "%s\n", address);
        fscanf(f, "%d\n", &phone);



        printf("Customer ID = %d\n", id+1);
        printf("Customer Name = %s\n", name);
        printf("Customer Address = %s\n", address);
        printf("Customer Phone = %d\n", phone);

        rewind(f);

        do
        {
            tempC = fgetc(f);
            pos++;
            if(tempC == '\n')
                newLineCounter++;
        }while(newLineCounter < newLineNum);

        do
        {
            tempC = fgetc(f);
            if(tempC == ' ')
                loanCounter++;
        }while(tempC != '\n');

        fseek(f, pos, SEEK_SET);

        if(loanCounter != 0)
        {
            float sumLoans=0;
            printf("Loans = [");
            for(int j=0; j<loanCounter; j++)
            {
                fscanf(f, "%f ", &loanArr[j]);
                printf("%.2f + ", loanArr[j]);
                sumLoans += loanArr[j];
            }
            printf("\b\b] => %.2f\n\n", sumLoans);
        }
        else
            printf("No Loan\n\n");

        fscanf(f, "%s", name);

    }

}

int newLoan()
{
    FILE *f, *tempFile;
    int customerId, newLineNum;
    int newLineCounter = 0, loanCounter = 0, pos = 0;
    char tempC;
    union Loan loans;

    printf("Input customer id for new loan\n");
    scanf("%d",&customerId);


    if(customerId > getCustomerCounter())
    {
       printf("There is no such ID.");
        return 0;
    }

    newLineNum= 5*customerId-1;

    f = fopen("customer.txt", "r+");

    do
    {
        tempC = fgetc(f);
        pos++;
        if(tempC == '\n')
            newLineCounter++;
    }while(newLineCounter < newLineNum);

    do
    {
        tempC = fgetc(f);
        pos++;
        if(tempC == ' ')
            loanCounter++;
    }while(tempC != '\n');

    if(loanCounter != 3)
    {
        char ch;
        tempFile = fopen("temp.txt", "w");

        while ((ch = fgetc(f)) != EOF)
            fputc(ch, tempFile);

        fclose(tempFile);

        fseek(f, pos-1, SEEK_SET);


        printf("Enter an amount: ");
        scanf("%f", &loans.arr[0]);

        printf("Enter a period: ");
        scanf("%f", &loans.arr[1]);

        printf("Enter an interest rate: ");
        scanf("%f", &loans.arr[2]);

        fprintf(f, "%.2f \n", calculateLoan(loans.arr[0], loans.arr[1], loans.arr[2]));

        tempFile = fopen("temp.txt", "r");

        while ((ch = fgetc(tempFile)) != EOF)
            fputc(ch, f);

        fclose(tempFile);
        fclose(f);
        remove("temp.txt");

    }
    else
        printf("This customer cannot get any more credits.\n");

    //5n-1

}

float calculateLoan(float amount, int period, float interestRate)
{
    float loan;

    if(period != 0)
    {
        loan = amount * (1 + (interestRate/100)) * calculateLoan(1, period-1, interestRate);
        return loan;
    }
    else
        return 1;
}


void addCustomer (union Person Customer)
{
    setCustomerCounter();

    clearBuffer();


    FILE* f;
    f = fopen("customer.txt", "a");

    printf("Enter customer's name : ");
    scanf("%[^\n]%*c", Customer.name);
    fprintf(f, "%s\n", Customer.name);

    printf("Enter customer's address : ");
    scanf("%[^\n]%*c", Customer.address);
    fprintf(f, "%s\n", Customer.address);


    printf("Enter customer's phone : ");
    scanf("%d", &Customer.phone);
    fprintf(f, "%d\n", Customer.phone);

    fprintf(f,"\n,\n");


    fclose(f);
}

int listCustomers() //print 0 if there is no customers
{
    int customerCounter;
    char tempC;
    char name[50];

    if(isFile("customer.txt"))
    {
        customerCounter = getCustomerCounter();
        if(customerCounter != 0)
        {
            FILE* f;
            f = fopen("customer.txt", "r");

            for(int i=0; i<customerCounter; i++)
            {
                do
                {
                    tempC = fgetc(f);
                }while(tempC != '\n');

                fscanf(f, "%s ", name);
                printf("%d. name = %s\n", i+1, name);

                for(int i=0; i<3; i++)
                {
                    do
                    {
                        tempC = fgetc(f);
                    }while(tempC != '\n');
                }
            }
            fclose(f);
            return 1;
        }
        else
        {
            return 0;
        }

    }
    else
    {
        return 0;
    }
}

int isFile(char *fileName)
{
    FILE *isThere;
    int returnValue;
    if((isThere = fopen(fileName, "r")))
    {
        fclose(isThere);
        return 1;
    }
    else
        return 0;
}

void setCustomerCounter()
{
    FILE *f;
    int customerCounter;
    //f = fopen("customers.txt", "a+");
    if(isFile("customer.txt"))
    {
        f = fopen("customer.txt", "r+");

        customerCounter = getCustomerCounter();
        customerCounter++;

        rewind(f);
        fprintf(f, "%d\n", customerCounter);
        fclose(f);
    }
    else
    {
        f = fopen("customer.txt", "a");
        fprintf(f, "%d\n", 1);
        fclose(f);
    }

}

int getCustomerCounter()
{
    FILE *f;
    int customerCounter;

    f = fopen("customer.txt", "r+");
    rewind(f);
    fscanf(f, "%d ", &customerCounter);

    fclose(f);

    return customerCounter;
}

int clearBuffer()	//this function checks if the buffer is clean, if it's not clean it cleans it
{
	int isBufferClear=1;
	while(getchar() != '\n')
		isBufferClear++;

	if(isBufferClear)
		return 1;
	else
		return 0;
}
