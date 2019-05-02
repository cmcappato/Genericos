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

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivoBinario;
    int indice = 0;

    if ((pArchivoBinario = fopen(path, "rb")) != NULL)
    {
        indice = parser_EmployeeFromBinary(pArchivoBinario, pArrayListEmployee);
    }

    fclose(pArchivoBinario);

    return indice;
}


Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee = (Employee*) malloc(sizeof(Employee));

    return pEmployee;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr)
{
    Employee* pEmployee;

    pEmployee = employee_new();

    if(pEmployee!=NULL)
    {
        employee_setId (pEmployee, atoi(idStr));
        employee_setNombre (pEmployee, nombreStr);
        employee_setHorasTrabajadas( pEmployee, atoi(horasTrabajadasStr));
    }

    return pEmployee;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployee = employee_new();
    int indice = 0;
    char auxiliarId[20];
    int auxiliarIdDecimal;
    char auxiliarNombre[50];
    char auxiliarHoras[30];
    char auxiliarSueldo[20];

    if(pArrayListEmployee != NULL)
    {
        auxiliarIdDecimal = getValidInt ("Ingrese ID del empleado: ", "Error, ingrese un ID valido: ", 1, 10000);
        itoa(auxiliarIdDecimal, auxiliarId, 10);

        getValidStringEspaciosYLetras ("Ingrese nombre del empleado: ", "Error, ingrese un nombre valido: ", auxiliarNombre);
        getValidStringNumeros ("Ingrese las horas trabajadas: ", "Error, ingrese horas validas: ", auxiliarHoras);
        getValidStringNumeros ("Ingrese el sueldo del empleado: ", "Error, ingrese sueldo valido: ", auxiliarSueldo);

        newEmployee = employee_newParametros(auxiliarId, auxiliarNombre, auxiliarHoras);

        if (auxiliarId != NULL)
        {
            auxiliarIdDecimal = atoi(auxiliarSueldo);
            employee_setSueldo(newEmployee, auxiliarIdDecimal);
            ll_add(pArrayListEmployee, newEmployee);
            indice = 1;
        }
    }
    return indice;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    Employee* pNewEmployee;
    int indice = 0;
    int tamLista = ll_len(pArrayListEmployee);
    char auxId[20];
    int auxiliarId;
    int auxiliarIdDecimal;
    char auxiliarNombre [50];
    char auxiliarHoras [30];
    int horasAux;
    char auxiliarSueldo [20];
    int sueldoAux;
    int option;

    if (pArrayListEmployee != NULL)
    {
        tamLista = ll_len(pArrayListEmployee);
        auxiliarId = getValidInt("Ingrese el ID del empleado que desea modificar: ", "Error, ID no valido, ingrese nuevamente: ", 1, 10000);

        for (int i = 0; i < tamLista; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxiliarId == pEmployee -> id)
            {
                do
                {
                    printf("Elija que desea modificar: \n");
                    printf("1- ID del empleado \n");
                    printf("2- Nombre del empleado \n");
                    printf("3- Horas que trabajo el empleado \n");
                    printf("4- Sueldo del empleado \n");
                    printf("5- Salir");
                    printf("*******************************************************************************\n");
                    scanf("%d", &option);

                    switch (option)
                    {
                        case 1:
                            auxiliarIdDecimal = getValidInt ("Ingrese ID del empleado: ", "Error, ingrese un ID valido: ", 1, 10000);
                            itoa(auxiliarIdDecimal, auxId, 10);
                            for (i = 0; i < tamLista ; i++)
                            {
                                pNewEmployee = (Employee*) ll_get(pArrayListEmployee, i);
                                if (pNewEmployee -> id == auxiliarIdDecimal)
                                {
                                    indice = 0;
                                    printf("El ID ya existe, intente con otro");
                                    break;
                                }
                                else
                                {
                                    auxiliarId = atoi(auxId);
                                    employee_setId(pEmployee, auxiliarId);
                                }
                            }
                            break;
                        case 2:
                            getValidStringEspaciosYLetras ("Ingrese nombre del empleado: ", "Error, ingrese un nombre valido: ", auxiliarNombre);
                            employee_setNombre(pEmployee, auxiliarNombre);
                            break;
                        case 3:
                            getValidStringNumeros ("Ingrese las horas trabajadas: ", "Error, ingrese horas validas: ", auxiliarHoras);
                            horasAux = atoi(auxiliarHoras);
                            employee_setHorasTrabajadas(pEmployee, horasAux);
                            break;
                        case 4:
                            getValidStringNumeros ("Ingrese el sueldo del empleado: ", "Error, ingrese sueldo valido: ", auxiliarSueldo);
                            sueldoAux = atoi(auxiliarSueldo);
                            employee_setSueldo(pEmployee, sueldoAux);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Ingrese una opcion del 1 al 5");
                    }

                }while (option != 5);
            }
        }
    }
    return indice;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    int indice = 1;
    int tamLista = ll_len(pArrayListEmployee);
    int id;

    if(pArrayListEmployee != NULL)
    {
        id = getValidInt("Ingrese ID del empleado que desea eliminar: ", "Error, ingrese un ID valido: ", 1, 10000);

        for (int i = 0; i < tamLista; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if (pEmployee->id == id)
            {
                ll_remove(pArrayListEmployee, i);
                indice = 0;
                printf("Empleado eliminado correctamente");
                employee_delete(pEmployee);
                break;
            }
        }
        if(pEmployee->id != id)
        {
            printf("No se encontro empleado con ese ID");
            indice = 1;
        }
    }
    return indice;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int indice = 0;
    int tamLista = ll_len(pArrayListEmployee);
    int id;
    char nombre [50];
    int horas;
    int sueldo;


    if(pArrayListEmployee != NULL)
    {
        if (tamLista > 0)
        {
            printf("  ID      Nombre      Horas Trabajadas   Sueldo \n");

            for (int i = 0; i < tamLista; i++)
            {
                pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(pEmployee, &id);
                employee_getNombre(pEmployee, nombre);
                employee_getHorasTrabajadas(pEmployee, &horas);
                employee_getSueldo(pEmployee, &sueldo);

                printf("%5d  %10s %10d  %10d\n",id, nombre, horas, sueldo);
            }
            indice = 1;
        }
        else
        {
            printf("No se han cargado los datos");
        }
    }
    return indice;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int indice = 0;

    if (pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, sortByName, 0);
    }
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
