#include <stdlib.h>
#include <stdio.h>

void main(){

    FILE *fp = fopen("entrada1.txt", "w");


    // começo de um teste
    fprintf(fp, "205 5\n");    
    for (int i = 0; i < 20; i++){
        fprintf(fp, "A Db C D E F G A A# F# ");
    }
    fprintf(fp, "A B C D D");
    fprintf(fp, "\nA B C D D");
    // término do teste




    //fim dos testes
    fprintf(fp, "\n0 0");
    fclose(fp);

}
