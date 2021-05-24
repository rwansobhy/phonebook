#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
#include "Contact.h"

int main()

{

    system("COLOR D7");

    printf("\t\t\t\t\t\t****PHONEBOOK****\n");
  int option=0;

    while(option !=8)
    {
printf("\t\t\t\t\t    *********menu:**********\n");
    printf("enter:\n\t\t\t\t\t1:load          5:modify\n\t\t\t\t\t2:search\t6:printsorting\n\t\t\t\t\t3:add           7:save\n\t\t\t\t\t4:delete\t8:quit\n");
    printf("answer:");
        scanf("%d",&option);

        switch(option)
        {
        case 1:
            load();
            break;
       case 2:
            search();
            break;
        case 3:
            add();
            break;
        case 4:
            Delete();
            break;
       case 5:
            modify();
            break;
        case 6:
            print();
            break;
        case 7:
            save();
            break;
        case 8:
            quit();
        default:
            printf("enter from 1 to 8");
        }
    }




    return 0;
}
