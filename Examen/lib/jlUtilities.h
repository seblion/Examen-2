#include <iostream>
#include <windows.h>
#define TIME 100000

using namespace std;

#define DELAY 1000000


enum color { azul = 1, verde, turqueza, rojo, rosa, amarillo};
string setColor(color c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return "";
}



// Validacion
bool validarNumero(string numero)
{
   for(int i=0; i< numero.length();i++) 
        if (!isdigit(numero[i]))
            return false; //no es un numero
        return true; //es un numero
}

void getNumeroPositivo(const string& label, int& number)
{
    string str;
    bool esNumeroValido = false;

    do
    {
        cout << label;
        cin >> str;

        esNumeroValido = validarNumero(str);
        if (!esNumeroValido)
        {
            cout << "Entrada no válida. Introduzca un número válido." << endl;
        }
    } while (!esNumeroValido);

    number = stoi(str);
}


bool validarSexo(char sexo)
{
    sexo = toupper(sexo); 
    return sexo == 'F' || sexo == 'M';
}

void getSexo(string label, char &sexo)
{
    bool esSexoValido = false;

    do
    {
        cout << label;
        cin >> sexo;
        sexo = toupper(sexo); 

        esSexoValido = validarSexo(sexo);

        if (!esSexoValido)        
        {
            cout << "Entada no valida. Intente nuevamente." << endl;
        }
    } while (!esSexoValido);
}

//Carga animacion
void ingresoO(int veces )
{
    for(int i = 0; i < veces; i++)
    {
        cout << "\tIngrese una opcion:  0oo\r";
        usleep(TIME);
        cout << "\tIngrese una opcion:  o0o\r";
        usleep(TIME);
        cout << "\tIngrese una opcion:  oo0\r";
        usleep(TIME);
    }
    cout <<"\r\t Ingrese una opcion:    ";
}

void cargaCien(int i,int tam)
{
    char signo[]="\\|/-| ";
        printf("%c  %%%i", signo[i%6], (i * 100) / (tam - 1));
        usleep(TIME*2);
        printf("\r");
}

void cargaC(int i, int tam)
{
    char signo[] = "\\|/-| ";
    printf("%c  %%%i", signo[i % 6], (i * 100) / tam);
    usleep(TIME * 2);
    printf("\r");
}

void menu(int &opc)
{
    bool opcValida = false;
    do{
            cout<<endl << setColor(azul) << "\t\tMENU" <<endl;
            cout<< setColor(verde)  <<"\t 1. Recuperar Cliente"<< endl
                                <<"\t 2. Recuperar Mascota"<< endl
                                <<"\t 3. Presentar Cliente"<< endl
                                <<"\t 4. Presentar Mascota"<< endl
                                <<"\t 5. Agregar Cliente"<< endl
                                <<"\t 6. Agregar mascota"<< endl
                                <<"\t 7. Guardar mascota"<< endl
                                <<"\t 8. Guardar cliente"<< endl
                                <<"\t 9. Salir" <<endl;
            ingresoO(2);

            try
            {
                cin >> opc;
                cin.clear();
                if (opc>0 && opc<=9)
                {
                    opcValida = true;
                    break;
                } 
                throw invalid_argument("Opc no valida");
            }
            catch(...)
            {
                cout<< "\n    :( Opcion no valida... "; 
                fflush(stdin);
            }
    }while(!opcValida);
}

void noExisteID()
{
    cout <<setColor(rojo)<< "No existe el ID ingresado" << endl << endl;
}
