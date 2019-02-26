int setId_Generico(eGenerica* this,int id)
{
    int indice = 0;

    if(this != NULL && id > 0)
    {
        this -> id = id;
        indice = 1;
    }
    return indice;
}


int setNombre_Generico(eGenerica* this,char* nombre)
{
    int indice = 0;

    if(this != NULL && strlen(nombre))
    {
        strcpy(this -> nombre, nombre);
        indice = 1;
    }
    return indice;
}

int setNumeroTelefonico(eGenerica* this, char* numeroTelefonico)
{
    int indice = 0;

    if(this != NULL && strlen(numeroTelefonico))
    {
        strcpy(this -> numeroTelefonico, numeroTelefonico);
        indice = 1;
    }
    return indice;
}

int setImporte(eGenerica* this, int importe)
{
    int indice = 0;
    if(this != NULL )
    {
        if(importe > 0)
        {
            this -> importe = importe;
            indice = 1;
        }
    }
    return indice;
}