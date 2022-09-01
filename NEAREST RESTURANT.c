#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//Restaurant Finder
//Group 4
//

typedef struct brand{  //
    char *name;
    int XAxis;
    int YAxis;
    int id;
}
brand;

brand** toBeDefined();  //Prototype of toBeDefined


//Prototype of shortest path function. Change the return type accordingly
//xUserInput == X Coordinate of User given as input
//yUserInput == Y Coordinate of User given as input
//arrOfBrands ==  Array of strutures containing information about the brands
void Distance(brand** arrOfBrands,int *dist, int xUserInput, int yUserInput); 
void Id(brand** arrofBrands, int *id);
void Sort(int* dist, int* id);
void Output(brand** arrOfBrands, int *id, int* dist);

int main()
{
    //Returns an array containing the list of all restaurants, in the form of
    //an array of structures
    brand** arrOfBrands = toBeDefined();   
         
    printf("Welcome to the Restaurant Finder!");
    
    //User coordinates
    int xUser = 0, yUser = 0;
    do
    {
        printf("Enter your coordinates(in a 10X10 grid)\n");
        printf("Enter X coordinate: ");
        scanf("%d", &xUser);
        printf("Enter Y coordinate: ");
        scanf("%d", &yUser);
    } while ((!(xUser >= 0 && xUser < 10)) && (!(yUser >= 0 && yUser < 10)));
    
    int dist[10];
    Distance(arrOfBrands,dist, xUser, yUser);    //To code the shortest path function

    int idarr[10];   
    Id(arrOfBrands,idarr);

    Sort(dist,idarr);  //to sort distance and id in same order

    Output(arrOfBrands,idarr,dist); //To print restaurant data in ascending order of distance

    //After above function call ends, this frees all allocated memory
    // free(arrOfBrands);
    return 0;
}

brand** toBeDefined()   // Returns an array of structures, containing information regarding restaurants
{
    brand** mainArray = malloc(sizeof(brand) * 10);

    brand* mcd1 = malloc(sizeof(brand));
    mcd1->name = "McDonalds Main Branch";
    mcd1->XAxis = 0;
    mcd1->YAxis = 7;
    mcd1->id = 1;
    mainArray[0] = mcd1;

    brand* mcd2 = malloc(sizeof(brand));
    mcd2->name = "McDonalds, XYZ Branch";
    mcd2->XAxis = 2;
    mcd2->YAxis = 3;
    mcd2->id = 2;
    mainArray[1] = mcd2;

    brand* la1 = malloc(sizeof(brand));
    la1->name = "La Pino's Main Branch";
    la1->XAxis = 0;
    la1->YAxis = 3;
    la1->id = 3;
    mainArray[2] = la1;

    brand* la2 = malloc(sizeof(brand));
    la2->name = "La Pino's, ZYX Branch";
    la2->XAxis = 2;
    la2->YAxis = 3;
    la2->id = 4;
    mainArray[3] = la2;

    brand* do1 = malloc(sizeof(brand));
    do1->name = "Domino's Pizza";
    do1->XAxis = 0;
    do1->YAxis = 0;
    do1->id = 5;
    mainArray[4] = do1;

    brand* kfc = malloc(sizeof(brand));
    kfc->name = "KFC";
    kfc->XAxis = 9;
    kfc->YAxis = 7;
    kfc->id = 6;
    mainArray[5] = kfc;

    brand* bcw1 = malloc(sizeof(brand));
    bcw1->name = "Belgian Waffle, HQ";
    bcw1->XAxis = 7;
    bcw1->YAxis = 9;
    bcw1->id = 7;
    mainArray[6] = bcw1;

    brand* bcw2 = malloc(sizeof(brand));
    bcw2->name = "Belgian Waffle, DWHQ";
    bcw2->XAxis = 5;
    bcw2->YAxis = 5;
    bcw2->id = 8;
    mainArray[7] = bcw2;

    brand* hc1 = malloc(sizeof(brand));
    hc1->name = "Hocco Eatery, Main Branch";
    hc1->XAxis = 8;
    hc1->YAxis = 8;
    hc1->id = 9;
    mainArray[8] = hc1;

    brand* neem = malloc(sizeof(brand));
    neem->name = "Under the Neem Tree";
    neem->XAxis = 3;
    neem->YAxis = 7;
    neem->id = 10;
    mainArray[9] = neem;

    return mainArray;
}

//xUserInput == X Coordinate of User given as input
//yUserInput == Y Coordinate of User given as input
//arrOfBrands ==  Array of strutures containing information about the brands
void Distance(brand** arrOfBrands, int* dist, int xUserInput, int yUserInput)
{
    for(int i=0;i<10;i++){
        dist[i]=(abs(xUserInput - arrOfBrands[i]->XAxis) + abs(yUserInput - arrOfBrands[i]->YAxis));
    }
}

void Id(brand** arrofBrands, int*id)
{
    for(int i=0;i<10;i++){
        id[i]=arrofBrands[i]->id;
    }
}

void Sort(int* dist, int* id)
{
    int temp;
    for(int i=9;i>0;i--){
        for(int j=0;j<i;j++){
            if(dist[j]>dist[j+1]){
                temp=dist[j];
                dist[j]=dist[j+1];
                dist[j+1]=temp;

                temp=id[j];
                id[j]=id[j+1];
                id[j+1]=temp;
            }
        }
    }
}

void Output(brand** arrOfBrands, int *id, int* dist)
{
    printf("Best Restaurants near you are : \n");
    printf("Sr.No.  Distance  Name&Location \n");
    for(int i=0;i<10;i++){
        printf("%d.      %d         %s (%d,%d)\n",(i+1), dist[i], arrOfBrands[id[i]-1]->name, arrOfBrands[id[i]-1]->XAxis,arrOfBrands[id[i]-1]->YAxis);

    }printf("\n");
}