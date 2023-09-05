/*
*Nombre: Juan Sebastian Leon Espinosa
*Fecha: 09/08/2023
*/

// #include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <windows.h>
#include <vector>
#include "..\lib\patString.h"

using namespace std;

enum color { azul = 1, verde, turqueza, rojo, rosa, amarillo};
string setColor(color c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return "";
}