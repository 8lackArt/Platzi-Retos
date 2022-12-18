#include <stdio.h>
#include <string.h>

//variables
char marcador[2], salto, animalfav[20], clima[10];
short reto, opcion, edad;
float n1, n2, limite, rango, limite_inf, limite_sup;

//Declaracion
void menu();
void biblioteca_de_retos();

int main()
{
	do {
	    menu();
	    biblioteca_de_retos();
	} while (strcmp(marcador, "#")==0); 
}

//Definicion

void menu()
{
    printf("\nBienvenido a la segunda biblioteca de retos de Platzi\n");
    printf("\nReto 1: Numero mayor y menor\n");
    printf("Reto 2: En el rango por favor\n");
    printf("Reto 3: Rangos cambiantes\n");
    printf("Reto 4: 'I like Turtles'\n");
    printf("Reto 5: ¿Cómo está el clima?\n");
    printf("Reto 6: Edad permitida\n");
    printf("Reto 7: Mensajes opcionales\n");
    printf("\nEscoja el reto que desea ejecutar:\n");
    printf("Reto ");
    scanf("%d", &reto);
    fflush(stdin);
}

void biblioteca_de_retos()
{
    switch (reto) {
        case 1:
            //Reto 1: Numero mayor y menor
            printf("\nEscoja la opcion segun el numero que desea encontrar:\n");
            printf("\nDigite 0 para encontrar el numero mayor\n");
            printf("Digite 1 para encontrar el numero menor\n");
            printf("\nOpcion ");
            scanf("%2d", &opcion);
            printf("\nDigite un primer numero a comparar:\n");
            scanf("%f", &n1);
            printf("Digite un segundo numero a comparar:\n");
            scanf("%f", &n2);
            switch (opcion) {
                case 0:
                    if (n1>n2)
                        printf("\n%.2f es mayor que %.2f\n", n1, n2);
                    else
                        printf("\n%.2f es mayor que %.2f\n", n2, n1);
                    break;
                case 1:
                    if (n1<n2)
                            printf("\n%.2f es menor que %.2f\n", n1, n2);
                    else
                        printf("\n%.2f es menor que %.2f\n", n2, n1);
                    break;
               default:
                   printf("\nError, la opcion ingresada es incorrecta\n");
                   break;
            }
            break;
         case 2:
            //Reto 2: En el rango por favor
            printf("\nPara verificar si el numero se encuentra en rango, proporcione el numero limite y el numero a comparar\n");
            printf("Establezca el numero limite:\n");
            scanf("%f", &limite);
            printf("Ahora, proporcione el numero a comparar:\n");
            scanf("%f", &rango);
            if (rango<=limite)
                printf("El número %.2f se encuentra en el rango, gracias\n", rango);
            else
                printf("El número %.2f excede el límite permitido\n", rango);
            break;
        case 3:
            //Reto 3: Rangos cambiantes
            printf("\nPara verificar si el numero se encuentra en rango, proporcione el limite superior, el limite inferior, y el numero a comparar\n");
            printf("Establezca el limite superior:\n");
            scanf("%f", &limite_sup);
            printf("Establezca el limite inferior:\n");
            scanf("%f", &limite_inf);
            printf("Por ultimo, proporcione el numero a comparar:\n");
            scanf("%f", &rango);
                if (rango>=limite_inf && rango<=limite_sup)
                    printf("El número %.2f se encuentra en el rango, gracias\n", rango);
                else if (rango>limite_sup)
                    printf("El número %.2f se encuentra por encima del limite superior\n", rango);
                else
                    printf("El número %.2f se encuentra por debajo del limite superior\n", rango);
            break;
        case 4:
            //Reto 4: "I like Turtles"
            printf("\nPor favor, ingrese su animal favorito:\n");
            gets(animalfav);
            strlwr(animalfav);
            if (strcmp(animalfav, "tortuga")==0)
                printf("Tambien me gustan las tortugas\n");
            else
                printf("Ese animal es genial, pero prefiero las tortugas\n");
            break;
        case 5:
            //Reto 5: ¿Cómo está el clima?
            printf("\nHola! esta lloviendo en Bogota?\n");
            gets(clima);
            strlwr(clima);
            if (strcmp(clima,"si")==0)
            {
                printf("Tambien, esta haciendo mucho viento?\n");
                gets(clima);
                strlwr(clima);
                if (strcmp(clima,"si")==0)
                    printf("Que mal clima! Es mejor que no salga con sombrilla\n");
                else if (strcmp(clima,"no")==0)
                    printf("Por favor salga con sombrilla, nadie quiere enfermarse\n");           
            }
            else if (strcmp(clima,"no")==0)
                printf("Que bien! Entonces tenga un bonito dia");
            break;
        case 6:
            //Reto 6: Edad permitida
            printf("\nPor favor, ingrese su edad:\n");
            scanf("%d", &edad);
            if (edad>=30)
                printf("Nunca es tarde para aprender ¿Qué curso tomaremos?\n");
            else if (edad>=18 && edad<=29)
                printf("Es un momento excelente para impulsar tu carrera.\n");
            else
                printf("¿Sabes hacia dónde dirigir tu futuro? Seguro puedo ayudarte.\n");
            break;
        case 7:
            //Reto 7: Mensajes opcionales
            printf("\nA continuacion podra mostrar un mensaje en pantalla.\n");
            printf("\nProporcione un numero del 1-6: ");
            scanf("%d", &opcion);
                switch (opcion)
                {
                case 1:
                    printf("\nHoy aprenderemos sobre programación\n");
                    break;
                case 2:
                    printf("\n¿Qué tal tomar un curso de marketing digital?\n");
                    break;
                case 3:
                    printf("\nHoy es un gran día para comenzar a aprender de diseño\n");
                    break;
                case 4:
                    printf("\n¿Y si aprendemos algo de negocios online?\n");
                    break;
                case 5:
                    printf("\nVeamos un par de clases sobre producción audiovisual\n");
                    break;
                case 6:
                    printf("\nTal vez sea bueno desarrollar una habilidad blanda en Platzi\n");
                    break;
                default:
                    printf("\nError, por favor ingrese un numero del 1-6\n");    
                    break;
                }
            break;
        default:
                printf("\nError, no se pudo ejecutar el programa\n");
            break;
    }
    printf("\nFinalizo el programa, si desea ejecutar otro programa presione '#':\n");
    scanf("%1s", marcador);
    salto = getchar();
}