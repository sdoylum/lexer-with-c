#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void advance(struct Lexer lex){
	lex.position++;
	if(strlen(lex.text) > lex.position){
		lex.currentChar = lex.text[lex.position];
		
	}else{
		lex.currentChar = '\0';
	}
}

void tokener(struct Lexer lex, struct Node *lis){
	printf("%d",lex.currentChar);
	while(lex.currentChar != '8'){

		if(lex.currentChar == '+'){
			lis -> next = (struct Node*)malloc(sizeof(struct Node));
			lis -> next -> tok.type="art";
			lis -> next -> tok.value="+";
			printf("%s", lis->tok.value);
			lis = lis->next;
			lis->next = NULL;
			advance(lex);
		}else{
			
			advance(lex);
		}
	}
	
}

int main()
{
	struct Node *list = (struct Node*)malloc(sizeof(struct Node));
	struct Lexer lex;
	list->tok.type="idf";
	list->tok.value="cc";
	list->next=NULL;
	lex.position = -1;
	scanf("%s", lex.text);
	advance(lex);
	tokener(lex, list);
	return 0;
}

