#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#define NOMBRE_LIMITE 25
#define DNI_LIMITE 9
#define REINTENTOS 2

typedef struct
{
    char nombre[70];
    int edad;
    char dni[20];
    float altura;
}Persona;

int person_altaPersona(Persona *persona);
void person_imprimirPersona(Persona* persona);

#endif // PERSON_H_INCLUDED
