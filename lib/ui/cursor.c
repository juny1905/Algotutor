#include <stdio.h>

void SetCursorPos(int XPos, int YPos)
{
	printf("\033[%d;%dH", YPos+1, XPos+1);
}

// Testing line
int main(void){
	SetCursorPos(10,10);
	return 0;
}

