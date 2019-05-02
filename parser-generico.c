#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entidad.h"


int parser_ClientFromText(FILE*, LinkedList*);

int parser (FILE* pFile, LinkedList* generico)
{
	eGenerica* pGenerica;
	int cantidad; // cantidad de variables que va a tener la estructura
	//declaro estructuras necesarias (de tipo char)
	int indice = -1;

	if(pFile != NULL)
	{
		cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n"/*varian segun cantidad de variables, en este caso 4*/, /*nombres de las variables declaradas*/);
		do
		{
			cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n"/*varian segun cantidad de variables, en este caso 4*/, /*nombres de las variables declaradas*/);

			if (cantidad == 4)
			{
				pGenerica = newParametrosGenericos (/*variables*/);

				if (pCliente != NULL)
				{
					ll_add (generico, pGenerica);
				}
                else
                {
                    printf("No hay mas espacio en memoria");
                }
                indice = 1;
			}
            else
            {
                break;
            }
        }while(!feof(pFile));
	}
	return indice;
}
