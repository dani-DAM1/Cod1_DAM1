/***************************************************************
 * Has de crear una agenda de 5 amics dels que guardaràs       *
 * la següent informació:                                      *
 *  Nom                                                        *
 *  Telefon                                                    *
 *  Mail                                                       *
 *  Edat                                                       *
 *                                                             *
 * Crea un switch que demani les opcions de la 1 a la 4,       *
 * que faran una crida a les següents funcions:                *
 *                                                             *
 *  1. Afegir                                                  *
 *  2. Llistar                                                 *
 *  3. Modificar                                               *
 *  4. Eliminar                                                *
 *  0. Sortir                                                  *
 *                                                             *
 * ----------------------------------------------------------- *
 * per Daniel Gonzalez                                         *
 ***************************************************************/

#include <stdio.h>
#include <string.h>
int num=1;
struct RegistreAmics{
int edat;
char nom[45];
int telefon[9];
char mail[20];
};
struct RegistreAmics Amics[5];/*Declara la matriu Amics de tipus RegistreAmics */
void mostrar();
void introduir(int pos);
void modificar();
void eliminar();
void netejaBuffer();

int main(void){

    int opcio;
    do{
        do{
            system ("clear");
            printf("\tAGENDA D'AMICS\n");
            printf("\t--------------\n\n");
            printf("\tQue vols fer? \n");
            printf("\t   1. Afegir un amic\n");
            printf("\t   2. Llistar els amics\n");
            printf("\t   3. Modificar registres\n");
            printf("\t   4. Eliminar registres\n");
            printf("\t   0. Sortir\n\n");
            printf("\tEntra una opcio (0-4)\n\t");
            scanf("%d",&opcio);
        }while(opcio<0&&opcio>4);
        switch (opcio){
            case 0:
                return 0;
            break;
            case 1:
                introduir(num);
                num++;
            break;
            case 2:
                mostrar();
            break;
            case 3:
                modificar();
            break;
            case 4:
                eliminar();
            break;
        }
   }while(opcio!=0);
   return 0;
}
void introduir(int pos){
    if (num>5){
        printf("\n\tTots els registres estàn complets, ");
        printf("\n\tesborri un si vol introduir-ne un altre ");
    }
    else{
        getchar();
        printf("\n\tNom: ");
        scanf("%s",&Amics[pos].nom);
        getchar();
        //do{
            printf("\tTelèfon: (9 números)\n\t");
            scanf("%d",&Amics[pos].telefon);
        //}while(strlen(Amics[pos].telefon)!=9);
        printf("\teMail: ");
        scanf("%s",Amics[pos].mail);
        printf("\tEdat: ");
        scanf("%d",&Amics[pos].edat);
        netejaBuffer();
    }
}

void mostrar(){
    int i;
    printf("\n\tHi ha %d Registre(s):\n",num-1);
    for(i=1;i<num;i++){
        printf("\n\tRegistre nº %d\n",i);
        printf("\t   Nom:   \t%s\n", Amics[i].nom);
        printf("\t   Telèfon: \t%d\n", Amics[i].telefon);
        printf("\t   eMail: \t%s\n", Amics[i].mail);
        printf("\t   Edat: \t%d\n\n\t", Amics[i].edat);
    }
    getchar();
    getchar();
}
void modificar(){
    char telefon[9];
    int i,fitxa;
    printf("\n\tIntrodueix el teléfon del amic a modificar:\n\t");
    getchar();//netejaBuffer();
    scanf("%c",&telefon);
    for(i=1;i<num;i++){
        if(strcmp(Amics[i].telefon,telefon)==0){
        fitxa=i;
        }
    }
    if(strcmp(Amics[fitxa].telefon,telefon)==0){
        printf("\n\tTorna a introduir les seves dades:\n\t");
        netejaBuffer();
        introduir(fitxa);
    }
    else{
        printf("\n\tNo hi ha cap registre amb aquest telefon\n\t");
        getchar();
    }
}
void eliminar(){
    char telefon[9];
    int i,fitxa;
    printf("\n\tIntrodueix el teléfon del amic a eliminar:\n\t");
    netejaBuffer();
    scanf("%c",&telefon);
    for(i=1;i<num;i++){
        if(strcmp(Amics[i].telefon,telefon)==0){
        fitxa=i;
        }
    }
    if(strcmp(Amics[fitxa].telefon,telefon)==0){
        strcpy(Amics[fitxa].nom,Amics[num-1].nom);
        strcpy(Amics[fitxa].telefon,Amics[num-1].telefon);
        strcpy(Amics[fitxa].mail,Amics[num-1].mail);
        Amics[fitxa].edat=Amics[num-1].edat;
        Amics[num].edat='\0';
        num=num-1;
        printf("\n\tRegistre eliminat\n\t");
        getchar();
    }
    else{
        printf("\n\tNo hi ha cap registre amb aquest telefon\n\t");
        getchar();
    }
}
void netejaBuffer(){
    char c;
    do{
        c=getchar();
    }while(c!='\n');
}
