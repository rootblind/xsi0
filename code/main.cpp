#include <iostream>
#include <conio.h>
#include <stdlib.h>

#include "pvp.h"
#include "pve.h"
#include "unelte_x0.h"

using namespace std;


void tutorial(char joc[5][5])
{
    system("cls");
    cout<<"x si 0 este un joc in 2, cel ce reuseste sa alinieze in verticala, orizontala sau pe diagonala";
    cout<<"\ncaracterul cu care joaca, castiga, daca nu mai exista spatii si nimeni nu a reusit sa alinieze\n";
    cout<<"caracterele, atunci jocul se va incheia in egalitate.";
    cout<<"\n\nPentru a-ti plasa caracterul, fie el x sau 0, trebuie sa dai cardinalul corespunzator casetei\n";
    cout<<"respective, acestea fiind numerotate de la 1 la 9, numerotarea incepand de la stanga sus, pana la dreapa jos.";
    getch();
    cout<<"\nExemplu: initial tabelul arata asa: \n";
    initializare(joc);
    afisare(joc);
    getch();
    cout<<endl<<"Dar daca aleg sa joc cu x si aleg sa il pun pe x pe pozitia 7, tabelul va arata asa:\n";
    joc[3][1] = 'x';
    afisare(joc);
    cout<<endl<<"Apasa o tasta pentru a te intoarce la meniu!";
    getch();
}
void meniu(char joc[5][5])
{
    system("cls");
    unsigned select;
    do{
        do{
        system("cls");
        cout<<"1- Joaca vs un prieten\n2- Joaca vs calculatorul tau\n3- Tutorial\n0- Iesire\n";
        cout<<"Alege: ";cin>>select;
        }while(select != 1 && select != 2 && select != 3 && select != 0);
        if(select == 3)
            tutorial(joc);
        else if(select == 1)
                joc_pvp(joc);
                else if(select == 2)
                    joc_pve(joc);

    }while(select != 0);

}

int main()
{
    char joc[5][5];
    meniu(joc);
}
