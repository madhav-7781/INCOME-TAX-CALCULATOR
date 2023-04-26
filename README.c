//INCOME-TAX-CALCULATOR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold tax payer record.
struct Taxpayer
{
	int id;
	char name[50];
	int age;
	float income;
	float tax;
};

// Function to calculate income tax based on income.
float calculateTax(float income)
{
	float tax = 0;
	if(income <= 250000)
	{
		tax = 0;
	}
	else if(income <= 500000)
	{
		tax = (income - 250000) * 0.05;
	}
	else if(income <= 1000000)
	{
		tax = 250000 * 0.05 + (income - 500000) * 0.2;
	}
	else
	{
		tax = 250000 * 0.05 + 500000 * 0.2 + (income - 1000000) * 0.3;
	}
	return tax;
}

int main()
{
	int i,j;
	struct Taxpayer taxPayers[100]; // Array to store tax payer records.
	int numRecords = 0; // Number of records in the array.
	printf("\n------------------------------------------------------- Income Tax Calculator ------------------------------------------\n");
	int choice;
	do
	{
		printf("\n1. Add New Record\n");
		printf("2. List all Tax Payers along with the Income Tax to be paid\n");
		printf("3. Search\n");
		printf("4. Edit\n");
		printf("5. Delete Record\n");
		printf("6. Exit\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				// Add New Record.
				printf("\nEnter ID: ");
				scanf("%d",&taxPayers[numRecords].id);
				printf("Enter Name: ");
				scanf("%s",taxPayers[numRecords].name);
				printf("Enter Age: ");
				scanf("%d",&taxPayers[numRecords].age);
				printf("Enter Income: ");
				scanf("%f",&taxPayers[numRecords].income);
				taxPayers[numRecords].tax = calculateTax(taxPayers[numRecords].income);
				numRecords++;
				printf("Record Added Successfully!\n");
				break;
				
			case 2:
				// List all tax payers along with income tax to be paid.
				
				if(numRecords==0)
				{
					printf("No Records Found.\n");
				}
				else
				{
					printf("\nTax Payers List:\n");
					printf("-----------------------------------------------------------------------------\n");
					printf("ID\tName\t\tAge\tIncome\t\tTax to be Paid\n");
					printf("-----------------------------------------------------------------------------\n");
					for(i=0;i<numRecords;i++)
					{
						printf("%d\t%s\t\t%d\t%.2f\t%.2f\n",taxPayers[i].id,taxPayers[i].name,taxPayers[i].age,taxPayers[i].income,taxPayers[i].tax);
					}
					printf("------------------------------------------------------------------------------\n");
				}
				break;
			
			case 3:
				// Search for a tax payer by name.
				
				if(numRecords == 0)
				{
					printf("No Records Found.\n");
				}
				else
				{
					char searchName[50];
					int found = 0;
					printf("\nEnter Name to Search: ");
					scanf("%s",searchName);
					for(i = 0;i<numRecords;i++)
					{
						if(strcmp(searchName,taxPayers[i].name)==0)
						{
							printf("Record Found:\n\n");
							printf("ID: %d\n",taxPayers[i].id);
							printf("Name: %s\n",taxPayers[i].name);
							printf("Age: %d\n",taxPayers[i].age);
							printf("Income: %.2f\n",taxPayers[i].income);
							printf("Tax to be Paid: %.2f\n",taxPayers[i].tax);
							found = 1;
							break;
						}
					}
					if(!found)
					{
						printf("Record Not Found.\n");
					}
				}
				break;
				
			case 4:
				// Edit a tax payer record.
				if(numRecords==0)
				{
					printf("No Records Found.\n");
				}
				else
				{
					
					char editName[50];
					int found = 0;
					printf("\nEnter Name to Edit: ");
					scanf("%s",editName);
					for(i=0;i<numRecords;i++)
					{
						if(strcmp(editName,taxPayers[i].name) == 0)
						{
							printf("Enter New Name: ");
							scanf("%s",taxPayers[i].name);
							printf("Enter New Age: ");
							scanf("%d",&taxPayers[i].age);
							printf("Enter New Income: ");
							scanf("%f",&taxPayers[i].income);
							taxPayers[i].tax = calculateTax(taxPayers[i].income);
							printf("Record Edited Successfully!\n");
							found = 1;
							break;
						}
					}
					if(!found)
					{
						printf("Record Not Found.\n");
					}
				}
				break;
				
			case 5:
				// Delete a tax payer record.
				
				if(numRecords == 0)
				{
					printf("No Records Found.\n");
				}
				else
				{
					char deleteName[50];
					int found = 0;
					printf("\nEnter Name to Delete: ");
					scanf("%s",deleteName);
					for(i = 0;i<numRecords;i++)
					{
						if(strcmp(deleteName, taxPayers[i].name) == 0)
						{
							for(j=i;j<numRecords-1;j++)
							{
								// Shift the records after the deleted record to fill the gap.
								taxPayers[j].id = taxPayers[j+1].id;
								strcpy(taxPayers[j].name, taxPayers[j+1].name);
								taxPayers[j].age = taxPayers[j+1].age;
								taxPayers[j].income = taxPayers[j+1].income;
								taxPayers[j].tax = taxPayers[j+1].tax;
							}
							numRecords--;
							printf("Record Deleted Successfully!\n");
							found = 1;
							break;
						}
					}
					if(!found)
					{
						printf("Record Not Found.\n");
					}
				}
				break;
			case 6:
				// Exit.
				printf("Exiting...\n");
				break;
				
			default:
				printf("Invalid choice. Please try again.\n");
				break;
		}
	} while(choice!=6);
	return 0;
}
