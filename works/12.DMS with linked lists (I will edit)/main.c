#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50 //Actually I was prefer dynamically but when reading from file it was being problems in dynamic memory that's why I used that

typedef struct table
{
	char tableName[MAX];
	char field[MAX][MAX];
	char type[MAX][MAX];
	int isNull[MAX];
	int isKey[MAX];
	int fieldCount;
	int rowCount;
	int maxRowSize;
	char values[MAX][MAX][MAX];
}table;

typedef struct tables
{
	struct tables *next;
	table * t;
}tables;

typedef struct database
{
	tables * tList; /* to be implemented as a linked list */
	int n; /* num of entries */
	char name[MAX]; /* table name */
}database;


database* create_database(char *name);
table* create_table();
void insert_table(database *d, table *t);
void show_table(database *d);
void desc_table(database *d, table *t);
void remove_table(database *d, char *name);
int insert_row(database *d, char *tableName);
void select_from(database *d, char *tableName);

void save_as_binary(database *d);
database* read_database_from_binfile();

//void insert_key(database *d, table *t, key_value);


int main()
{
	database *d = create_database("Pet");

	table *t;
	t = (table*)malloc(sizeof(table));
	t = create_table();

	insert_table(d, t);

	table *t2;
	t2 = (table*)malloc(sizeof(table));
	t2 = create_table();

	insert_table(d, t2);

	table *t3;
	t3 = (table*)malloc(sizeof(table));
	t3 = create_table();

	insert_table(d, t3);

	//desc_table(d, t2);

	insert_row(d, "mete");
	insert_row(d, "ahmet");
	insert_row(d, "mete");


	show_table(d);


	save_as_binary(d);

	database *d2 = read_database_from_binfile();
	select_from(d2, "mete");
	show_table(d2);
	select_from(d2, "ahmet");



}

database* read_database_from_binfile()
{
	FILE *text = fopen("db.bin", "rb");
	
    table *t;
	t = (table*)malloc(sizeof(table));

	char dbName[MAX];
	fread(dbName, sizeof(char*), 1, text);
	database *db = create_database(dbName);
    int cnt=0 ;
    while( fread(t, sizeof(table), 1, text) > 0 ) {
        insert_table(db, t);
		t = NULL;
		t = (table*)malloc(sizeof(table));
        cnt++ ;
    }
    	printf("%s\n", db->tList->t->tableName) ;
    fclose(text);
	return db;
}


void save_as_binary(database *d)
{
	FILE *text = fopen("db.bin", "wb") ;
     tables *tmp = d->tList;
    int cnt=0 ;
    if ( text==NULL || d==NULL ) {
        printf("filed to save.\n") ;
        return ;
    }
	fwrite(d->name, sizeof(char*), 1, text);
    while (tmp!=NULL ) {
        cnt++ ;
        fwrite(tmp->t, sizeof(table), 1, text);
        tmp = tmp->next ;
    }
    fclose(text) ;
    printf("write %d items ok\n", cnt) ;

}

void select_from(database *d, char *tableName)
{
	tables *iter = d->tList;

	int isFind = 0;
	char tempValue[15];
	int fieldCount, rowCount;

	while(iter != NULL)
	{
		if(iter->t != NULL)
		{
			if(strcmp(tableName, iter->t->tableName) ==0)
			{
				isFind = 1;
				fieldCount = iter->t->fieldCount;
				rowCount = iter->t->rowCount;

				printf("\n\n");
				printf("TABLE NAME: %s\n", tableName);

				for(int i=0; i<fieldCount; i++)
					printf("+-----------");
				printf("+\n");
				for(int i=0; i<fieldCount; i++)
					printf("| %-9s ", iter->t->field[i]);

				printf("|\n");

				for(int i=0; i<fieldCount; i++)
					printf("+-----------");

				printf("+\n");

				/*for(int i=0; i<fieldCount; i++)
				{
					for(int j=0; j<rowCount; j++)
					{
						printf("| %-9s ", iter->t->values[j][i]);
					}
					printf("|\n");
				}*/

				/*printf("| %-9s ", iter->t->values[0][0]);
				printf("| %-9s ", iter->t->values[0][1]);
				printf("| %-9s ", iter->t->values[0][2]);
				printf("| %-9s ", iter->t->values[0][3]);
				printf("|\n");
				printf("| %-9s ", iter->t->values[1][0]);
				printf("| %-9s ", iter->t->values[1][1]);
				printf("| %-9s ", iter->t->values[1][2]);
				printf("| %-9s ", iter->t->values[1][3]);*/

				for(int i=0; i<rowCount+1; i++)
				{
					for(int j=0; j<fieldCount; j++)
					{
						printf("| %-9s ", iter->t->values[i][j]);
					}
					printf("|\n");
				}



				printf("|\n");

				for(int i=0; i<fieldCount; i++)
					printf("+-----------");

				printf("|\n");

				break;
			}
		}

		iter = iter->next;
	}


	if(!isFind)
		printf("\n\n### There is no table named %s in the database... ###", tableName);

}

int insert_row(database *d, char *tableName)
{

	tables *iter = d->tList;

	char ***tempValues;

	int isFind = 0;
	char tempValue[15];
	int fieldCount, rowCount, maxRowSize;

	while(iter != NULL)
	{
		if(iter->t != NULL)
		{
			if(strcmp(tableName, iter->t->tableName) ==0)
			{
				isFind = 1;
				fieldCount = iter->t->fieldCount;
				rowCount = iter->t->rowCount;
				maxRowSize = iter->t->maxRowSize;
				/*tempValues = (char***)malloc((rowCount+1)*sizeof(char**));
				for (int i = 0; i < rowCount+1; i++)
				{
					tempValues[i] = (char**)malloc(fieldCount * sizeof(char*));
					for(int j = 0; j<fieldCount; j++)
					{
						tempValues[i][j] = (char*)malloc(15 * sizeof(char));
					}
				}

				for(int i = 0; i<rowCount+1; i++)
				{
					for(int j=0; j<fieldCount; j++)
					{
						strcpy(tempValues[i][j], iter->t->values[i][j]);
					}
				}*/

				if(maxRowSize == MAX)
					return 0;
				/*else
				{
					if(rowCount >= maxRowSize)
					{
						maxRowSize += 10;
						iter->t->maxRowSize = maxRowSize;
						/*iter->t->values = realloc(iter->t->values, maxRowSize);
						for(int i=0; i<maxRowSize; i++)
							iter->t->values[i] = realloc(iter->t->values[i], fieldCount);

						for(int i=0; i<maxRowSize; i++)
							for(int j=0; j<fieldCount; j++)
								iter->t->values[i][j] = realloc(iter->t->values[i][j], 15);*/


				/*		tempValues = (char***)malloc(maxRowSize*sizeof(char**));
						for(int i=0; i<maxRowSize; i++)
						{
							tempValues[i] = (char**)malloc(fieldCount * sizeof(char*));
							for (int j = 0; j < fieldCount; j++)
							{
									tempValues[i][j] = (char*)malloc(15 * sizeof(char));
							}
						}

						for(int i = 0; i<maxRowSize-10; i++)
						{
							for(int j=0; j<fieldCount; j++)
							{
								strcpy(tempValues[i][j], iter->t->values[i][j]);
							}
						}

						iter->t->values = tempValues;

					}
				} */

				for(int j=0; j<iter->t->fieldCount; j++)
				{
					printf("Please enter value for field named %s: ", iter->t->field[j]);
					scanf("%s", tempValue);
					strcpy(iter->t->values[rowCount][j], tempValue);
				}

				//iter->t->values = tempValues;


				for(int i=0; i<iter->t->fieldCount; i++)
					printf("\n--%s--\n", iter->t->values[rowCount][i]);

				iter->t->rowCount = rowCount+1;
				printf("\n-?%d?-\n", iter->t->rowCount);

				break;
			}
		}

		iter = iter->next;
	}


	if(!isFind)
		printf("\n\n### There is no table named %s in the database... ###", tableName);
	else
		printf("\n### SUCCESFULLY ADDED A NEW ROW ###\n\n");

	//free(tempValues);
	return 1;
}


void remove_table(database *d, char *tableName)
{
	tables *iter = d->tList;
	tables *prevNode = iter;

	int isFind = 0;

	while(iter != NULL)
	{
		if(iter->t != NULL)
		{
			if(strcmp(tableName, iter->t->tableName) ==0)
			{
				isFind = 1;
				if(prevNode == iter)
				{
					printf("girdi");
					d->tList = iter->next;
					iter = NULL;
				}
				else
				{
					prevNode->next = iter->next;
					iter->next = NULL;
				}
				break;
			}
		}

		prevNode = iter;
		iter = iter->next;
	}


	if(!isFind)
		printf("\n\n### There is no table named %s in the database... ###", tableName);
	else
		printf("\n\n### Table named \"%s\" has deleted on database... ###", tableName);



}


void show_table(database *d) //finished
{
	tables *iter = d->tList;
	printf("\n\n");
	printf("+----------------------------+\n");
	printf("| Tables in %-17s|\n", d->name);
	printf("|----------------------------|\n");

	while(iter != NULL)
	{
		printf("| %-26s |\n", iter->t->tableName);

		iter = iter->next;
	}
		printf("+----------------------------+\n");

}


void desc_table(database *d, table *t)
{
	tables *iter = d->tList;

	int fieldCount;
	int isFind = 0;
	char caseNull[5], caseKey[5];


	while(iter != NULL)
	{
		if(iter->t != NULL)
		{
			if(strcmp(t->tableName,iter->t->tableName)==0)
			{
				isFind=1;
				fieldCount = t->fieldCount;

				printf("\n\n");
				printf("TABLE NAME: %s\n", t->tableName);
				printf("+---------+-------------+------+-----+\n");
				printf("| Field   | Type        | Null | Key |\n");
				printf("+---------+-------------+------+-----+\n");

				for(int i=0; i<fieldCount; i++)
				{
					if(t->isNull[i] == 1)
						strcpy(caseNull, "Yes");
					else
						strcpy(caseNull, "No");

					if(t->isKey[i] == 1)
						strcpy(caseKey, "Yes");
					else
						strcpy(caseKey, "No");

					printf("|%-9s|%-13s|%-6s|%-5s|\n", t->field[i], t->type[i], caseNull, caseKey);
				}

				printf("+---------+-------------+------+-----+\n");

			}
		}
		iter = iter->next;
	}

	if(!isFind)
		printf("There is no table named %s in the database", t->tableName);
}

table* create_table()
{
	table *tempTable;
	char tempName[50];
	int fieldCount;
	int isKeyEntered = 0;

	tempTable = (table*)malloc(sizeof(table));

	printf("Enter Table Name: ");
	scanf("%s", tempTable->tableName);

	printf("Enter there is how many field: ");
	scanf("%d", &fieldCount);
	tempTable->fieldCount = fieldCount;

	tempTable->rowCount = 0;

	for(int i=0; i<fieldCount; i++)
	{

		printf("Enter %d.Field Name: ", i+1);
		scanf("%s", tempName);
		strcpy(tempTable->field[i], tempName);

		printf("Enter %d.Type Name: ", i+1);
		scanf("%s", tempName);
		strcpy(tempTable->type[i], tempName);

		if(!isKeyEntered)
		{
			printf("Is %d.Field Primary Key:(Yes=1, No=0) ", i+1);
			scanf("%d", &tempTable->isKey[i]);
		}

		if(tempTable->isKey[i] != 1)
		{
			printf("Can %d.Field be NULL:(Yes=1, No=0) ", i+1);
			scanf("%d", &tempTable->isNull[i]);
		}
		else
			isKeyEntered = 1;


		printf("\n\n");

	}

	return tempTable;
}

database* create_database(char *name)
{
	/* allacotes of database and tables structs*/
	database *db;
	db = malloc(sizeof(database));
	db->tList = (tables*)malloc(sizeof(tables));

	/* initializing variables*/
	db->tList->t = NULL;
	db->tList->next = NULL;
	db->n = 0;

	/* setting name*/
	strcpy(db->name, name);

	return db;
}

void insert_table(database *d, table *t)
{
	tables *iter = d->tList;

	if(iter -> t == NULL)	//if it is the first table entry
	{
		iter -> t = (table*)malloc(sizeof(table));
		iter -> t = t;
		iter->next = NULL;
		printf("1-%s", t->tableName);
	}
	else
	{
		while(iter ->next != NULL) iter = iter->next; // go to end of linkedlist

		iter -> next = (tables*)malloc(sizeof(tables)); //allacote a new table in next of iter
		iter = iter->next;
		iter->t = t; //assign table to table of iter
		iter->next = NULL;
		printf("2-%s", t->tableName);
		

	}
	show_table(d);
}

