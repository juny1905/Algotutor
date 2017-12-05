#include <stdio.h>

void setCursorPos(int row_Pos, int col_Pos)
{
	printf("\033[%d;%dH", row_Pos+1, col_Pos+1);
}

void setCursorPrint(int row_Pos, int col_Pos, char *_string)
{
	printf("\033[%d;%dH", row_Pos+1, col_Pos+1);
	printf("%s",_string);
}

// Testing line
/*
int main(void){
	SetCursorPos(10,10);
	return 0;
}
*/
