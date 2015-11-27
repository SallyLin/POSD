#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include "Shape.h"
#include <vector>
#include <string>
#include "Graphics.h"
#include <stack>
#include <utility>

const std::string newline("\n");
const std::string space(" ");

int areaSum(std::vector<Shape *> v);
/*
std::string fileContentsAsString(const char * fileName);
Graphics * extractGraphicsFromOneLine(std::string & contents, int & level);
Graphics * buildGraphicsFromFile(const char * fileName);
void compose(std::stack<std::pair<int, Graphics *>> & pda);
*/
#endif // UTIL_H_INCLUDED
