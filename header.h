#define ID 1
#define CTE_ENTERA 2
#define CADENA 3
#define OP_MODULO 4
#define OP_NEQ 5
#define OP_NEG 6
#define OP_MOD_ASIG 7
#define OP_ASIG 8
#define COMMENT 9
#define COMILLA 10
#define PARENT_IZQ 11
#define PARENT_DCH 12
#define LLAVE_IZQ 13
#define LLAVE_DCH 14
#define CORCH_IZQ 15
#define CORCH_DCH 16
#define COMA 17
#define PUNTO_COMA 18
#define INT 19
#define BOOLEAN 20
#define STRING 21
#define RETURN 22
#define FOR 23
#define INPUT 24
#define PRINT 25
#define FUNCTION 26
#define IF 27

typedef struct transicion {
    int estado_siguiente;
    char accion;
} transicion;

typedef struct token_valor {
    int id_token;
    int valor;
} token_valor;

typedef struct token_lexema {
    int id_token;
    char *lexema;
} token_lexema;