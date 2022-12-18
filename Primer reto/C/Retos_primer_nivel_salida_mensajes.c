#include <stdio.h>
#include <string.h>
#include <math.h>

char nombre_usuario[60], marcador[2], salto;
short i, retos, categorias, rebanadas, consumidas, edad, edad_pasada, edad_futura;
short cantidad_personas, opcion_propina;
float total_cuenta, propina, total_pagar, propina_personalizada, impuestos;
float cantidad_dias;
int horas, minutos, segundos;
float millas, kilometros;
float menor_100, mayor_1000, n_veces;

//Declaracion

int suma_enteros();
float suma_float();
float multiplicacion(float a);
int resta(int a, int b);
void menu();
void biblioteca_de_retos();

int main() 
{   
    do
    {
        menu();
        biblioteca_de_retos();
    }   
    while (strcmp(marcador, "#")==0);
    return 0;
}

void menu()
{
    printf("Bienvenido a la biblioteca de retos de Platzi!\n");
    printf("Seleccione el reto que desea mostrar:\n");
    printf("\n");
    printf("Reto 1: Hola [nombre]\n");
    printf("Reto 2: Hola... nombre y apellido\n");
    printf("Reto 3: Mensaje multilinea\n");
    printf("Reto 4: Suma de enteros\n");
    printf("Reto 5: Suma y multiplicacion\n");
    printf("Reto 6: Resta de pizzas\n");
    printf("Reto 7: Edad futura y pasada\n");
    printf("Reto 8: Divide la cuenta\n");
    printf("Reto 9: Calculando dias\n");
    printf("Reto 10: Conversor de millas\n");
    printf("Reto 11: Cuantas veces un numero en otro\n");
    printf("\n");
    printf("Reto ");
    scanf("%3d", &retos);
    salto = getchar();
    printf("\n");
    fflush(stdin);
    /*Este getchar() es para almacenar el
    salto de linea que deja scanf() en el
    buffer.
    
    Cuando es almacenado la funcion 
    gets() no toma este salto de linea
    como input.*/
}

void biblioteca_de_retos()
{
    switch (retos)
    {
    case 1:
        //Reto 1 Hola [nombre]
        printf("Digite su nombre para recibir un saludo personalizado\n");
        scanf("%59s", nombre_usuario);
        printf("Hola %s!\n", nombre_usuario);
        fflush(stdin);
        /*La funcion fflush() sirve para vaciar o
        limpiar el buffer de salida de transmision.
        Tambien limpia el buffer de entrada despues
        de usar un scanf()*/
        break;
    
    case 2:
        //Reto 2 Hola.... nombre y apellido
        printf("Digite su nombre y apellido para recibir un saludo personalizado\n");
        gets(nombre_usuario);
        printf("Hola %s!\n", nombre_usuario);
        break;

    case 3:
        //Reto 3: Mensaje multilinea
        printf("Platzi cuenta con cursos de:\n");
        categorias=6;
        for ( i = 1; i <= categorias; i++)
        {
            printf("\x1b[38;5;154m");
            /* Para mostrar en el terminal
            el texto con un color ASCII especifico
            podemos usar el codigo ASCII de 256
            colores.
            Donde "ESC[38;5;{ID}m"
            ESC = \x1b (hex) o \033 (octal)
            ID = va desde 0 a 255 (0 = negro, y 255 = blanco) 
            */
            printf("[categoria%d]\n", i);
        }
        
        printf("\x1b[0m\n");
        break;
    
    case 4:
        //Reto 4: Suma de enteros
        printf("Por favor, ingrese datos estrictamente enteros!\n");
        printf("\nLa suma entre los dos numeros es igual a %d\n", suma_enteros());
        fflush(stdin);
        break;

    case 5:
        //Reto 5: Suma y multiplicacion
        printf("\nIngrese dos numeros para realizar una suma entre numeros flotantes o enteros\n");
        printf("\nEl resultado de la multiplicacion es igual a %.2f\n", multiplicacion(suma_float()));
        break;

    case 6:
        //Reto 6: Resta de pizzas
        printf("Bienvenido a la fiesta de Platzi\n");
        printf("\nEnhorabuena! Trajiste pizza. Cuantas rebanadas de pizza trajiste a la fiesta?\n");
        scanf("%d", &rebanadas);
        printf("Ya ha transcurrido 30 minutos. Ingrese la cantidad de pizzas consumidas:\n");
        scanf("%d", &consumidas);
        printf("\nLa cantidad de rebanadas restantes es %d\n", resta(rebanadas, consumidas));
        break;
    
    case 7:
        //Reto 7: Edad futura y pasada
        printf("Para obtener su edad futura y su edad pasada necesitamos los siguientes datos:\n");
        printf("\nPorfavor, indique su nombre\n");
        gets(nombre_usuario);
        printf("Porfavor, indique su edad\n");
        scanf("%d", &edad);
        edad_pasada=edad-1;
        edad_futura=edad+1;
        printf("\n%s, el ano pasado tenias %d anos, y el proximo año cumpliras %d años\n", nombre_usuario, edad_pasada, edad_futura);
        break;
    
    case 8:
        //Reto 8: Divide la cuenta
        printf("Bienvenido a la calculadora de cuentas de Platzi\n");
        printf("\nPara comenzar, indique el valor total a pagar:\n");
        scanf("%f", &total_cuenta);
        printf("Segundo, indique la cantidad de personas que pagaran la cuenta:\n");
        scanf("%d", &cantidad_personas);

        impuestos=total_cuenta*0.19;
        total_pagar=(total_cuenta+impuestos)/cantidad_personas;

        printf("El valor a pagar por cada uno de los integrantes es de $%.2f COP, incluyendo impuestos\n", total_pagar);

        printf("\nPor ultimo, indique cuanta propina desea incluir\n");
        printf("\nDigite 0 para 0%%\n");
        printf("Digite 1 para 5%%\n");
        printf("Digite 2 para 10%%\n");
        printf("Digite 3 para 15%%\n");
        printf("Digite 4 para 20%%\n");
        printf("Digite 5 para un %% de propina personalizada\n");
        scanf("%1d", &opcion_propina);
        switch (opcion_propina)
        {
        case 0:
            propina=total_cuenta*0;
            break;

        case 1:
            propina=total_cuenta*0.05;
            break;
        
        case 2:
            propina=total_cuenta*0.1;
            break;

        case 3:
            propina=total_cuenta*0.15;
            break;
        
        case 4:
            propina=total_cuenta*0.2;
            break;

        case 5:
            printf("\nCuanto porcentaje desea dar de propina\n");
            scanf("%f", &propina_personalizada);
            propina=total_pagar*(propina_personalizada/100);
            break;
        
        default:
            printf("\nLo sentimos, no pudimos detectar la opcion digitada. Repita nuevamente\n");
            break;
        }

        printf("\nEl valor de la propina es de %.2f COP\n", propina);
        total_pagar=total_pagar+propina;
        printf("El valor a pagar es de $%.2f COP\n", total_pagar);
        break;
    
    case 9:
        //Reto 9: Calculando dias
        printf("Bienvenido a la calculadora de dias de Platzi\n");
        printf("\nPrimero, indique la cantidad de dias que quiere convertir a horas minutos y segundos:\n");
        scanf("%f", &cantidad_dias);
        horas=cantidad_dias*24;
        minutos=horas*60;
        segundos=minutos*60;
        
        printf("\nA partir de %.1f dias, el tiempo obtenido es de %d horas, %d minutos, y %d segundos\n", cantidad_dias, horas, minutos, segundos);
        break;
    case 10:
        //Reto 10: Conversor de millas
        printf("Bienvenido al conversor de millas a kilometros de Platzi\n");
        printf("\nIngrese el valor en millas a convertir:\n");
        scanf("%f", &millas);
        kilometros=millas*1.609344;
        printf("\nEl valor %.2f en millas es igual a %f kilometros\n", millas, kilometros);
        break;
        
    case 11:
        //Reto 11: Cuantas veces un numero en otro
        printf("Bienvenido, para calcular cuantas veces esta un numero en otro, ingrese los siguientes datos...\n");
        printf("\nPrimero, ingrese un numero menor a 100:\n");
        repeat100:
        scanf("%f", &menor_100);
        if(menor_100<100)
        {
            printf("Por ultimo, ingrese un numero mayor a 1000:\n");
            repeat1000:
            scanf("%f", &mayor_1000);
            if(mayor_1000>1000)
            {
                n_veces=mayor_1000/menor_100;
                printf("\nLa cantidad de veces que esta %.2f en %.2f es igual a %f\n", menor_100, mayor_1000, n_veces);
            }
            else
            {
                printf("El valor no es mayor a 1000. Por favor, ingrese un numero mayor a 1000.\n");
                goto repeat1000;
            }    
        }
        else
        { 
            printf("El valor no es menor a 100. Por favor, ingrese un numero menor a 100.\n");
            goto repeat100;
        }
        break;

    default:
        printf("Error, no se pudo ejecutar el programa\n");
        break;
    }

    printf("\nFinalizo el programa, si desea ejecutar otro programa presione '#':\n");
    scanf("%1s", marcador);
    salto = getchar();
}

//Definicion

int suma_enteros()
{
    int a, b, resultado;
    printf("Ingrese el primer numero:\n");
    scanf("%d", &a);
    printf("Ingrese el segundo numero:\n");
    scanf("%d", &b);
    resultado=a+b;
    return resultado;
}

float suma_float()
{
    float a, b, resultado;
    printf("Ingrese el primer numero:\n");
    scanf("%f", &a);
    printf("Ingrese el segundo numero:\n");
    scanf("%f", &b);
    resultado=a+b;
    return resultado;
}

float multiplicacion(float a)
{
    float c, resultado;
    printf("Ingrese un tercer numero para multiplicarlo con el resultado de la suma:\n");
    scanf("%f", &c);
    resultado=a*c;
    return resultado;
}

int resta(int a, int b)
{
    int resta;
    resta = a-b;
    return resta;
}