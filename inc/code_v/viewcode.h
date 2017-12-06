#ifndef CODE_VIEW_H
#define CODE_VIEW_H

#include "../code_r/readcode.h"

void printComm(int _y, int _x, int line, LINE *para);
void printPara(int _y, int _x, int _y_limit, int _x_limit, int line, LINE *para);
void printScrolled(int _y, int _x, int _y_limit, int _x_limit, LINE *para);

#endif // CODE_VIEW_H
