#include "ShiftAndExato.h"
#include "BMH.h"
#include <sys/time.h>
#include <time.h>


int main(int argc, char *argv[]){
    
    // definindo o tempo de execução
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    
    
    int a, metodo = 0;
    sequencia arranjo1, arranjo2;
    FILE *file = fopen(argv[1], "r");
    if(argv[2] == NULL) printf("Metodo nao especificado\n");
    else metodo = atoi(argv[2]);
    if(file == NULL){
        printf("Erro, entrada do arquivo incorreta\n");
        return 0;
    }
    

    /*processo dos metodos:
    metodo 1: Forca Bruta
    metodo 2: ShiftAndExato
    metodo 3: BMH
    */

   
    if(metodo == 1){
        while(1){
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        a = forca_bruta(&arranjo1, &arranjo2);
        if(a == -7) break;
        gravador(a);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
    }
    if(metodo == 2){
        mascara *M;
        while(1){
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        M = cria_mascaras(&arranjo1, &arranjo2, M);
        a = shift_and_exato(&arranjo1, M, arranjo2.tamanho);
        if(a == -7) break;
        gravador(a);
        limpeza_mascaras(M, arranjo1.tamanho);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
    }
    if(metodo == 3){
        while(1){
            //printf("\naqui");
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        

        //inserir aqui a funcao BMH, ex: a = BMH(&arranjo1, &arranjo2);
        a = BMH(&arranjo1, &arranjo2);
        if(a == -7) break;
        gravador(a);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
    }
    //fim dos metodos
    
    fclose(file);
    
    // captura do tempo de execução
    gettimeofday(&end, NULL);
    
    printf("\ntempo de: %.4f\n", (end.tv_sec - start.tv_sec) + 1e-6*(end.tv_usec - start.tv_usec));
    return 0;
}
