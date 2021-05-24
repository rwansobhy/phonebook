#pragma pack(1)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define MAX_SIZE 100
#include "Contact.h"
Contact phonebook[MAX_SIZE];
int current_size=0;
Contact c;
void load()
{

    FILE *pf;
    pf=fopen("phonebook.txt","r");
    if (pf==NULL)
    {
        printf("unable to open the file" );
        exit(1);
    }
    else
    {
        while (!feof(pf))
        {



            fscanf(pf,"%[^,],",phonebook[current_size].firstname);
            fscanf(pf,"%[^,],",phonebook[current_size].lastname);
            fscanf(pf,"%d-%d-%d,",&(phonebook[current_size].date_birth.day),&(phonebook[current_size].date_birth.month),&(phonebook[current_size].date_birth.year));
            fscanf(pf,"%[^,],",phonebook[current_size].address);
            fscanf(pf,"%[^,],",phonebook[current_size].email);
            fscanf(pf,"%[^\n]\n",phonebook[current_size].phonenumber);


            current_size++;



        }
        fclose(pf);
    }
}

void p_rint()
{
    int i;
    for(i=0; i<current_size; i++)
    {
        printf("Contact no.%d:\n",i+1);
        printf("the first name is:%s\n",phonebook[i].firstname);
        printf("the last name is:%s\n",phonebook[i].lastname);
        printf("the address is:%s\n",phonebook[i].address);
        printf("the email is:%s\n",phonebook[i].email);
        printf("the Date Of Birth is:%02d-%02d-%4d\n",phonebook[i].date_birth.day,phonebook[i].date_birth.month,phonebook[i].date_birth.year);
        printf("phonebook is:%s\n",phonebook[i].phonenumber);

    }

}


void add()
{
    int i;
    int n;
    printf("Enter number of entries:");
    scanf("%d",&n);
    if(current_size==MAX_SIZE)
    {
        printf("Error:phonebook directory is full");
        return;
    }
    for(i=0; i<n; i++)
    {
        printf("Entry number %d\n", (i + 1));
        c.id=current_size;
        printf("Enter the first name: ");
        scanf("%s",c.firstname);
        printf("Enter the last name: ");
        scanf("%s",c.lastname);
        // printf("Enter date of birth:");
        // scanf("%d %d %d",&(c.date_birth.day),&(c.date_birth.month),&(c.date_birth.year));
        int dd,mm,yyyy;

        printf("Enter date of birth(DD-MM-YYYY)format:\n");
        printf("Enter the day:");
        scanf("%d",&dd);
        printf("Enter the month:");
        scanf("%d",&mm);
        printf("Enter the year:");
        scanf("%d",&yyyy);

        validate_date(dd,mm,yyyy,&c);

        printf("Enter the address of the contact:");
        getchar();
        scanf("%[^\n]",c.address);
        printf("Enter the email:");
        scanf("%s",c.email);
        while(!validate_email(c.email))
        {
            printf("email is not valid\n");
            printf("Enter the email:");
            scanf("%s",c.email);
        }
        //printf("Enter the phone number :");
        // scanf("%s",c.phonenumber);
        int response;
        printf("CHOOSE WHETHER YOU WANT PHONE NUMBER OR MOBILE NUMBER\n");
        do
        {
            printf("enter '1' for phonenumber or '2' for mobile number:");
            scanf("%d",&response);
        }
        while(response!=1&&response!=2);

        if(response==1)
        {
            printf("Enter phone number inform of xx-xxxxxxx:");
            scanf("%s",c.phonenumber);
            while(!validate_phone(response,c.phonenumber))
            {
                printf("phone number is not valid\n");
                printf("Enter phone number inform of xx-xxxxxxx:");
                scanf("%s",c.phonenumber);
            }
        }
        else
        {
            printf("Enter mobile number in the format of xxxxxxxxxxx:");
            scanf("%s",c.phonenumber);
            while(!validate_phone(response,c.phonenumber))
            {
                printf("mobilenumber is not valid\n");
                printf("Enter mobile number in the format of xxxxxxxxxxx:");
                scanf("%s",c.phonenumber);
            }
        }

        //printf("-------------------------------------------------------------\n");
        system("cls");


        phonebook[current_size]=c;
        ++current_size;
    }


}
void search()
{
    char first[100];
    char last[100];
    char phone[100];
    int type,i;
    int response;
    do
    {
        printf("Enter:\n1:Search with first name\n2:Search with last name\n3:Search with phone number\n");
        printf("Answer:");
        scanf("%d",&type);
    }
    while(!(type>=1&&type<=3));
    switch(type)
    {
    case 1:
        printf("Enter first name: ");
        scanf("%s",first);
        break;
    case 2:
        printf("Enter last name: ");
        scanf("%s",last);
        break;
    case 3:

        printf("CHOOSE WHETHER YOU WANT PHONE NUMBER OR MOBILE NUMBER\n");
        do
        {
            printf("enter '1' for phonenumber or '2' for mobile number:");
            scanf("%d",&response);
        }
        while(response!=1&&response!=2);

        if(response==1)
        {
            printf("Enter phone number inform of xx-xxxxxxx:");
            scanf("%s",phone);
            while(!validate_phone(response,phone))
            {
                printf("phone number is not valid\n");
                printf("Enter phone number inform of xx-xxxxxxx:");
                scanf("%s",phone);
            }
        }
        else
        {
            printf("Enter mobile number in the format of xxxxxxxxxxx:");
            scanf("%s",phone);
            while(!validate_phone(response,phone))
            {
                printf("mobilenumber is not valid\n");
                printf("Enter mobile number in the format of xxxxxxxxxxx:");
                scanf("%s",phone);
            }
        }

        break;

    }
    int count=0;
    for(i=0; i<current_size; i++)
    {
        if(type==1)
        {
            if(strcasecmp(phonebook[i].firstname,first)==0)
            {
                count++;

                printf("\n");
                printf("The first name is: %s\n",phonebook[i].firstname);
                printf("The last name is: %s\n",phonebook[i].lastname);
                printf("The address is: %s\n",phonebook[i].address);
                printf("The email is: %s\n",phonebook[i].email);
                printf("The phone number is: %s\n",phonebook[i].phonenumber);
                printf("The date of birth is: %02d-%02d-%4d\n",phonebook[i].date_birth.day,phonebook[i].date_birth.month,phonebook[i].date_birth.year);
                printf("\n");

            }
        }
        else if(type==2)
        {
            if(strcasecmp(phonebook[i].lastname,last)==0)
            {
                count++;
                printf("\n");
                printf("The first name is: %s\n",phonebook[i].firstname);
                printf("The last name is: %s\n",phonebook[i].lastname);
                printf("The address is: %s\n",phonebook[i].address);
                printf("The email is: %s\n",phonebook[i].email);
                printf("The phone number is: %s\n",phonebook[i].phonenumber);
                printf("The date of birth is: %02d-%02d-%4d\n",phonebook[i].date_birth.day,phonebook[i].date_birth.month,phonebook[i].date_birth.year);
                printf("\n");

            }
        }
        else if(type ==3)
        {
            if(strcasecmp(phonebook[i].phonenumber,phone)==0)
            {
                count++;
                printf("\n");
                printf("The first name is: %s\n",phonebook[i].firstname);
                printf("The last name is: %s\n",phonebook[i].lastname);
                printf("The address is: %s\n",phonebook[i].address);
                printf("The email is: %s\n",phonebook[i].email);
                printf("The phone number is: %s\n",phonebook[i].phonenumber);
                printf("The date of birth is: %02d-%02d-%4d\n",phonebook[i].date_birth.day,phonebook[i].date_birth.month,phonebook[i].date_birth.year);
                printf("\n");

            }
        }
    }
    if(count==0)
    {
        printf("No Contacts Found !\n");
    }



}



void modify()
{

    int i;
    int count=0;
    Contact * temp[current_size];
    char lastname[100];
    printf("Enter last name: ");
    scanf("%s",lastname);
    for(i=0; i<current_size; i++)
    {
        if(strcasecmp(phonebook[i].lastname,lastname)==0)
        {
            temp[count]=&phonebook[i];
            count++;

        }
    }
    if(count==0)
        return;
    for(i=0; i<count; i++)
    {
        printf("[%d],%s,%s,%s,%s,%d-%d-%d,%s\n",i,temp[i]->firstname,temp[i]->lastname,temp[i]->address,temp[i]->email,temp[i]->date_birth.day,temp[i]->date_birth.month,temp[i]->date_birth.year,temp[i]->phonenumber);
    }
    int contact_to_modify;
    do
    {
        printf("enter user number\n");
        scanf("%d",&contact_to_modify);
    }
    while(contact_to_modify<0||contact_to_modify>=count);

    int flag,day_temp,month_temp,year_temp;
    char str_temp[100];
    getchar();
    printf("Enter new first name:");
    flag=scanf("%[^\n]",str_temp);
    getchar();
    if (flag==1)
        strcpy(temp[contact_to_modify]->firstname,str_temp);
    printf("Enter new last name:");
    flag=scanf("%[^\n]",str_temp);
    getchar();
    if (flag==1)
        strcpy(temp[contact_to_modify]->lastname,str_temp);
    printf("Enter new address:");

    flag=scanf("%[^\n]",str_temp);
    getchar();
    if (flag==1)
        strcpy(temp[contact_to_modify]->address,str_temp);
    printf("Enter new email:");
    flag=scanf("%[^\n]",str_temp);
    getchar();

    while(flag==1&&!validate_email(str_temp))
    {
        printf("email is not valid\n");
        printf("Enter new email:");
        flag=scanf("%[^\n]",str_temp);
        getchar();
    }
    if(flag==1)
        strcpy(temp[contact_to_modify]->email,str_temp);

    printf("Enter the day:");
    scanf("%d",&day_temp);
    printf("Enter the month:");
    scanf("%d",&month_temp);
    printf("Enter the year:");
    scanf("%d",&year_temp);
    validate_date(day_temp,month_temp,year_temp,temp[contact_to_modify]);
    int response;

    do
    {
        printf("enter '1' for phonenumber or '2' for mobile number or 3 to skip");
        scanf("%d",&response);
    }
    while(response!=1&&response!=2&&response!=3);

    if(response==1)
    {
        printf("Enter phone number inform of xx-xxxxxxx:");
        scanf("%s",temp[contact_to_modify]->phonenumber);
        while(!validate_phone(response,temp[contact_to_modify]->phonenumber))
        {
            printf("phone number is not valid\n");
            printf("Enter phone number inform of xx-xxxxxxx:");
            scanf("%s",temp[contact_to_modify]->phonenumber);
        }
    }
    else if(response==2)
    {
        printf("Enter mobile number in the format of xxxxxxxxxxx:");
        scanf("%s",temp[contact_to_modify]->phonenumber);
        while(!validate_phone(response,temp[contact_to_modify]->phonenumber))
        {
            printf("mobilenumber is not valid\n");
            printf("Enter mobile number in the format of xxxxxxxxxxx:");
            scanf("%s",temp[contact_to_modify]->phonenumber);
        }
    }

}

void save()
{
    FILE *pf;
    char buff[MAX_SIZE];
    int i;
    pf=fopen("phonebook.txt","w");
    if(!pf)
    {
        printf("unable to open the file");
        exit(1);

    }
    for(i=0; i<current_size; i++)
    {
        sprintf(buff,"(%d)%s,%s,%d-%d-%d,%s,%s,%s\n",(i+1),phonebook[i].firstname,phonebook[i].lastname,phonebook[i].date_birth.day,phonebook[i].date_birth.month,phonebook[i].date_birth.year,phonebook[i].address,phonebook[i].email,phonebook[i].phonenumber);
        fputs(buff,pf);
    }
    fclose(pf);
}
void Delete()
{

    int response=0;
    int j;//iterator
    int i;
    char delete_firstname[50];
    char delete_lastname[50];


    printf("Enter the first name you wish to delete");
    scanf("%s",delete_firstname);
    printf("Enter the last name you wish to delete");
    scanf("%s",delete_lastname);

    for(j=0; j<current_size; j++)
    {
        if(strcmp(phonebook[j].firstname,delete_firstname)==0 && strcmp(phonebook[j].lastname,delete_lastname)==0)
        {

            printf("Are you sure you want to delete:[%d]%s,%s,%d-%d-%d,%s,%s,%s?\n",phonebook[j].id,phonebook[j].firstname,phonebook[j].lastname,phonebook[j].date_birth.day,phonebook[j].date_birth.month,phonebook[j].date_birth.year,phonebook[j].address,phonebook[j].email,phonebook[j].phonenumber);
            puts("You will not be able to undo the deletion.");
            puts("Enter \'1\' to confirm delete ");
            scanf("%d",&response);
            if(response==1)
            {
                for(i=j; i<current_size-1; i++)
                {
                    phonebook[i]=phonebook[i+1];
                }
                current_size--;

            }





        }
    }

}

void print()
{
    int n;
    printf("enter\n 1:sort with last name\n2:sort with date of birth\n");
    scanf("%d",&n);
    if(n==1)
        sortbylastname();
    if(n==2)
        sortbyDOB();
}
void sortbylastname()
{
    Contact temp;
    int i,j;
    for(i=0; i<current_size; i++)
    {
        for(j=0; j<current_size-i-1; j++)
        {
            if(strcmp(phonebook[j].lastname,phonebook[j+1].lastname)>0)
            {
                temp=phonebook[j];
                phonebook[j]=phonebook[j+1];
                phonebook[j+1]=temp;
            }
        }
    }
    for(i=0; i<current_size; i++)
    {
        printf("the first name is:%s\n",phonebook[i].firstname);
        printf("the last name is:%s\n",phonebook[i].lastname);
        printf("the address is:%s\n",phonebook[i].address);
        printf("the email is:%s\n",phonebook[i].email);
        printf("the phone number is:%s\n",phonebook[i].phonenumber);
        printf("dateofbirth:%d-%d-%d\n",phonebook[i].date_birth.day,phonebook[i].date_birth.month,phonebook[i].date_birth.year);
    }
}
void sortbyDOB()
{
    int temp;
    int i,j;
    for(i=0; i<current_size; i++)
    {
        for(j=0; j<current_size-i-1; j++)
        {
            if(phonebook[j].date_birth.year<phonebook[j+1].date_birth.year)
            {
                temp=phonebook[j].date_birth.year;
                phonebook[j].date_birth.year=phonebook[j+1].date_birth.year;
                phonebook[j+1].date_birth.year=temp;
            }
            else if(phonebook[j].date_birth.year==phonebook[j+1].date_birth.year&&phonebook[j].date_birth.month<phonebook[j+1].date_birth.month)
            {
                temp=phonebook[j].date_birth.year;
                phonebook[j].date_birth.year=phonebook[j+1].date_birth.year;
                phonebook[j+1].date_birth.year=temp;
            }
            else if(phonebook[j].date_birth.year==phonebook[j+1].date_birth.year&&phonebook[j].date_birth.month==phonebook[j+1].date_birth.month&&phonebook[j].date_birth.day<phonebook[j+1].date_birth.day)
            {
                temp=phonebook[j].date_birth.year;
                phonebook[j].date_birth.year=phonebook[j+1].date_birth.year;
                phonebook[j+1].date_birth.year=temp;
            }
        }
    }
    for(i=0; i<current_size; i++)
    {
        printf("the first name is:%s\n",phonebook[i].firstname);
        printf("the last name is:%s\n",phonebook[i].lastname);
        printf("the address is:%s\n",phonebook[i].address);
        printf("the email is:%s\n",phonebook[i].email);
        printf("the phone number is:%s\n",phonebook[i].phonenumber);
        printf("dateofbirth:%d-%d-%d\n",phonebook[i].date_birth.day,phonebook[i].date_birth.month,phonebook[i].date_birth.year);
    }
}

void quit()
{
    int n;
    printf("Do you want to save all changes\n");
    printf("enter 1:Yes\n2:No\n");
    scanf("%d",&n);
    if(n==1)
        save();
    else if (n==2)
        exit(0);



}
void validate_date(int dd,int mm,int yyyy,Contact * c)
{
    int flag=1;

    while(flag)
    {
        if(yyyy<=2019&&yyyy>=1920)
        {
            if(mm>=1&&mm<=12)
            {
                if((dd>=1&&dd<=31)&&(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12))
                {
                    printf("Date is valid\n");
                    flag=0;
                }
                else if((dd>=1&&dd<=30)&&(mm==4||mm==6||mm==9||mm==11))
                {
                    printf("Date is valid\n");
                    flag=0;
                }
                else if((dd>=1&&dd<=28)&&(mm==2))
                {
                    printf("Date is valid\n");
                    flag=0;
                }
                else
                {
                    printf("Day or month not valid\n");
                    printf("Enter the day:");
                    scanf("%d",&dd);
                    printf("Enter the month:");
                    scanf("%d",&mm);
                    continue;
                }
            }
            else
            {
                printf("Month not valid\n ");
                printf("Enter the month:");
                scanf("%d",&mm);
                continue;
            }
        }
        else
        {
            printf("Year is not valid\n");
            printf("Enter the year:");
            scanf("%d",&yyyy);
            continue;
        }

    }
    c->date_birth.day=dd;
    c->date_birth.month=mm;
    c->date_birth.year=yyyy;

}
int validate_email(char *email)
{
    int state=0,i;
    for(i=0; i<strlen(email); i++)
    {
        if(i==0)
        {
            if(isalpha(email[i]))
            {
                state=1;
            }
            else
            {
                return 0;
            }
        }
        else if(state==1)
        {
            if (email[i]=='@')
            {
                state=2;
            }
            else if(!isalpha(email[i])&&!isdigit(email[i])&&email[i]!='.'&&email[i]!='_')
                return 0;

        }
        else if(state==2)
        {
            if(isalpha(email[i]))
            {
                state=3;
            }
            else
            {
                return 0;
            }
        }

        else if(state==3)
        {
            if (email[i]=='.')
            {
                state=4;
            }
            else if(!isalpha(email[i]))
                return 0;
        }
        else if(state==4)
        {
            if(isalpha(email[i]))
            {
                state=5;
            }
            else
            {
                return 0;
            }
        }
        else if(state==5)
        {
            if(!isalpha(email[i]))
                return 0;

        }

    }
    return state==5;

}
int validate_phone(int response, char*phonenumber)
{
    int i;
    int state=0;

    if(response == 2 )
    {
        for(i=0; i<strlen(phonenumber); i++)
            if(!isdigit(phonenumber[i]))
                return 0;
        return 1;
    }
    else
    {
        for(i=0; i<strlen(phonenumber); i++)
        {
            if(i==0)
            {
                if(isdigit(phonenumber[i]))
                {
                    state=1;
                }
                else
                {
                    return 0;
                }
            }
            else if(state==1)
            {
                if(phonenumber[i]=='-')
                {
                    state=2;
                }
                else if(!isdigit(phonenumber[i]))
                {
                    return 0;
                }

            }
            else if(state==2)
            {
                if(isdigit(phonenumber[i]))
                {
                    state=3;
                }
                else
                {
                    return 0;
                }
            }
            else if(state==3)
            {
                if(!isdigit(phonenumber[i]))
                {
                    return 0;
                }
            }




        }
        return state ==3;
    }


}
















