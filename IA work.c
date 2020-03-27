#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

int provbid;
int proveid;
int login();
void menu2();
void menu3();
void bus_mgm();
void emp_mgm();


typedef struct bus_data
{
    int busid;
    float distrav;
    
}bus;

typedef struct emp_data
{
   int empid;
   float hrswrkd;
}emp;

void addb(int*,bus[]);
void adde(int*,emp[]);

void viewb(int*,bus[]);
void viewe(int*,emp[]);
void updateb(int*,bus[]);
void updatee(int*,emp[]);
void deleteb(int*,bus[]); 
void deletee(int*,emp[]);
int searchb(int,bus[]);
int searche(int,emp[]); 
void readfileb(int*,bus[]);
void readfile(int*,emp[]);
void writefileb(int,bus[]);
void writefilee(int,emp[]);

int main(){
	

	

	

	
	int option1;
	int p = 0;
	p = login();
	if (p==1){
	printf("\n-*-*-*-*-*     Welcome to 'Company Manager' user      *-*-*-*-*\n");
	}
	else{
		return 0;
	}
	system("pause");
	system("cls");
	printf("\n\nPlease slect an option:\n");
	printf("1 Bus managment menu\n");
	printf("2 Employee managment menu\n");
	printf("3 Exit\n");
	scanf("%d", &option1);
	
	while (option1 != 3){
	
		switch(option1){
			case 1:
				menu2();
				break;
			case 2:
				menu3();
				break;
			default:
				{
					if (option1 != 3){
						printf("\nOption is not supported.");
					}
				}
		system("pause");
		printf("Please slect an option:\n");
		printf("1 Bus managment menu\n");
		printf("2 Employee managment menu\n");
		printf("3 Exit\n");
		scanf("%d", &option1);
		 
		}
    system("pause");
	}
	
	return 0;
}

int login(){
int pwd = 12345678;
	int count = 0;
	int pw;
	printf("Welcome to 'comapnay manager' login screen\n");
	while (count != 5){
		printf("Please enter password. \n");
		scanf("%d",&pw);
		if (pw == pwd){
			printf("Password accepted");
			return 1;
		}
		else{
			printf("\n Wrong Password, try again.\n");
			
		}
		count++;
		printf("You have done %d chances out of 5\n", count);
	}
	return 0;
}



void menu2(){
	int choice;
	int bl = 0;
	bus bslist[SIZE];
	readfileb(&bl, bslist);
	system("pause");
	system("cls");
	printf("Welcome to the bus menu.\n\n");
	printf("Please select an option:\n\n1: Add bus information\n2: View bus information\n3: Update bus information\n4: Delete bus information\n5: Return to login menu\n6: to exit the prgram\n");
	scanf("%d",&choice);
	while (choice != 6){
	
		switch (choice){
			case 1:
				addb(&bl, bslist);
				break;
			case 2:
				viewb(&bl, bslist);
				break;
			case 3: 
				updateb(&bl, bslist);
				break;
			case 4:
				deleteb(&bl, bslist);
				break;
			case 5:
				main();
				break;	
			default:
				if (choice != 6){
					printf("you have not selected a proper option\n");
				}
				else{
					goto end;
				}

		}
		system("pause");
		system("cls");
		printf("Please select an option:\n\n1: Add bus information\n2: View bus information\n3: Update bus information\n4: Delete bus information\n5: Return to login menu\n6: Exit\n ");
		scanf("%d",&choice);
	}
	end:
		exit(0);
}

void menu3(){
	int choice;
	int el = 0;
	emp eplist[SIZE];
	system("pause");
	system("cls");
	printf("Welcome to the Employee menu menu.\n\n");
	printf("Please select an option:\n\n1: Add Employee information\n2: View Employee information\n3: Update Employee information\n4: Delete Employee information\n5: Return to login menu\n6: Exit\n");
	scanf("%d", &choice);
	while (choice != 6){
	
		switch (choice){
			case 1:
				adde(&el, eplist);
				break;
			case 2:
				viewe(&el, eplist);
				break;
			case 3: 
				updatee(&el, eplist);
				break;
			case 4:
				deletee(&el, eplist);
				break;
			case 5:
				main();
				break;
				default:
				if (choice != 6){
					printf("you have not selected a proper option\n");
				}
				else{
					goto end;
				}
			}
		system("pause");
		printf("Please select an option:\n1: Add Employee information\n2: View Employee information\n3: Update Employee information\n4: Delete Employee information\n5: Return to login menu\n6: Exit\n");
		scanf("%d", &choice);
		}
		end:
			exit(0);
}

void addb(int *loc ,bus list[]){
	printf("Add bus information");
	
	int n =  searchb( *loc, list);
	
	if (n != -1){
		printf("This ID is already being used.");
	}
	else
	{
		list[*loc].busid = provbid;
		
		fflush(stdin);
		
		printf("Please enter the total distance traveled, the number you have given will be accepted as km: ");
		scanf("%f", &list[*loc].distrav);
		
		*loc = *loc + 1;
	}
}

void adde(int*loc ,emp list[]){
	printf("Add Employee information\n");
	
	int n =  searche( *loc, list);
	
	if (n != -1){
		printf("This ID is already being used.");
	}
	else
	{
		list[*loc].empid = proveid;
		
		fflush(stdin);
		
		printf("Please enter the total hours worked: ");
		scanf("%f", &list[*loc].hrswrkd);
		
		*loc = *loc + 1;
	}	
}


void viewb(int *loc ,bus list[]){
		
	int meh;
	
	printf("Showing information of all buses.\n");
	
	for(meh = 0; meh < *loc; meh++)
	{
		printf("Bus ID is: %d\n", list[meh].busid);
		printf("Distance traveled is: %.1f km\n", list[meh].distrav);
	}
}

void viewe(int *loc,emp list[]){
	int meh;
	
	printf("Showing information of all Employess.\n");
	
	for(meh = 0; meh < *loc; meh++)
	{
		printf("Employee ID is: %d\n", list[meh].empid);
		printf("Hours worked are: %.1f hours\n", list[meh].hrswrkd);
	}
}


void updateb(int *loc,bus list[]){
	int tempbid;
	
	printf("Update bus information");
	
	tempbid = searchb(*loc, list);
	
	if( tempbid== -1)
	{
		printf("This ID does not exist.\n");
	}
	else
	{
		printf("Enter new distanced traveled: ");
		scanf("%f", &list[tempbid].distrav);
		
		printf("Distance traveled has been updated. \a");
	}
}

void updatee(int *loc ,emp list[]){
	int tempeid;
	
	printf("Update employee information");
	
	tempeid = searche(*loc, list);
	
	if( tempeid== -1)
	{
		printf("This ID does not exist.\n");
	}
	else
	{
		printf("Enter new hours worked: ");
		scanf("%f", &list[tempeid].hrswrkd);
		
		printf("Hours worked has been updated. \a");
	}
}


void deleteb(int *loc, bus list[]){
	int tempbid, meh;
	
	printf("Delete bus info");
	
	tempbid = searchb(*loc, list);
	
	if(tempbid == -1)
	{
		printf("This ID does not exist.\n");
	}
	else
	{
		for(meh = tempbid; meh < *loc; meh++)
		{
			list[meh].busid = list[meh + 1].busid;
			list[meh].distrav = list[meh + 1].distrav;
		}
		
		*loc = *loc - 1;
		printf("Bus ID %d has been deleted.\n", tempbid);
	}
}

void deletee(int *loc,emp list[]){
	int tempeid, meh;
	
	printf("Delete employee info");
	
	tempeid = searche(*loc, list);
	
	if(tempeid == -1)
	{
		printf("This ID does not exist.\n");
	}
	else
	{
		for(meh = tempeid; meh < *loc; meh++)
		{
			list[meh].empid = list[meh + 1].empid;
			list[meh].hrswrkd = list[meh + 1].hrswrkd;
		}
		
		*loc = *loc - 1;
		printf("Employee ID %d has been deleted.\n", tempeid);
	}
}


int searchb(int loc, bus list[]){
	int meh;
	
	printf("Enter bus ID: ");
	scanf("%d", &provbid);
	
	for(meh=0; meh<loc; meh++){
		if(list[meh].busid == provbid)
		return meh;
	}
	return -1;
}

int searche(int loc ,emp list[]){
	int meh;
	
	printf("Enter employee ID: ");
	scanf("%d", &proveid);
	
	for(meh=0; meh<loc; meh++){
		if(list[meh].empid == proveid)
		return meh;
	}
	return -1;
} 


void readfileb(int *loc, bus list[]){
	FILE *bd;
	
	bd = fopen("Bus Data.txt", "r");
	if(bd != NULL)
	{
		while(!feof(bd))
		{
			fscanf(bd, "%d %f ", &list[*loc].busid, &list[*loc].distrav);
			*loc = *loc + 1;
		}
	}
	fclose(bd);
}

void readfile(int *loc, emp list[]){
	FILE *ed;
	
	ed = fopen("Employee Data.txt", "r");
	if(loc != NULL)
	{
		while(!feof(ed))
		{
			fscanf(ed, "%d %f ", &list[*loc].empid, &list[*loc].hrswrkd);
			*loc = *loc + 1;
		}
	}
	fclose(ed);
}

