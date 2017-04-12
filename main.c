/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Juan Retamales
 *
 * Created on 25 de marzo de 2017, 16:29
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Functiones
 */
int validador1(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10, int c11, int c12);
int validador2(int c1, int c12);
int validador3(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10, int c11, int c12);


int main(int argc, char** argv) {
    
    int entrada[12];
    int largo = 0;
    
    printf("Iniciando...ok \n");
    int a,b,c,d,e,f,g,h,i,j,k,l;
    
    int x;
    int y=0;
    
    printf("Entrada.in...");
    
    /*printf("Ingrese entrada.in: scanf("%i",&nota1);\n");*/
    FILE *archivo;
    int caracter;

    archivo = fopen("entrada.in","r");

    if (archivo == NULL)
    {
        printf("\nError de apertura del archivo. \n\n");
    }
    else
    {
        while((caracter = fgetc(archivo)) != EOF)
        {
            
            /* Lee el archivo entrada.in pero en formato UTF8 sin BOM */
            if(isdigit(caracter)!=0)
            {
                if(largo>0)
                {
                    y=0;
                    for ( x = 0; x < largo; x++ )
                    {
                        if(entrada[x]==(((int)caracter)-48))
                        {
                            y=1;
                        }
                    }
                }
                if(y==0)
                {
                    entrada[largo]=((int)caracter)-48;
                    largo++;
                }
            }
        }
    }
    fclose(archivo);
    printf("ok \n");
    printf("Formando las  combinaciones y guardandolo en salida.out...");
    /* -Creo la combinacion*/
    FILE *fp;
 	
    fp = fopen ( "salida.out", "w" );
    fclose ( fp );
    char str[10];
    
    for ( a = 0; a < largo; a++ )
    {
        for ( b = 0; b < largo; b++ )
        {
            for ( c = 0; c < largo; c++ )
            {
                for ( d = 0; d < largo; d++ )
                {
                    for ( e = 0; e < largo; e++ )
                    {
                        for ( f = 0; f < largo; f++ )
                        {
                            for ( g = 0; g < largo; g++ )
                            {
                                for ( h = 0; h < largo; h++ )
                                {
                                    for ( i = 0; i < largo; i++ )
                                    {
                                        for ( j = 0; j < largo; j++ )
                                        {
                                            for ( k = 0; k < largo; k++ )
                                            {
                                                for ( l = 0; l < largo; l++ )
                                                {
                                                    if(validador1(entrada[a], entrada[b], entrada[c], entrada[d], entrada[e], entrada[f], entrada[g], entrada[h], entrada[i], entrada[j], entrada[k], entrada[l])==0 && validador2(entrada[a], entrada[l])==0 && validador3(entrada[a], entrada[b], entrada[c], entrada[d], entrada[e], entrada[f], entrada[g], entrada[h], entrada[i], entrada[j], entrada[k], entrada[l])==0)
                                                    {
                                                        fp = fopen ( "salida.out", "a" );
                                                        sprintf(str, "%d", entrada[a]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[b]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[c]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[d]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[e]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[f]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[g]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[h]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[i]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[j]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[k]);
                                                        fprintf(fp, "%s", str);
                                                        sprintf(str, "%d", entrada[l]);
                                                        fprintf(fp, "%s", str);
                                                        fprintf(fp, "\n");
                                                        fclose ( fp );
                                                    }
                                                }
                                                
                                            }
                                        }
                                    }
                                    
                                }
                                
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("ok \n");
    return (EXIT_SUCCESS); 
}
/*
 * Validador 1 - verifica que no existan 3 numeros iguales consecutivos
 */
int validador1(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10, int c11, int c12)
{
    int test=0;
    if(c1==c2 && c2==c3)
    {
        return 1;
    }
    if(c2==c3 && c3==c4)
    {
        return 1;
    }
    if(c3==c4 && c4==c5)
    {
        return 1;
    }
    if(c4==c5 && c5==c6)
    {
        return 1;
    }
    if(c6==c7 && c7==c8)
    {
        return 1;
    }
    if(c7==c8 && c8==c9)
    {
        return 1;
    }
    if(c8==c9 && c9==c11)
    {
        return 1;
    }
    if(c9==c10 && c10==c11)
    {
        return 1;
    }
    if(c10==c11 && c11==c12)
    {
        return 1;
    }
    return 0;
}
/*
 * Validador 2 - verifica que si el primer numero es impar, no termine en impar
 */
int validador2(int c1, int c12)
{
    if(c1%2==1 && c12%2==1)
    {
        return 1;
    }
    return 0;
}
/*
 * Validador 3 - verifica que no tenga mas de 3 numeros consecutivos
 */
int validador3(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10, int c11, int c12)
{
    int actual = c1;
    if((actual+4)>=10)
    {
        if((actual+1)==c2 && (actual+2)==c3 && (actual+3)==c4 && (actual+4)==c5)
        {
            return 1;
        }
    }
    
     actual = c2;
     if((actual+4)>=10)
    {
        if((actual+1)==c3 && (actual+2)==c4 && (actual+3)==c5  && (actual+4)==c6)
        {
            return 1;
        }
     }
     actual = c3;
     if((actual+4)>=10)
    {
        if((actual+1)==c4 && (actual+2)==c5 && (actual+3)==c6  && (actual+4)==c7)
        {
            return 1;
        }
     }
     actual = c4;
     if((actual+4)>=10)
    {
        if((actual+1)==c5 && (actual+2)==c6 && (actual+3)==c7  && (actual+4)==c8)
        {
            return 1;
        }
     }
     actual = c5;
     if((actual+4)>=10)
    {
        if((actual+1)==c6 && (actual+2)==c7 && (actual+3)==c8  && (actual+4)==c9)
        {
            return 1;
        }
     }
     actual = c6;
     if((actual+4)>=10)
    {
        if((actual+1)==c7 && (actual+2)==c8 && (actual+3)==c9  && (actual+4)==c10)
        {
            return 1;
        }
     }
     actual = c7;
     if((actual+4)>=10)
    {
        if((actual+1)==c8 && (actual+2)==c9 && (actual+3)==c10  && (actual+4)==c11)
        {
            return 1;
        }
     }
    actual = c8;
    if((actual+4)>=10)
    {
        if((actual+1)==c9 && (actual+2)==c10 && (actual+3)==c11  && (actual+4)==c12)
        {
            return 1;
        }
    }
    return 0;
}
