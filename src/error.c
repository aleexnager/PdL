#include <stdio.h>
#include <stdlib.h>
#include "header.h"

FILE *gen_error(FILE *fp, int cod_error, int linea, char c, char *buf_linea) {
    if (fp == NULL) exit(1);
    switch (cod_error) {
    case 50:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nEste carácter no es aceptado por la gramática del lenguaje \'%c\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 51:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 52:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 53:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 54:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 55:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 56:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 57:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 58:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 59:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 60:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nNo se acepta un delimitador. Se esperada el carácter \'/\'.\n\n", cod_error, linea, buf_linea);
        break;
    case 61:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 62:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 63:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 64:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 65:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nCarácter \'%c\' no esperado, se esperaba el carácter \'/\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 66:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nEste carácter no es aceptado por la gramática del lenguaje \'%c\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 67:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nEste carácter no es aceptado por la gramática del lenguaje \'%c\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 68:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nEste carácter no es aceptado por la gramática del lenguaje \'%c\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 69:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nEste carácter no es aceptado por la gramática del lenguaje \'%c\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 70:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nEste carácter no es aceptado por la gramática del lenguaje \'%c\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    case 71:
        fprintf(fp, "Error Léxico %d. Línea %d:\n%s\nEste carácter no es aceptado por la gramática del lenguaje \'%c\'.\n\n", cod_error, linea, buf_linea, c);
        break;
    }
    return fp;
}

FILE *gen_error_int(FILE *fp, int linea, int c, char *buf_linea) {
        fprintf(fp, "Error Léxico. Línea %d:\n%s\nEl int \'%d\' tiene un valor que se sale del rango representable [-32767, 32767].\n\n", linea, buf_linea, c);
        return fp;
}

FILE *gen_error_string(FILE *fp, int linea, char *lexema, char *buf_linea) {
        fprintf(fp, "Error Léxico. Línea %d:\n%s\nLa longitud del String \'%s\' supera el límite permitido de 64 carácteres.\n\n", linea, buf_linea, lexema);
        return fp;
}

FILE *gen_error_sintactico(int cod_error, FILE *fp, int linea, int token, int simb) {
    if (cod_error == 100)
    {
        fprintf(fp, "Error Sintáctico %d en la línea %d: No se esperaba el token %d. La secuencia de tokens no es aceptada por la gramática\n", cod_error, linea, token);
    }
    else
    {
        fprintf(fp, "Error Sintáctico %d en la línea %d: No se puede aplicar ninguna regla dado el simbolo no terminal %d y el token %d.\n", cod_error, linea, simb, token);
    }
}

