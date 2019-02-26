int controller_loadFromText(char* path, LinkedList* pArrayList_Generica)
{
    int indice = 0;
    FILE* pArchivoTexto = fopen( path, "r");

    if(pArchivoTexto != NULL && pArrayList_Generica != NULL)
    {
        indice = parser_ClientFromText(pArchivoTexto, pArrayList_Generica);
        printf("Archivo cargado con exito\n");
    }
    else
    {
        printf("El archivo no se pudo cargar\n");
        fclose(pArchivoTexto);
    }
    fclose(pArchivoTexto);
    return indice;
}


int controller_saveAsText(char* path, LinkedList* pArray_Generica)
{
    int indice = 0;
    int largoLista = ll_len(pArray_Generica);
    eAux* pArray_GenericaAux;
    FILE* fp = fopen(path, "w");
    int i;

    if(fp==NULL)
    {
        printf("Error al abrir archivo para guardar\n");
        return indice;
    }
    fprintf(fp, "Id,Tipo,Id Cliente,Importe final\n");
    if(pArray_Generica!=NULL)
    {
        for(i = 0; i < largoLista; i++)
        {
            pArray_GenericaAux = (eAux*)ll_get(pArray_Generica, i);
            fprintf(fp, "%d,%d,%d,%d\n", pArray_GenericaAux->id, pArray_GenericaAux->tipo, pArray_GenericaAux->idCliente, pArray_GenericaAux->importeFinal);
        }
        printf("Se ha guardado el archivo con exito\n");
        indice = 1;
    }
    fclose(fp);
    return indice;
}


int controller_saveAsBinary(char* path, LinkedList* pArray_Generica)
{
    int indice = 0;
    int largoLista = ll_len(pArray_Generica);
    eAux* pAux;
    FILE* fp = fopen(path, "wb");
    int i;

    if(fp == NULL)
    {
        printf("Error al guardar el archivo\n");
        return indice;
    }

    if(pArray_Generica != NULL)
    {
        for(i = 0; i < largoLista; i++)
        {
            pAux = (eAux*)ll_get(pArray_Generica, i);
            fwrite(pAux, sizeof(eAux), 1, fp);
        }
        printf("Se ha guardado el archivo con exito\n");
        indice = 1;
    }
    fclose(fp);
    return indice;
}
