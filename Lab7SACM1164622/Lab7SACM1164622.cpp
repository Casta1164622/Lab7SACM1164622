#include <iostream>
#include "Lista.h"
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unordered_map>

Lista<int> listaNumeros;
unordered_map<int,int> numeroHash;

void menuPrincipal();
void menuBusqueda();

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int HashFunction(int n) 
{
    return (n * n) % 100;
}

void menuBusqueda()
{
    string selection, selectSearch, selection2;
    int select, search, select2;
    bool pass = false;
    int first = 0;
    int middle;
    int last = listaNumeros.GetCount() - 1;

    do 
    {
        listaNumeros.Clear();
        cout << "1. Busquedas\n";
        cout << "Ingrese la cantidad de numeros aleatorios\n";

        getline(cin, selection);

        if (is_number(selection))
        {
            select = stoi(selection);
            if (select > 0 && 100) pass = true;
        }

        srand(time(0));

        for (int i = 0; i < select; i++)
        {
            int numeroAdd = rand() % 100;
            listaNumeros.Add(numeroAdd);

            numeroHash.insert({ HashFunction(numeroAdd), numeroAdd });

        }

    } while (pass != true);
    
    do
    {
        cout << "Lista generada:\n";
        for (int i = 0; i < listaNumeros.GetCount(); i++)
        {
            cout << "- " + to_string(listaNumeros.GetItem(i)->data) + "\n";
        }

        cout << "Seleccione una opcion\n";
        cout << "1| Busqueda secuencial\n";
        cout << "2| Busqueda binaria\n";
        cout << "3| Busqueda por hashes\n";
        cout << "0| Regresar\n";

        getline(cin, selection2);

        if (is_number(selection2))
        {
            select2 = stoi(selection2);
        }
        else { select2 = 100000000; }

        if (selection2 == "")
        {
            select2 = 10;
        }

        if (select2 == 1 || select2 == 2 || select2 == 3) 
        {
            cout << "Ingrese el numero a buscar\n";

            getline(cin, selectSearch);
            if (is_number(selectSearch))
            {
                search = stoi(selectSearch);
            }
        }
        
        switch (select2)
        {
        case 1:
            for (int i = 0; i < listaNumeros.GetCount(); i++) 
            {
                if (search == listaNumeros.GetItem(i)->data) 
                {
                    cout << "Se encontro el numero en la posicion " << i + 1 << "\n";
                    cout << "Presione una tecla para continuar\n";
                    getwchar();
                    return;
                }
            }
            cout << "El numero no se encontro en la lista\n";
            cout << "Presione una tecla para continuar\n";
            getwchar();
            return;
            
            break;
        case 2:

             first = 0;
             middle;
             last = listaNumeros.GetCount()-1;

             while (first <= last) 
             {
                middle = (first + last) / 2;

                if (search == listaNumeros.GetItem(middle)->data) 
                {
                    cout << "Se encontro el numero en la posicion " << middle + 1 << "\n";
                    cout << "Presione una tecla para continuar\n";
                    getwchar();
                    return;
                }
                else 
                {
                    if (listaNumeros.GetItem(middle)->data > search) 
                    {
                        last = middle - 1;
                    }
                    else 
                    {
                        first = middle + 1;
                    }
                }
             }
            cout << "El numero no se encontro en la lista\n";
            cout << "Presione una tecla para continuar\n";
            getwchar();
            return;
            break;
        case 3: 

            if (numeroHash.find(HashFunction(search)) == numeroHash.end()) 
            {
                cout << "El numero no se encontro en la lista\n";
                cout << "Presione una tecla para continuar\n";
                getwchar();
            }
            else 
            {
                cout << "Se encontro el numero en la lista "<< "\n";
                cout << "Presione una tecla para continuar\n";
                getwchar();
            }
            break;
        case 0:
            menuPrincipal();
            return;
        default:
            menuBusqueda();
        }
    } while (select != 0);
}

void menuPrincipal()
{
    string selection;
    int select;

    do
    {
        system("cls");
        cout << "Lab7 SACM\n";
        cout << "Seleccione una opcion\n";
        cout << "1| Busquedas\n";
        cout << "2| Figuras\n";
        cout << "0| Salir del programa\n";

        getline(cin, selection);

        if (is_number(selection))
        {
            select = stoi(selection);
        }
        else { select = 100000000; }

        if (selection == "")
        {
            select = 10;
        }

        switch (select)
        {
        case 1:
            menuBusqueda();
            break;
        case 2:
            
            break;
        case 0:
            exit(0);
            return;
        default:
            menuPrincipal();
        }
    } while (select != 0);
}

int main()
{
    menuPrincipal();
}