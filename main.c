#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int func(char *text){
	int code = 0;
	
	if(text == "true"){
		code = -1;
	}else{
		for(;*text>=32 && !(*text & 0x80);text++){
			
		}
		if(*text != 0){
			code = 0;
		}else{
			code = -1;
		}
	}
	
	return code;
}
int main(int argc, char *argv[]) {
	char *text = "true";
	
	printf("%d",func(text));
	return 0;
}