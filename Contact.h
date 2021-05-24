
#ifndef PROJECT2_H_INCLUDED
#define PROJECT2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
int year;
int month;
int day;
}DOB;
typedef struct
{
    int id;
    char firstname[100];
    char lastname[100];
    char address[100];
    char phonenumber[100];
    char email[100];
    DOB date_birth;
}Contact;
int main();
void load();
void search();
void add();
void Delete();
void modify();
void print();
void save();
void quit();
void sortbylastname();
void sortbyDOB();
void validate_date(int dd,int mm,int yyyy,Contact * c);
int validate_email(char * email);
void p_rint();
int validate_phone(int response,char * phone);




#endif // PROJECT2_H_INCLUDED
