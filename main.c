#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ver_mut(int tabla[8][8], int i, int j, int k, int l)
{
    int index;
    switch (tabla[i-1][j-1])
    {
    case 1:
            if( i==k )
            {
                if( j<l )
                {
                    for( index=j+1; index<l; index++ )
                        if( tabla[i-1][index-1] != 0 )
                            return 0;
                }
                else
                {
                    for( index=l+1; index<j; index++ )
                        if( tabla[i-1][index-1] != 0 )
                            return 0;
                }
                return 1;
            }
            else
                if( j==l )
                {
                    if( i<k )
                    {
                        for( index=i+1; index<k; index++ )
                            if( tabla[index-1][j-1] != 0 )
                                return 0;
                    }
                    else
                    {
                        for( index=k+1; index<i; index++ )
                            if( tabla[index-1][j-1] != 0 )
                                return 0;
                    }
                    return 1;
                }
                else
                    return 0;
    case 2:
            if( i==k-1 && j==l-2 )
                return 1;
            else if( i==k-1 && j==l+2 )
                        return 1;
                else if( i==k+1 && j==l-2 )
                        return 1;
                    else if( i==k+1 && j==l+2 )
                            return 1;
                        else if( i==k-2 && j==l-1 )
                                return 1;
                            else if( i==k-2 && j==l+1 )
                                    return 1;
                                else if( i==k+2 && j==l-1 )
                                        return 1;
                                    else if( i==k+2 && j==l+1 )
                                            return 1;
                                        else
                                            return 0;
    case 3:
            if( abs(i-k) == abs(j-l) )
            {
                /*if( j<l )
                {
                    for( index=j+1; index<l; index++ )
                        if( tabla[i][index] != 0 )
                            return 0;
                }
                else
                {
                    for( index=l+1; index<j; index++ )
                        if( tabla[i][index] != 0 )
                            return 0;
                }*/
                return 1;
            }
            else
                return 0;
    default: return 1;

    }

}

void citire(int tabla[8][8])
{
    char ci,cj,ck,cl;
    int   i, j, k, l;

    tryagain:
    printf("\n\tScrieti coordonatele piesei pe care doriti sa o mutati\t");

    tryagain1:

    ci = getch();
    i = (int)ci - '0';
    printf("%d",i);

    cj = getch();
    j = (int)cj - '0';
    printf("%d\n",j);

    if( i<1 || j<1 || i>8 || j>8 )
    {
        printf("\tMai incercati odata\t");
        goto tryagain1;
    }
    if( tabla[i-1][j-1] == 0 )
    {
        printf("\tUita-te mai bine\t");
        goto tryagain1;
    }
    printf("\tsi acum unde sa ajunga:");

    tryagain2:

    ck = getch();
    k = (int)ck - '0';
    printf("%d",k);

    cl = getch();
    l = (int)cl - '0';
    printf("%d\n",l);

    if( k<1 || l<1 || k>8 || l>8 )
    {
        printf("\tMai incercati odata\t");
        goto tryagain2;
    }
	
    if( !ver_mut(tabla,i,j,k,l) )
    {
        printf("\tMai incearca odata\n");
        goto tryagain;
    }
    printf("%d %d\n",k,l);

    tabla[ k -1 ][ l -1 ] = tabla[ i -1 ][ j -1];
    tabla[ i -1 ][ j -1 ] = 0;

}

void afisare(int tabla[8][8])
{
    int i,j;
    char ch='a';

    for(j=0;j<8;j++)
        printf("     %c     ",ch++);
    printf("\n");
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            printf("|---------|");
        printf("\n");
        for(j=0;j<8;j++)
            switch(tabla[i][j])
            {
                case 0: printf("|         |");break;
                case 1: printf("|         |");break;
                case 2: printf("|    __   |");break;
                case 3: printf("|         |");break;
                case 4: printf("|    |    |");break;
                case 5: printf("|         |");break;
                case 6: printf("|    _    |");break;
            }
        printf("\n");
        for(j=0;j<8;j++)
            switch(tabla[i][j])
            {
                case 0: printf("|         |");break;
                case 1: printf("|  [---]  |");break;
                case 2: printf("|   / o|  |");break;
                case 3: printf("|    0    |");break;
                case 4: printf("|   = =   |");break;
                case 5: printf("|   \\^/   |");break;
                case 6: printf("|   ( )   |");break;
            }

        printf("\n");
        for(j=0;j<8;j++)
            switch(tabla[i][j])
            {
                case 0: printf("|         |");break;
                case 1: printf("|   | |   |");break;
                case 2: printf("|  [__ |  |");break;
                case 3: printf("|    O    |");break;
                case 4: printf("|    |    |");break;
                case 5: printf("|   / \\   |");break;
                case 6: printf("|   / \\   |");break;
            }
        printf(" %d\n",i+1);
        for(j=0;j<8;j++)
            switch(tabla[i][j])
            {
                case 0: printf("|         |");break;
                case 1: printf("|  [___]  |");break;
                case 2: printf("|   /__|  |");break;
                case 3: printf("|   (_)   |");break;
                case 4: printf("|  (___)  |");break;
                case 5: printf("|  (___)  |");break;
                case 6: printf("|  (___)  |");break;
            }
        printf("\n");
        for(j=0;j<8;j++)
            printf("|         |");
        printf("\n");
    }
    for(j=0;j<8;j++)
        printf("|---------|");
}

int main()
{
    int tabla[8][8]={{1,2,3,4,5,3,2,1},
					{6,6,6,6,6,6,6,6},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{6,6,6,6,6,6,6,6},
					{1,2,3,4,5,3,2,1}};
    for(;;)
    {
        afisare(tabla);
        citire(tabla);
        system("cls");
    }
    return 0;
}
