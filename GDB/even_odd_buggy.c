#include<stdio.h>

void swap(int* odds, int* even, int index)
{
    int temp = odds[index];
    odds[index] = even[index];
    even[index] = temp;
}

int main()
{
    int odds[] = {1, 3, 5, 7};
    int even[] = {2, 4, 6, 8};

    for(int i = 0; i < 4; i++)
    {
        swap(odds, even, i);
    }

    printf("The odds resuls are:\n");

    for(int i = 0; i < 4; i++)
    {
        printf("odd[%d] = %d:\n",i, odds[i]);
    }

    printf("The even results are:\n");
    for(int i = 0; i < 4; i++)
    {
        printf("even[%d] = %d:\n",i, even[i]);
    }

    return 0;
}