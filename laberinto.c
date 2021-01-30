#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#define ALTO 15
#define ANCHO 15
#define CUADROS 200

typedef struct{
	int orientacion;        //1: NORTE - 2: ESTE - 3: SUR - 4: OESTE
	int posicionX;
	int posicionY;
}personaje;
const char espacio=' ';
const char pared='#';
const char laberinto[ALTO][ANCHO]=	{	{178,178,' ',178,178,178,178,178,178,178,178,178,178,178,178},
										{178,178,' ',178,178,' ',178,178,178,178,178,178,178,178,178},
										{178,178,' ',178,178,' ',178,178,178,178,178,178,178,178,178},
										{178,178,' ',178,178,' ',' ',' ',' ',' ',' ',' ',' ',' ',178},
										{178,178,' ',178,178,178,178,178,178,178,178,178,178,' ',178},
										{178,178,' ',178,178,' ',' ',' ',' ',' ',' ',' ',' ',' ',178},
										{178,178,' ',178,178,' ',178,' ',178,' ',178,178,178,178,178},
										{178,' ',' ',' ',' ',' ',178,' ',' ',' ',178,' ',' ',178,178},
										{178,' ',178,178,178,178,178,' ',178,178,178,' ',178,178,178},
										{178,' ',178,178,178,178,178,' ',' ',' ',178,' ',' ',' ',178},
										{178,' ',178,178,178,178,178,' ',178,' ',178,178,178,' ',178},
										{178,' ',' ',' ',' ',178,178,' ',178,' ',' ',178,' ',' ',178},
										{178,178,178,178,' ',178,178,' ',178,' ',178,178,' ',178,178},
										{178,178,178,178,' ',178,178,' ',178,' ',' ',' ',' ',178,178},
										{178,178,178,178,' ',' ',178,178,178,178,178,178,178,178,178}};

personaje pj;


void avanza()							//En funcion de la orientacion mueve al personaje en determinada posicion
{
	switch(pj.orientacion)
	{
		case 1:	pj.posicionY--;
				break;
		
		case 2: pj.posicionX++;
				break;
		
		case 3: pj.posicionY++;
				break;
		
		case 4: pj.posicionX--;
	}
}

int curvaDerecha()						//Detecta si hay una curva hacia la derecha relativa
{	
	switch(pj.orientacion)
	{
		case 1:	if(laberinto[pj.posicionY][pj.posicionX+1] == ' ')
					return 1;
				else
					return 0;
				break;
		
		case 2: if(laberinto[pj.posicionY+1][pj.posicionX] == ' ')
					return 1;
				else
					return 0;
				break;
		
		case 3: if(laberinto[pj.posicionY][pj.posicionX-1] == ' ')
					return 1;
				else
					return 0;
				break;
		
		case 4: if(laberinto[pj.posicionY-1][pj.posicionX] == ' ')
					return 1;
				else
					return 0;
				break;
	}
	
	
	
}

int paredEnfrente()								//Detecta si hay una perd al frente relativo
{
	switch(pj.orientacion)
	{
		case 1: if(laberinto[pj.posicionY-1][pj.posicionX] == (char)178)
					return 1;	
				else
					return 0;	
		
		case 2: if(laberinto[pj.posicionY][pj.posicionX+1] == (char)178)
					return 1;
				else
					return 0;
				break;
		
		case 3: if(laberinto[pj.posicionY+1][pj.posicionX] == (char)178)
					return 1;
				else
					return 0;
				break;
		
		case 4: if(laberinto[pj.posicionY][pj.posicionX-1] == (char)178)
					return 1;
				else
					return 0;
				break;
	}
}

int datos()												//En funcion de los datos, orienta al personaje y avanza
{
	
	if(curvaDerecha() == 1)   					 			
	{
		pj.orientacion++;									//Si hay curva a la derecha, cambia la orientacion en sentido horario
		if(pj.orientacion == 5)					
		{
			pj.orientacion=1;								//Limita los datos de giro a 1<=X<=4
		}
		avanza();											//Avanza en funcion del frente relativo
	}
	else
	{
		if(paredEnfrente() == 1)
		{		
			pj.orientacion--;								//Si hay pared al frente, cambia la orientacion en sentido antihorario
			if(pj.orientacion==0)
			{
				pj.orientacion=4;							//Limita los datos de giro a 1<=X<=4
			}
			
		}
		else
		{
			avanza();										//Si no hay pared al frente, avanza
		}
				
	}
	
	
	
	return 0;
}



int main()
{
	int i,j,k;
	pj.orientacion=1;
	pj.posicionX=5;
	pj.posicionY=14;
	
	
	for(i=0;i<ALTO;i++)
		{
			for(j=0;j<ANCHO;j++)
			{
				if(pj.posicionX==j && pj.posicionY==i)
					printf("X");
				else
					printf("%c",laberinto[i][j]);
			}
			printf("\n");
		}
			
	getch();
	
	
	
	
	while(pj.posicionY != 0 )
	{	
		system("cls");
		printf("Posicion en X: %d\nPosicion en Y: %d\nOrientacion: %d\n\n",pj.posicionX,pj.posicionY,pj.orientacion);
		datos();
		
		
		
		for(i=0;i<ALTO;i++)
		{
			for(j=0;j<ANCHO;j++)
			{
				if(pj.posicionX==j && pj.posicionY==i)
					printf("X");
				else
					printf("%c",laberinto[i][j]);
			}
			printf("\n");
		}	
		Sleep(100);
		
	}
	
	
	
}
