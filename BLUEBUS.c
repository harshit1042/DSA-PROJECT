#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main()
{
    int a;
    struct bus
    {
        int age;
        long long int phone_number;
        char name[30];
        int preffered_seat;
    };

    struct bus passenger[29];

    printf(" \n");
    printf("Welcome to  \'BluEBuS\' \n");

    int i = 0;
    int booked_seats = 0;

    while (i < 30)
    {
        for (int k = 0; k < 73; k++)
        {
            printf("_");
        }
        printf("\n");

        printf("Enter 1 for Registration!!!\n");
        printf("Enter 2 for seeing list!!!\n");
        printf("Enter 3 for EXIT!!!\n");
        scanf("%d", &a);

        if (a == 1)
        {
            printf("\nEnter the name of the passenger : ");
            scanf(" %[^\n]s", passenger[i].name);
            printf("\nEnter the age of passenger :");
            scanf("%d", &passenger[i].age);
            printf("\nEnter the Phone number of the passenger :");
            scanf("%llu", &passenger[i].phone_number);

            for (int stay1 = 0; stay1 < 5; stay1++)
            {
                int flag = 0;
                printf("\nEnter your prefferable seat : ");
                scanf("%d", &passenger[i].preffered_seat);

                while (passenger[i].preffered_seat > 30 || passenger[i].preffered_seat < 1)
                {
                    printf("you entered seat no. which is not avalable");
                    printf("\nEnter your prefferable seat : ");
                    scanf("%d", &passenger[i].preffered_seat);
                }

                if (i == 0)
                {
                    break;
                }
                for (int stay = 0; stay < i; stay++)
                {
                    flag = 0;
                    if (passenger[i].preffered_seat == passenger[stay].preffered_seat)
                    {
                        printf("THis seat is already taken....\n");
                        printf("This seats are taken...\n");
                        for (int sugar = 0; sugar < i; sugar++)
                        {
                            printf("%d ", passenger[sugar].preffered_seat);
                        }
                        break;
                    }

                    else
                    {
                        flag = 1;
                    }
                }

                if (flag == 1)
                {
                    break;
                }
            }

            i++;
        }

        else if (a == 2)
        {

            for (int m = 0; m < 73; m++)
            {
                printf("_");
            }
            printf("\n");

            printf("\n");
            printf("| ");
            printf("No.");
            printf(" |");
            printf(" Name of Passenger                      ");

            printf("| ");
            printf("Mobile No.");
            printf(" | ");

            printf("Age");
            printf(" | ");

            printf("Seat");
            printf(" | ");

            printf("\n");

            for (int k = 0; k < 73; k++)
            {
                printf("_");
            }
            printf("\n");

            for (int m = 0; m < 73; m++)
            {
                printf("_");
            }
            printf("\n");

            for (int n = 0; n < i; n++)
            {
                printf("\n");
                printf("|  ");
                printf("%d", n + 1);
                printf("  |");
                printf(" %s", passenger[n].name);

                for (int l = 0; l < 69 - 30 - strlen(passenger[n].name); l++)
                {
                    printf(" ");
                }

                printf("| ");
                printf("%llu", passenger[n].phone_number);
                printf(" | ");

                printf("%d", passenger[n].age);
                printf(" |  ");

                printf("%d", passenger[n].preffered_seat);
                printf("  | ");

                printf("\n");

                for (int k = 0; k < 73; k++)
                {
                    printf("_");
                }
                printf("\n");
            }
        }
        else if (a == 3)
        {
            printf("Thank You for visiting...!");
            break;
        }
        else
        {
            printf("!!!ERROR!!!\n");
        }
    }

    return 0;
}