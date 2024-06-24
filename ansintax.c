#include "anlex.h"

#define MAX_ELEMENTOS 100

typedef struct _nodo {
  char *dato;
  struct _nodo *siguiente;
} nodo;

nodo *pila[MAX_ELEMENTOS];
int cima = -1;

void push(char *dato) {
  if (cima == MAX_ELEMENTOS - 1) {
    printf("Error: Pila llena\n");
    exit(1);
  }
  cima++;
  pila[cima] = malloc(sizeof(nodo));
  pila[cima]->dato = dato;
  pila[cima]->siguiente = NULL;
}

char *pop() {
  if (cima == -1) {
    printf("Error: Pila vacía\n");
    exit(1);
  }
  char *dato = pila[cima]->dato;
  pila[cima] = pila[cima]->siguiente;
  cima--;
  return dato;
}

int top() {
  if (cima == -1) {
    return -1;
  }
  return atoi(pila[cima]->dato);
}

void mostrarPila() {
  printf("Pila: [");
  for (int i = cima; i >= 0; i--) {
    printf("%s ", pila[i]->dato);
  }
  printf("]\n");
}

void errorSintactico(char *esperado) {
  printf("Error sintáctico: Se esperaba '%s', pero se encontró '%s'\n", esperado, t.nombre);
  exit(1);
}

void match(int esperado) {
  if (t.compLex != esperado) {
    errorSintactico(getSimboloNombre(esperado));
  }
  getToken();
}

void grupoObjetos() {
  match('{');
  while (t.compLex != '}' && t.compLex != EOF) {
    if (t.compLex == 'STRING') {
      match(LITERAL_CADENA);
      match(':');
      valor();
      match(',');
    } else {
      errorSintactico("Cadena de caracteres o '}'");
    }
  }
  match('}');
}

void grupoArreglos() {
  match('[');
  while (t.compLex != ']' && t.compLex != EOF) {
    valor();
    match(',');
  }
  match(']');
}

void valor() {
  switch (t.compLex) {
    case LITERAL_NUM:
      match(LITERAL_NUM);
      break;
    case LITERAL_CADENA:
      match(LITERAL_CADENA);
      break;
    case 'true':
      match(BOOL);
      break;
    case 'false':
      match(BOOL);
      break;
    case '{':
      grupoObjetos();
      break;
    case '[':
      grupoArreglos();
      break;
    case 'null':
      match(E_NULL);
      break;
    default:
      errorSintactico("Valor no válido");
  }
}

void analizar() {
  getToken();
  while (t.compLex != EOF) {
    valor();
    match(',');
  }
}

int main() {
  initTabla();
  initTablaSimbolos();
  analizar();
  printf("Análisis exitoso\n");
  return 0;
}

int main_json (){
	if (t.compLex != EOF){
		json();
	}
}

void json (){
	
	case token1
	element();
	eof
	
}

void element(){
	switch (token1) {
	  case value1:
		//
		objeto();
		break;
	  case value2:
		// 
		array();
		break;
	  default:
		// 
		error_ll();
	}
}

void objeto(){
	
}

void array(){
	switch (token1) {
	  case '[':
		//
		match('[');
		element_list();
		match(']');
		break;
	}	
}


void element_list(){
	switch (token1) {
	case ']':
		//
		break;
	default:
		element();
		element2();
	}
}

void element2(){
	switch (token1) {
	case ',':
		//
		element_list();
		element2();
		break;
	}
}

switch (expression) {
  case value1:
    // code to execute when expression == value1
    break;
  case value2:
    // code to execute when expression == value2
    break;
  // ... more cases ...
  default:
    // code to execute when none of the cases match
}