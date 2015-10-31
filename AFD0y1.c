#include <stdio.h>
#define p printf //hago esto por flojo

typedef struct cads{
char cadena_01[10];//cadena que recibe
char estado;      //Estado   en el que se encuentra la cadena con que se trabajará (E=error ,0,1,2,3,4)
}cadena;
void zoo(void);
void evalua (void);
cadena c;
main(){
  int op;
   do{
    p("\n1.- Introducir una cadena\n");
    p("2.- Validar cadena\n");
    p("4.- Salir");
    p("\n%c",c.estado);
   // p("\nOpcion: ");// pa cerciorarce en elestado en el que finaliza
    fflush( stdin );
      
    scanf("%d[1-4]", &op);
    switch(op){
      case 1: 
        p("\nIntroduce una cadena del alfabeto (0,1) (De 10 caracteres maximo, se descartaran los demas)\n");
        p("\nActual: [%s] \n",c.cadena_01);
        fflush( stdin );
        scanf("%10[^\n]s",c.cadena_01);
        p("\nNueva: [%s] \n",c.cadena_01);
        zoo();
        if(c.estado!='E')
          c.estado='0';
      break;
      case 2: 
      	 if(c.estado!='E'){
          c.estado='0';
        if (c.cadena_01[0]=='\0')
          p("\nCadena vacia");
        else{          
          evalua();
          if (c.estado=='4')
            p("\n >> Felicidades la cadena [%s] es valida",c.cadena_01);
          else
            p("\n >> Lo lamento la cadena [%s] no es valida",c.cadena_01);
        }
      }
      break;
          
      case 4: 
        p(" >> Bye");                    
      break;
      
      default: p("\n< * > Opcion incorrecta\n");
        }
        
    }while(op != 4);
    return 0;
}
void zoo(void){
  int cont=0;
 while(c.cadena_01[cont]!= '\0'){
      if(c.cadena_01[cont]!='0' && c.cadena_01[cont]!='1'){
        p("\nCadena no valida introduce 0 y 1");
        c.estado='E';
        break;
        }
        else
          c.estado='0';
      cont++;
 }
 p("\nOK");
}
   
void evalua(void){
	int cont=0;
	while(c.cadena_01[cont]!='\0'){
    if (c.estado=='E'){
      p("\nIntroduce una cadena que pueda evaluar (0y1)");
      break;
		}   
    else{
       switch(c.estado){
        case'0':
          if(c.cadena_01[cont]=='0')
            c.estado='1';
          if(c.cadena_01[cont]=='1')
            c.estado='2';
        break;

        case '1':
          if(c.cadena_01[cont]=='0')
            c.estado='1';
          if(c.cadena_01[cont]=='1')
            c.estado='3';
        break;

        case '2':
          if(c.cadena_01[cont]=='0')
            c.estado='1';
          if(c.cadena_01[cont]=='1')
            c.estado='2';

        break;

        case '3':
          if(c.cadena_01[cont]=='0')
            c.estado='1';
          if(c.cadena_01[cont]=='1')
            c.estado='4';
        break;
  
        case '4':
          if(c.cadena_01[cont]=='0')
            c.estado='1';
          if(c.cadena_01[cont]=='1')
            c.estado='2';
        break;

        default: 
        p("\n< * > Ups algo salio mal\n");
    }

	}
	cont++;
}
}