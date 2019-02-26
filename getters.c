int getId_Generico(eGenerica* this, int* id)
{
    int indice = 0;

    if(this != NULL)
    {
        *id = this -> id;
        indice = 1;
    }
    return indice;
}



int getNombre_Generico(eGenerica* this,char* nombre)
{
    int indice = 0;
    if(this != NULL)
    {
        strcpy (nombre, this->nombre);
        indice = 1;
    }
    return indice;
}

int getSexo(eGenerica* this, char* sexo)
{
    int indice = 0;

    if(this != NULL)
    {
        strcpy (sexo, this -> sexo);
        indice = 1;
    }
    return indice;
}

int getNumeroTelefonico(eGenerica* this, char* numeroTelefonico)
{
    int indice = 0;

    if(this != NULL)
    {
        strcpy (numeroTelefonico, this -> numeroTelefonico);
        indice = 1;
    }
    return indice;
}

int getImporte(eGenerica* this, int* importe)
{
    int indice = 0;
    if(this != NULL)
    {
        *importe = this -> importe;
        indice = 1;
    }
    return indice;
}

int getIdAbono(eGenerica* this, int* id)
{
    int indice = 0;

    if (this != NULL)
    {
        *id = this->id;
        indice = 1;
    }
    return indice;
}