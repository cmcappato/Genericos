#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"



int main()
{
    int opcion;
    LinkedList* listadoGenerico = ll_newLinkedList();

    do
    {
    	printf("******************************************************************************* \n");
        printf("1- \n");
        printf("2- \n");
        printf("3- \n");
        printf("4- \n");
        printf("5- \n");
        printf("6- \n");
        printf("******************************************************************************* \n");
        printf("Elija una opcion: \n");
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4
                break;
            case 5:
                break;
            case 6:
                break;
            case 10:
                printf("Gracias por utilizar el programa \n");
                break;
            default:
                printf("Error, ingrese una opcion del 1 al 10");
        }
        system("pause");
        system("cls");
    }while (opcion != 10);
	return 0;
}