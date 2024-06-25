#include "anlex.h"





void match(int esperado) {

	
	if(esperado == IDENTIFICADOR && t.compLex == LITERAL_CADENA){
			t.compLex=IDENTIFICADOR;
			strcpy(t.nombre, "IDENTIFICADOR");
	}else{
		if (t.compLex != esperado) {
			printf("Error sintáctico: Se esperaba '%s', pero se encontró '%s'\n", esperado, t.nombre);
		}
	}
	printf("Match '%s',  '%s'\n", t.pe->lexema, t.nombre);
	getToken();
}

void json(){
	element();	
}

void element(){
	switch (t.compLex) {
		case '{':
			// elige objetos
			objeto();
			break;
	    case '[':
			// elige array
			array();
			break;
	    default:
			printf("Error sintáctico: Valor NO VALIDO");
	}
}

void array(){
	switch (t.compLex) {
		case '[':
			match('[');
			element_list();
			match(']');
			break;
		default:
			printf("Error sintáctico: Valor NO VALIDO");
	}	
}


void element_list(){
	switch (t.compLex) {
	case ']':
		//
		break;
	default:
		element();
		element_list2();
	}
}

void element_list2(){
	switch (t.compLex) {
	case ',':
		//
		match(',');
		element_list();
		element_list2();
		break;
	default:
		printf("coma no encontrado.\n");
	}
}

void objeto(){
	switch (t.compLex) {
	  case '{':
		//
		match('{');
		atribute_list();
		match('}');
		break;
	}	
}

void atribute_list(){
	switch (t.compLex) {
	case '}':
		break;
	default:
		atribute();
		atribute_list2();
	}
}

void atribute_list2(){
	switch (t.compLex) {
	case ',':
		//
		match(',');
		atribute_list();
		atribute_list2();
		break;
	default:
		printf("coma no encontrado.\n");
	}
}

void atribute(){
	atribute_name();
	match(OPASIGNA); 
	atribute_value();
}

void atribute_name(){
	match(IDENTIFICADOR); 
}

void atribute_value(){
	switch (t.compLex) {
		case '{':
			element();
			break;
		case '[':
			element();
			break;
		case LITERAL_CADENA:
			match(LITERAL_CADENA);
			break;
		case LITERAL_NUM:
			match(LITERAL_NUM);
			break;
		case BOOL:
			match(BOOL);
			break;
		case E_NULL:
			match(E_NULL);
			break;
		default:
			printf("Error sintáctico: Valor NO VALIDO \n");
	}
}

