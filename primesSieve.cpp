#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>



int* findPrimes(int max = 100)
{
    int* arr = (int*)malloc(sizeof(int) * max);
    if(arr == 0)
    {
        return 0;
    }

    memset(arr,0, sizeof(int)*21);

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[4] = 5;
    arr[6] = 7;
    arr[10] = 11;
    arr[12] = 13;
    arr[16] = 17;
    arr[18] = 19;
    //3,5,7,9,11,13,15,17,19
    // 5 --> 15
    // 3 --> 9
    
    int maxMinus = max - 1;
    for(int i = 21; i < maxMinus; i+=2)
    {
        int imo = i-1;
        arr[i] = 0;
        if(i % 3 == 0
        || i % 5 == 0
        || i % 7 == 0
        || i % 11 == 0
        || i % 13 == 0
        || i % 17 == 0
        || i % 19 == 0
        )
        {
            arr[imo] = 0;
        }
        else
        {
            int c = 21;
            bool notPrime = false;
            while (c < i)
            {
                if(i % c == 0)
                {
                    arr[imo] = 0;
                    notPrime = true;
                    break;
                }
                c += 2;
            }
            if(notPrime)
            {
                continue;
            }
            else
            {
                arr[imo] = i;
            }
        }    
    }
    return arr;
}

void printPrimes(int* arr, int sizeElements = 0)
{
    for(int i = 0; i < sizeElements; i++)
    {
        if(arr[i] != 0)
        {
            printf("%d, ", arr[i]);
        }
    }
}


int main()
{
    int max = 100000;
    int* primes = findPrimes(max);
    if(primes)
    {
        printPrimes(primes, max);
        free(primes);
    }
    else
    {
        printf("Allocation error!\n");
    }
    return 0;
}




