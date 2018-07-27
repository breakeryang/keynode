//
// Created by rabbit on 18-7-27.
//

#ifndef DEMO1_WIN_UTILS_H
#define DEMO1_WIN_UTILS_H


#include <cstdint>
#include <vector>

class WinUtils {


};
//
//int32_t _max(int32_t a, int32_t b) {
//    return a > b ? a : b;
//}

class Shape {

public:
    static double div(int32_t a, int32_t b) {
        if (b == 0) {
            throw "Division by zero condition";
        }
        return ((double) a / b);
    }
};

class Box : protected Shape {

private:
    int32_t height;
    int32_t length;
    int32_t breadth;

public:
    int32_t max(int32_t a, int32_t b) {
        return a > b ? a : b;
    }

    int32_t max() {
//        return height > length ? height : length;
        return max(length, max(height, breadth));
    }

    /**
     *  构造函数
     * @param a length
     * @param b height
     * @param c breadth
     */
    Box(int32_t a, int32_t b, int32_t c) {
        length = a;
        height = b;
        breadth = c;
    }

};

template<class T>
class Draw {
private:
    std::vector<T> el;
public:
    void d() {

    };

    void push(T const &a) {
//        el.push_back(a);
    };

    T top() {
//        return el.pop_back();
        return NULL;
    };

    bool empty() const {
        return el.empty();
    }
};

//
//void Draw::d() {
//    cout << "draw ... " << endl;
//}
//
//void Draw::push(const T &) {
//}
//
//T Draw::top() {
//}

#endif //DEMO1_WIN_UTILS_H
