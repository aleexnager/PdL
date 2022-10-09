#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "header.h"

// FUNCION QUE IMPLEMENTA EL FUNCIONAMIENTO DE ANALIZADOR LÉXICO, SU FUNCIÓN ES LEER DESDE UN FP, HABIENDO
// LEIDO YA UN CARÁCTER Y GENERAR UN TOKEN O GENERAR UN ERROR

int main(int argc, char const *argv[])
{
    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen("token.txt", "w");

    if (fp1 == NULL) exit(1);
    if (fp2 == NULL) exit(1);

    int estado = 0;
    int accion;
    char leido = fgetc(fp1);
    char* lexema;
    int valor;
    while (estado < 10)
    {
        accion = mt_afd_accion(estado, leido);
        fprintf(stderr, "La siguiente acción es %d\n", accion);
        estado = mt_afd_estado(estado, leido);
        fprintf(stderr, "El siguiente estado es %d\n", estado);

        if (estado == -1) gen_error(accion);

        switch (accion) {
            case A:
            {
                leido = fgetc(fp1);
                break;
            }
            case B:
            {
                fprintf(stderr, "Se ha llegado a B\n");
                leido = fgetc(fp1);
                break;
            }
            case C:
            {
                fprintf(stderr, "Se ha llegado a C");
                lexema = strncat(lexema, &leido, 1);
                leido = fgetc(fp1);
                break;
            }
            case D:
            {
                if (strlen(lexema) < 65) {
                    token_lexema_t* token = malloc(sizeof(token_lexema_t *));
                    token->id = CADENA;
                    token->lexema = lexema;
                    fprintf(fp2, "<%d, %s>\n", token->id, token->lexema);
                } else {
                    gen_error(59);
                }
                break;
            }
            case E:
            {
                valor = leido - '0';
                leido = fgetc(fp1);
                break;
            }
            case F:
            {
                valor = (valor * 10) + (leido - '0');
                leido = fgetc(fp1);
                break;
            }
            case G:
            {
                if (valor > -32768 && valor < 32768) {
                    token_valor_t* token = malloc(sizeof(token_valor_t *));
                    token->id = CTE_ENTERA;
                    token->valor = valor;
                    fprintf(fp2, "<%d, %d>\n", token->id, token->valor);
                } else {
                    gen_error(60);
                }
                break;
            }
            case H:
            {
                lexema = strncat(lexema, &leido, 1);
                leido = fgetc(fp1);
                break;
            }
            case I:
            {
                lexema = strncat(lexema, &leido, 1);
                leido = fgetc(fp1);
                break;
            }
            case J:
            {
                /* if (lexema.palRes()) {
                    gen_token(lexema, -);
                } else if ( (pos = lexema.enTS()) ) {
                    gen_token(ID, pos);
                } else {
                    pos = lexema.insertar();
                    gen_token(ID, pos);
                } */
            }
            case K:
            {
                token_lexema_t* token8 = malloc(sizeof(token_lexema_t *));
                token8->id = OP_MODULO;
                token8->lexema = "-";
                fprintf(fp2, "<%d, %s>\n", token8->id, token8->lexema);
                break;
            }
            case L:
            {
                token_lexema_t* token9 = malloc(sizeof(token_lexema_t *));
                token9->id = OP_MOD_ASIG;
                token9->lexema = "-";
                fprintf(fp2, "<%d, %s>\n", token9->id, token9->lexema);
                break;
            }
            case M:
            {
                token_lexema_t* token10 = malloc(sizeof(token_lexema_t *));
                token10->id = OP_NEG;
                token10->lexema = "-";
                fprintf(fp2, "<%d, %s>\n", token10->id, token10->lexema);
                break;
            }
            case N:
            {
                token_lexema_t* token11 = malloc(sizeof(token_lexema_t *));
                token11->id = OP_NEQ;
                token11->lexema = "-";
                fprintf(fp2, "<%d, %s>\n", token11->id, token11->lexema);
                break;
            }
            case O:
            {
                leido = fgetc(fp1);
                token_lexema_t* token1 = malloc(sizeof(token_lexema_t *));
                token1->id = OP_ASIG;
                token1->lexema = "-";
                fprintf(fp2, "<%d, %s>\n", token1->id, token1->lexema);
                break;
            }
            case P:
            {
                leido = fgetc(fp1);
                token_lexema_t* token2 = malloc(sizeof(token_lexema_t *));
                token2->id = PARENT_IZQ;
                token2->lexema = "-";
                fprintf(fp2, "<%d, %s>\n", token2->id, token2->lexema);
                break;
            }
            case Q:
            {
                leido = fgetc(fp1);
                token_lexema_t* token3 = malloc(sizeof(token_lexema_t *));
                token3->id = PARENT_DCH;
                token3->lexema = "-";
                fprintf(fp2, "<%d, %s>\n", token3->id, token3->lexema);
                break;
            }
            case R:
            {
                leido = fgetc(fp1);
                token_lexema_t* token4 = malloc(sizeof(token_lexema_t *));
                token4->id = LLAVE_IZQ;
                token4->lexema = "-";
                fprintf(fp2, "<%d, %s>\n", token4->id, token4->lexema);
                break;
            }
            case S:
            {
                leido = fgetc(fp1);
                token_lexema_t* token5 = malloc(sizeof(token_lexema_t *));
                token5->id = LLAVE_DCH;
                token5->lexema = "-";
                fprintf(fp2, "<%d, %s>\n", token5->id, token5->lexema);
                break;
            }
            case T:
            {
                leido = fgetc(fp1);
                token_lexema_t* token6 = malloc(sizeof(token_lexema_t *));
                token6->id = PUNTO_COMA;
                token6->lexema = "-";
                fprintf(fp2, "<%d, %s>\n", token6->id, token6->lexema);
                break;
            }
            case U:
            {
                leido = fgetc(fp1);
                token_lexema_t* token7 = malloc(sizeof(token_lexema_t *));
                token7->id = COMA;
                token7->lexema = NULL;
                fprintf(fp2, "<%d, %s>\n", token7->id, token7->lexema);
                break;
            }
        }
    }
    return 0;
}