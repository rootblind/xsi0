#ifndef UNELTE_X0_H_INCLUDED
#define UNELTE_X0_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void initializare(char joc[5][5])
{
    for(int i = 0; i < 5; i++)
        joc[i][0] = '|';
    for(int i = 0; i < 5; i++)
        joc[i][4] = '|';
    for(int i = 0; i < 5; i++)
        joc[0][i] = '=';
    for(int i = 0; i < 5; i++)
        joc[4][i] = '=';


    for(int i = 1; i < 4; i++)
        for(int j = 1; j < 4; j++)
            joc[i][j] = '#';
}

void afisare(char joc[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout<<joc[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
}


#endif // UNELTE_X0_H_INCLUDED
