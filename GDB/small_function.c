#include<stdio.h>
void array(int* arr)
{
    for(int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
}

int main()
{
    int a[10];
    array(a);
    return 0;
}