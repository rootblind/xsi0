#ifndef PVE_H_INCLUDED
#define PVE_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>

#include "unelte_x0.h"

using namespace std;


void joc_pve(char joc[5][5])
{
    initializare(joc);
    unsigned liber = 0,win = 0,jucator = 1,mutare,pi,pj;
    for(int i = 1; i < 4; i++)
        for(int j = 1; j < 4; j++)
            if(joc[i][j] == '#')
                liber++;
    do{
        system("cls");
        afisare(joc);

        do{
            if(jucator  == 1)
            {
                cout<<"Este randul tau: ";cin>>mutare;
            }
            else
                mutare = rand() % 10;
            unsigned cmutare = mutare;
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
        }while(mutare < 1 || mutare > 9 || joc[pi][pj] != '#');
        liber--;
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
    if(win == 1)
        cout<<"Jucatorul 1 a castigat!";
    else if(win == 2)
            cout<<"Jucatorul 2 a castigat!";
        else if(win == 0 && liber == 0)
                {
                    system("cls");
                    afisare(joc);
                    cout<<"Egal!";
                }
    getch();
}

#endif // PVE_H_INCLUDED
