#include "BMH.h"


typedef struct mascara{
    int masc;
    int *potencias;
} mascara;

mascara* cria_mascaras(sequencia* , sequencia* , mascara*);
int shift_and_exato(sequencia* , mascara* , int);
void limpeza_mascaras(mascara* , int);
