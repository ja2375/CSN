#include <stdio.h>
#include <stdlib.h>

void decBin();
void binDec();
void hexDec();
void decHex();

void main()
{
    int opc = -1;
    printf("\n\n\t***BIENVENIDO AL CONVERSOR DE SISTEMAS DE NUMERACION POR ja2375***\n");
    do{
        printf("\n\tMenu:\n\n");
        printf("\t---------------------------------------------------------\n");
        printf("\t|\t1.- Convertir de decimal a binario\t\t|\n");
        printf("\t|\t2.- Convertir de binario a decimal\t\t|\n");
        printf("\t|\t3.- Convertir de hexadecimal a decimal\t\t|\n");
        printf("\t|\t4.- Convertir de decimal a hexadecimal\t\t|\n");
        printf("\t|\t5.- Salir\t\t\t\t\t|\n");
        printf("\t---------------------------------------------------------");
        printf("\n\nElige una opcion: ");
        scanf("%d", &opc);

        switch(opc){
        case 1: decBin(); break;
        case 2: binDec(); break;
        case 3: hexDec(); break;
        case 4: decHex(); break;
        case 5: printf("Salir"); break;
        default: printf("Opcion no encontrada\n");
        }
    }while(opc != 5);
}

void decBin(){
    long int decimalNumber, remainder, quotient;
    int binaryNumber[100], i=1, j;
    printf("Escribe el numero en decimal a convertir: ");
    scanf("%ld",&decimalNumber);
    quotient = decimalNumber;
    while(quotient!=0){
         binaryNumber[i++]= quotient % 2;
         quotient = quotient / 2;
    }
    printf("Equivalente en binario de %d: ", decimalNumber);
    for(j = i -1 ;j> 0;j--)
         printf("%d",binaryNumber[j]);
    printf("\n");
}

void binDec(){
    long long n;
    printf("Atencion! Si escribes aqui un numero que no este en binario, el programa realizara las cuentas igualmente y te devolvera una incoherencia. Aun no tiene soporte el programa para detectar errores como ese. Quedas avisad@.\n");
    printf("Escribe el numero binario a convertir: ");
    scanf("%lld", &n);
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    printf("Equivalente en decimal: %d", decimalNumber);
}

void hexDec(){
    long long decimalNumber=0;
    char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
      '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char hexadecimal[30];
    int i, j, power=0, digit;

    printf("Escribe el digito hexadecimal a convertir: ");
    scanf("%s", hexadecimal);

    /* Converting hexadecimal number to decimal number */
    for(i=strlen(hexadecimal)-1; i >= 0; i--) {
        /*search currect character in hexDigits array */
        for(j=0; j<16; j++){
            if(hexadecimal[i] == hexDigits[j]){
                decimalNumber += j*pow(16, power);
            }
        }
        power++;
    }

    printf("Equivalente de %s en decimal: %ld", hexadecimal, decimalNumber);
}

void decHex(){
    long int decimalNumber,remainder,quotient;
    int i=1,j,temp;
    char hexadecimalNumber[100];

    printf("Escribe el numero decimal a convertir: ");
    scanf("%ld", &decimalNumber);

    quotient = decimalNumber;

    while(quotient!=0){
         temp = quotient % 16;

      //To convert integer into character
      if( temp < 10)
           temp = temp + 48;
      else
         temp = temp + 55;

      hexadecimalNumber[i++]= temp;
      quotient = quotient / 16;
  }

    printf("Equivalente de %d en hexadecimal: ", decimalNumber);
    for(j = i -1 ;j> 0;j--)
      printf("%c", hexadecimalNumber[j]);

}
