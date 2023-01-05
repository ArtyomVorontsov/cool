#include <stdio.h>
#define STACK_SIZE 64
#define ASCII_DIGIT_OFFSET 48

int main(void){
	char stack[STACK_SIZE];
	int sp = STACK_SIZE;	// Pointing to the top of a stack
	char input;
	int i = 0, end = 0, t = 0;

	printf(">");
	for(;;){	// Stack machine main loop
		input = getchar();
		
		if(input == 10) continue;	// Skip backspace
		switch(input){
			case 'd':
				for(i = STACK_SIZE - 1; i >= sp; i--)
					printf("%c  ascii: %d\n", stack[i], stack[i]);
				break;

			case 'e':
				t = stack[sp];
				switch(t){
					case '+':
						sp += 1;	// Pop op sign 
						stack[sp + 1] = 
							(stack[sp] - ASCII_DIGIT_OFFSET) + (stack[sp + 1] - ASCII_DIGIT_OFFSET) + ASCII_DIGIT_OFFSET;
						sp += 1;	// Pop second operand
						break;

					case 's': 
						sp += 1;	// Pop op sign
						t = stack[sp];
						stack[sp] = stack[sp + 1];
						stack[sp + 1] = t;
						break;
				}	
				break;

			case 'x':
				end = 1;
				break;
				
			
			default:
				stack[sp - 1] = input;
				sp -= 1;
				break;

		}
		printf(">");

		if(end) break;
	}
	
	return 0;
}

