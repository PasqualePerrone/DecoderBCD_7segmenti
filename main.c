//Decoder BCD a 7 segmenti creato tramite terminale
//Codice concepito in equivalenza ad uno schema con porte logiche
//Parte di attivazione segmenti risolta manualmente tramite Mappe di Karnaugh
//Creato da Pasquale Perrone Settembre 2021

#include <stdio.h>

int main() {
    char apiece,epiece,dpiece,bpiece;
    int i0,i1,i2,i3,a,b,c,d,e,f,g,n;

    //Input
    while(scanf("%1d%1d%1d%1d ",&i0,&i1,&i2,&i3) != EOF){
        //Azzeraggio
        apiece = ' ';
        epiece = ' ';
        bpiece = ' ';
        dpiece = ' ';
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        f = 0;
        g = 0;
        n = 0;
        
        //Conversione decimale
        if(i0){
            n+=8;
        }
        if(i1){
            n+=4;
        }
        if(i2){
            n+=2;
        }
        if(i3){
            n++;
        }

        //Attivazione segmenti
        
        //a
        if(i0 || (!i0 && !i1) || (i2 == i3)) a = 1;

        //b
        if(!i2 || (i2 && i3) || (!i0 && i1)) b = 1;

        //c
        if(i0 || (i1 && !i2 && i3) || (!i0 && !i1 && !i3) || (i1 && i2 && !i3) || (!i1 && i2 && i3)) c = 1;

        //d
        if((!i0 && !i1 && !i3) || (i1 && i2 && !i3) || (i0 && !i2 && !i3)) d = 1;

        //e
        if(i0 || (!i2 && !i3) || (!i0 && i1 && !i2 && i3) || (!i0 && i1 && i2 && !i3)) e = 1;
        
        //f 
        if(i0 || i2 || (i1 && i3) || (!i0 && !i1 && !i2 && !i3)) f = 1;

        //g
        if(i0 || (i2 && !i3) || (i1 && !i2) || (!i0 && !i1 && i2 && i3)) g = 1;

        //Printing
        printf("Hai inserito il numero binario: %d%d%d%d\n\nConvertito in decimale esso è: %d\n\n",i0,i1,i2,i3,n);
        if(f){
            printf(" _____ \n");
        }
        printf("\n");
        if(a) apiece='|';
        if(e) epiece='|';
        for(int i=0;i<3;i++){
            printf("%c     %c\n",epiece,apiece);
        }
        if(g){
            printf(" _____ \n");
        }
        printf("\n");
        if(b) bpiece='|';
        if(d) dpiece='|';
        for(int i=0;i<3;i++){
            printf("%c     %c\n",dpiece,bpiece);
        }
        if(c){
            printf(" _____ \n");
        }
        printf("\n\nProssima iterazione o fine programma... \n\n");
    }
    return 0;
}