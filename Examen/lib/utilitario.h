#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNumber(char label[])
{
    char numero[20];
    int n=0;

    printf("%s ", label);
    gets(numero);
    sscanf(numero,"%i", &n);
    return n;

}
/**
 *  si retorna 0 son iguales
*/
int cmpString(char str1[], char str2[])
{
    // longitud de las cadenas
    int str1len  = sizeof(&str1);
    int str2len  = sizeof(&str2);
    //printf("len : %i ", len);

    //logitud diferete fin de comparacion
    if(str1len != str2len)
        return str1len-str2len;

    //compara cada uno de los elementos
    for (int i = 0; i < str1len; i++)
        if(str1[i] != str2[i])
            return 1;
    return 0;
}

// void TreeNavidad()
// {
//     int len =10;
//     // char arbol[len][len];
//     // for (int f = 0; f < len/2; f++)
//     // {
//     //     for (int c = 0; c < len; c++)
//     //         if(((len/2 - f) < c ) && (c < (len/2 + f)))
//     //             printf("  x");
//     //         else
//     //             printf("  ");
//     //     printf("\n");
//     // }

   
// }
///////////////////////////////////////////
void cmpStringTest()
{
    char nombre1[]="pato";
    char nombre2[]="pato";

    // if(nombre1 == nombre2)
    //     printf("Son iguales");
    // else
    //     printf("NO son iguales");
    
    int b =0;
    for (int i = 0; i < 4; i++)
    {
        if(nombre1[i] != nombre2[i])
            b++;
    }

    if(b==0)
        printf("Son iguales");
    else
        printf("NO son iguales");
    
    
    
    printf("\n\n\n");
}

void HolaLib()
{
    printf("hola desde la libreria..\n\n\n");
}

void getTerminalscanf()
{
    char nombre1[20];
    char nombre2[20];

    printf("Ingresa nombre1:");
    scanf("%s",nombre1);

    printf("Ingresa nombre2:");
    scanf("%s",nombre2);
    
    printf("\n\n\n");
    printf("%s \n", nombre1);
    printf("%s \n", nombre2);
    printf("\n\n\n");

}


void getTerminalgets()
{
    char nombre1[20];
    char nombre2[20];
    char numero[20];
    int n=0;
    printf("Ingresa nombre1:");
    gets(nombre1);

    printf("Ingresa nombre2:");
    gets(nombre2);

    // printf("Ingresa numero:");
    // scanf("%i", &n);

    printf("Ingresa numero:");
    gets(numero);
    sscanf(numero,"%i", &n);
    
    printf("\n\n\n");
    printf("%s \n", nombre1);
    printf("%s \n", nombre2);
    printf("%i \n", n);
    printf("\n\n\n");

}