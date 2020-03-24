#ifndef PVP_H_INCLUDED
#define PVP_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <stdlib.h>

#include "unelte_x0.h"

using namespace std;


void joc_pvp(char joc[5][5])
{
    initializare(joc);//este apelata functia de initializare pentru a avea incarcata in memorie matrice ce se ocupa de tabla
    unsigned liber = 0,win = 0,jucator = 1,mutare,pi,pj;//liber stabileste cate locrui mai sunt libere, deoarece se stabileste remiza
                                                        // atunci cand nu mai sunt spatii libere
                                                        // win stabileste daca jucatorul 1 a castigat sau daca jucatorul 2 a castigat
                                                        // jucator stabileste daca este randul jucatorului 1 sau 2
                                                        // mutare memoreaza cardinalul indicelui locului in care un jucator vrea sa isi puna X-ul/0-ul
                                                        // pi si pj memoreaza pozitia din matrice al locului ales de jucator
    // se numara locurile libere
    for(int i = 1; i < 4; i++)
        for(int j = 1; j < 4; j++)
            if(joc[i][j] == '#')
                liber++;
    do{
        system("cls");
        afisare(joc);
        do{
            cout<<"Randul jucatorului "<<jucator<<": ";cin>>mutare;
            unsigned cmutare = mutare; // se face o copie a carei valoare va fi distrusa, deoarece este diminuata pentru a stabili daca s-a ajuns la
                                        // la pozitia aleasa ca mutare de jucator
            for(int i = 1; i < 4 && cmutare; i++)
                for(int j = 1; j < 4; j++)
            {
                cmutare--;
                if(cmutare == 0)
                {
                    pi = i;
                    pj = j;
                }
            }
        }while(mutare < 1 || mutare > 9 || joc[pi][pj] != '#');// validare de user input
        liber--; // mutari facute = mai putine locuri libere
        // se stabileste cine a facut mutarea, sa face mutarea si variabila jucator acum marcheaza randul celuilalt jucator
        if(jucator == 1)
        {
            joc[pi][pj] = 'x';
            jucator = 2;
        }
        else
        {
            joc[pi][pj] = '0';
            jucator = 1;
        }
        // se verifica daca jocul s-a incheiat, altfel spus, se verifica daca este indeplinita conditia de remiza, conditia victoriei jucatorului cu X
        // sau a celui cu 0
        // daca jucatorul X a castigast, win va fi 1, altfel va fi 2
        if((joc[1][1] == 'x' && joc[2][1] == 'x' && joc[3][1] == 'x') || (joc[1][2] == 'x' && joc[2][2] == 'x' && joc[3][2] == 'x') || (joc[1][3] == 'x' && joc[2][3] == 'x' && joc[3][3] == 'x') || (joc[1][1] == 'x' && joc[1][2] == 'x' && joc[1][3] == 'x') || (joc[2][1] == 'x' && joc[2][2] == 'x' && joc[2][3] == 'x') || (joc[3][1] == 'x' && joc[3][2] == 'x' && joc[3][3] == 'x') || (joc[1][1] == 'x' && joc[2][2] == 'x' && joc[3][3] == 'x') || (joc[1][3] == 'x' && joc[2][2] == 'x' && joc[3][1] == 'x'))
        {
            system("cls");
            win = 1;
            afisare(joc);
        }
        if((joc[1][1] == '0' && joc[2][1] == '0' && joc[3][1] == '0') || (joc[1][2] == '0' && joc[2][2] == '0' && joc[3][2] == '0') || (joc[1][3] == '0' && joc[2][3] == '0' && joc[3][3] == '0') || (joc[1][1] == '0' && joc[1][2] == '0' && joc[1][3] == '0') || (joc[2][1] == '0' && joc[2][2] == '0' && joc[2][3] == '0') || (joc[3][1] == '0' && joc[3][2] == '0' && joc[3][3] == '0') || (joc[1][1] == '0' && joc[2][2] == '0' && joc[3][3] == '0') || (joc[1][3] == '0' && joc[2][2] == '0' && joc[3][1] == '0'))
        {
            system("cls");
            win = 2;
            afisare(joc);
        }


    }while(win == 0 && liber);
    // se afiseaza mesajul de victorie
    if(win == 1)
        cout<<"Jucatorul 1 a castigat!";
    else if(win == 2)
            cout<<"Jucatorul 2 a castigat!";
        // in cazul in care a iesit din joc fara sa fie castigat nici 1 nici 2, atunci sigur a fost remiza, deoarece jocul continua cat timp
        // nu a castigat nimeni si cat timp exista spatii libere
        else if(win == 0 && liber == 0)
                {
                    system("cls");
                    afisare(joc);
                    cout<<"Egal!";
                }
    _getch();

}

#endif // PVP_H_INCLUDED
