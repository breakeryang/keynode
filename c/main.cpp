


#include <string>
#include <iostream>

#include <opencv2/opencv.hpp>

#include "WinUtils.h"

using namespace std;


/**
 * print data type help
 */
void printDataType();

int main() {
    cout << "Hello, world !" << endl;
    printDataType();

    Box *box = new Box(1, 2, 3);
    cout << "Box -> box() = " << box->max() << endl;
    delete box; // 释放内存

//    Shape shape;
    double v = Shape::div(12, 23);
    cout << " 12 / 23 = " << v << endl;

    return 0;
}


void printDataType() {

    cout << "bool \t " << sizeof(bool) << endl;

    cout << "char \t" << sizeof(char) << endl;

    cout << "wchar_t \t" << sizeof(wchar_t) << endl; // 宽字符 32

    // 32 字节， 算是一个对象了吧
    cout << "string \t" << sizeof(string) << endl;

    cout << "int32_t \t" << sizeof(int32_t) << endl;


}
