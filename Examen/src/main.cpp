#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <windows.h>
#include <cctype> 
#include <vector>
#include "..\lib\jlUtilities.h"
#include "..\lib\patColor.h"
#include "..\lib\patString.h"
#include "..\lib\patSerie.h"
#include "..\lib\patUtility.h"
#include "..\lib\utilitario.h"
using namespace std;
const string pathPalabra = "../../data/palabra.txt";
  
    using namespace std;

    
    string money;

    //tokens

    int const   Q = 13,
                L = 4,
                TK_ER  = -10,
                TK_GL  = -20,
                TK_GS  = -30,
                TK_DO  = -40,
                TK_HM  = -50;
    string const ALFA = "abcd"; //a = 10 b = 25 c = 50 

  int const mt[Q][L]=
    {//  a      b      c      d             
        {5,     1,     2,     TK_ER},   // qo   
        {TK_ER, 2,     3,     TK_GL},   // q1    
        {9,     3,     4,     TK_GS},   // q2   
        {TK_ER, 4,     4,     TK_DO},   // q3    
        {4,     4,     4,     TK_HM},   // q4    
        {6,     TK_ER, TK_ER, TK_ER},   // q5    
        {7,     TK_ER, TK_ER, TK_ER},   // q6   
        {8,     TK_ER, TK_ER, TK_GL},   // q7    
        {2,     TK_ER, TK_ER, TK_GL},   // q8   
        {10,    TK_ER, TK_ER, TK_GS},   // q9    
        {11,    TK_ER, TK_ER, TK_GS},   // q10    
        {12,    TK_ER, TK_ER, TK_DO},   // q11    
        {4,     TK_ER, TK_ER, TK_DO},   // q12   
    };      

     

vector <string> palabra;

//tokens

int const   Q = 11,
            L = 13,
            TK_ER  = -10,
            TK_SI  = -20,
            TK_SN  = -30,
            TK_SL  = -40;
string const ALFA = "sialtrno (;\n{";

int const mt[Q][L]=
{//  s      i      a      l      t      r      n      o     ' '     (      ;     \n      {         
    {1,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // qo 
    {TK_ER, 2,     3,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q1  
    {TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, 8,     TK_ER, TK_SI, TK_SI, TK_ER, TK_ER, TK_ER},   // q2 
    {TK_ER, TK_ER, TK_ER, 4,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q3  
    {TK_ER, TK_ER, TK_ER, TK_ER, 5,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q4  
    {TK_ER, TK_ER, 6,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q5  
    {TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, 7,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q6 
    {TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_SL, TK_ER, TK_SL, TK_ER, TK_ER},   // q7  
    {TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, 9,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q8 
    {TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_SN, TK_SN},   // q9  
};      

int getIndiceALFA(char c)
{
    int index = ALFA.find(c);
    if(index>=0)
        return index;
    return TK_ER;
}

void validarW(string w)
{
    int q=0, l=0;
    for (auto &&c : w )
    {
        l = getIndiceALFA(c);
        q = mt[q][l];

        switch (q)
        {
        case TK_SI:  cout<< "ok, se valido si";
            break;
        case TK_SN:  cout<< "ok, se valido sino";        
            break;
        case TK_SL:  cout<< "ok, se valido saltar";
            break;
        case TK_ER:  cout<< "palabra ("<< w <<") : NO ES VALIDA";
            break;
        }
    }
}

 
bool readArchivo()
{
    fstream f;
    string line;

    cout << "readArchivo:" << pathPalabra << endl;
    f.open(pathPalabra, ios_base::in);
    if (!f.is_open())
        cout << "Error al abrir el archivo:" << pathPalabra << endl;
        else 
        {
            while(!f.eof())
            {
                string c;
                vector<string> vDato;
                getline(f, line);
                vDato = SplitToVector(line, '\n');
                c = vDato.at(0);
                palabra.push_back(c);
            }
            return true;
        }
        f.close();
        return false;

}

int main()
{
    readArchivo();

    for (auto &&c : palabra)
    {
        if(c.length() < 8)
        {
        validarW(c);
        cout <<endl;
        } 
        else 
        {
            cout << "No es posible lanzar una bomba" <<endl;
        }
    }
    return 0;
}