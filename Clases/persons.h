#ifndef persons_H_INCLUDED
#define persons_H_INCLUDED
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

int persons_altaPersona(Persona *persona);
void persons_imprimirPersona(Persona* persona);

#endif // persons_H_INCLUDED
