#ifndef CODE_VIEW_H
#define CODE_VIEW_H

#include "../code_r/readcode.h"

int countPara(LINE *para);
void currentLine(int _y, int _x, int _y_limit, int _x_limit, int line);
void printPara(int _y, int _x, int _y_limit, int _x_limit, int line, LINE *para);
void printScrolled(int _y, int _x, int _y_limit, int _x_limit, LINE *para);

#endif // CODE_VIEW_H
