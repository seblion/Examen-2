#include <stdio.h>
#include <unistd.h>

// #define DELAY 100000
/**
 * showPares, genera pares 
 * @nro, numero de pares a generar
*/
void showPares(int nro)
{
    for (int i = 0; i < nro*2 ; i++)
    {
        if(i%2==0)
            printf("%i ", i);
    }
    printf("\n");
}

/**
 * showImpares, genera impares 
 * @nro, numero de pares a generar
*/
void showImpares(int nro)
{
    for (int i = 0; i < nro*2; i++)
    {
        if(i%2!=0)
            printf("%i ", i);
    }
}

/**
 * showSignoAlernadoFibonaci, presenta signos alternos con la serie fibonaci 
 * @nro, numero de pares a generar
*/
void  showSignoAlernadoFibonaci(int nro)
{
    int a =0, b=1, c=1;
    for (int i = 0; i < nro; i++)
    {
        for (int s = 0; s < c; s++)
            printf ( (i %2==0) ?  "+" : "-");

        printf("\t");
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n"); 
}

void showCuadrado(int size)
{
    //          * * * *  h..... v
    //          *     *         . 
    //          *     *         .
    //          * * * *         .

    for (int v = 1; v <= size; v++)
    {
        for (int h = 1; h <= size; h++)
        {
            if( (h == 1 || h== size) ||
                (v == 1 || v== size) )
                printf("* ");
            else
                printf("  ");
                //usleep(50000);
        }
        printf("\n");
    }

    // for (int v = 0; v < size; v++)
    // {
    //     for (int h = 0; h < size; h++)
    //         if( (h == 0 || h== size-1) ||
    //             (v == 0 || v== size-1) )
    //             printf("* ");
    //         else
    //             printf("  ");
    //     printf("\n");
    // }
}


void showTriangulo(int size)
{
    //      *
    //      * *
    //      * * *
    //      * * * *
    //      * * * * *

    for (int f = 1; f <= size; f++)
    {
        for (int c = 1; c <= size; c++)
        {
            if (f >= c)
                printf ("* ");
            else
                printf("  ");
            usleep(DELAY);
        }
        printf("\n");
    }
    
}

void showCruz(int size)
{
    for (int f = 1; f <= size; f++)
    {
        for (int c = 1; c <= size; c++)
        {
            if ((c==size/2 + 1)||(f==size/2 + 1))
                printf ("* ");
            else
                printf("  ");
            //usleep(DELAY);
        }
        printf("\n");
    }
    
}

//         +    --  +++ ----    +++++    ------
//          1   0   3   0       5
void serieSignosAlternosOptimo(int cantidad)
{
    for(int count = 1; (count <= cantidad) ; count++)
    {
        for(int i =1; i<=count; i++)
            printf("%c", (count % 2 == 0)?'-': '+');
        printf("\t");
    }
}
// Serie:  +    --    +++    ----   +++++   ------ ...
//count:   1    2       3    4         5         6
void serieSignosAlternos(int cantidad)
{
    //for (1...10)   while(< >  true)
    int count = 1;
    char signo = '+';

    while(count <= cantidad)
    {
        if(count % 2 == 0 )
            signo = '-';
        else
        {
            signo = '+';
        }   
        
        for(int i =1; i<=count; i++)
        {
            printf("%c", signo);
        }    
        printf("\t");
        count = count + 1;
    }
}