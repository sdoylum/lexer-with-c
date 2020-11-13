#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_PLUS PLUS
#define T_MINUS MINUS


struct Token{
	char * type;
	char * value;
};

struct Node{
	struct Token tok;
	struct Node *next;
};

struct Lexer{
	char * text;
	int position;
	char currentChar;
};

void advance(struct Lexer *lex){
	lex->position++;
	if(strlen(lex->text) > lex->position){
		lex->currentChar = lex->text[lex->position];	
	}else{
		lex->currentChar = '\0';
	}
}

void tokener(struct Lexer *lex, struct Node *lis){
	while(lex->currentChar != '\0'){
		if(lex->currentChar == '+'){
			lis -> next = (struct Node*)malloc(sizeof(struct Node));
			lis -> next -> tok.type="op";
			lis -> next -> tok.value="topla";
			lis = lis->next;
			lis->next = NULL;
			printf("%s", lis->tok.value);
			advance(lex);
		}else if(lex->currentChar == '-'){
			lis -> next = (struct Node*)malloc(sizeof(struct Node));
			lis -> next -> tok.type="op";
			lis -> next -> tok.value="cikar";
			lis = lis->next;
			lis->next = NULL;
			printf("%s", lis->tok.value);
			advance(lex);
		}else if(lex->currentChar == '*'){
			lis -> next = (struct Node*)malloc(sizeof(struct Node));
			lis -> next -> tok.type="op";
			lis -> next -> tok.value="carp";
			lis = lis->next;
			lis->next = NULL;
			printf("%s", lis->tok.value);
			advance(lex);
		}else if(lex->currentChar == '/'){
			lis -> next = (struct Node*)malloc(sizeof(struct Node));
			lis -> next -> tok.type="op";
			lis -> next -> tok.value="bol";
			lis = lis->next;
			lis->next = NULL;
			printf("%s", lis->tok.value);
			advance(lex);
		}else if(lex->currentChar == '='){
			lis -> next = (struct Node*)malloc(sizeof(struct Node));
			lis -> next -> tok.type="op";
			lis -> next -> tok.value="equals";
			lis = lis->next;
			lis->next = NULL;
			printf("%s", lis->tok.value);
			advance(lex);
		}else if(lex->currentChar == ';'){
			lis -> next = (struct Node*)malloc(sizeof(struct Node));
			lis -> next -> tok.type="op";
			lis -> next -> tok.value="semicolon";
			lis = lis->next;
			lis->next = NULL;
			printf("%s", lis->tok.value);
			advance(lex);
		}else if(lex->currentChar == '.'){
			lis -> next = (struct Node*)malloc(sizeof(struct Node));
			lis -> next -> tok.type="op";
			lis -> next -> tok.value="dot";
			lis = lis->next;
			lis->next = NULL;
			printf("%s", lis->tok.value);
			advance(lex);
		
		}else{	
			advance(lex);
		}
	}
	
}

int main()
{
	struct Node *list = (struct Node*)malloc(sizeof(struct Node));
	struct Lexer *lex = (struct Lexer*)malloc(sizeof(struct Lexer));;
	list->tok.type="idf";
	list->tok.value="cc";
	list->next=NULL;
	lex->position = -1;
	lex->text = (char*) malloc(256*sizeof(char));
	scanf("%s", lex->text);
	advance(lex);
	tokener(lex, list);
	
	return 0;
}

