//
// Created by yanzhiwen on 9/28/2018.
//

#ifndef NDK38_ARRAYSTACK_H
#define NDK38_ARRAYSTACK_H

#include <assert.h>
#include <malloc.h>
//用数组实现

template<class E>
class ArrayStack {

private:
    //栈顶元素的位置
    int top = -1;
    E *array = NULL;

    //栈的长度
    int size = 10;


public:
    //构造和析构
    ArrayStack();

    ~ArrayStack();

public:
    /**
     *
     * @return
     */
    bool isEmpty();

    /**
     * 弹出栈顶的元素
     * @return
     */
    E pop();

    /**
     *获取栈顶的元素但不弹出
     */
    E peek();

    /**
     * 将元素压入栈中
     * @param e
     */
    void push(E e);

private:
    void growArray();
};
template<class E>
E ArrayStack<E>::pop() {
    assert(top >= 0);
    return array[top--];
}

template<class E>
bool ArrayStack<E>::isEmpty() {
    return top == -1;
}

template<class E>
E ArrayStack<E>::peek() {
    return array[top];
}

template<class E>
void ArrayStack<E>::push(E e) {
    //需要判断下是否有足够的空间
    if (top + 1 == size) {
        //扩容
        growArray();
    }
    array[++top] = e;

}


template<class E>
ArrayStack<E>::ArrayStack() {
    //创建一个数组 并开辟内存空间
    array = (E *) malloc(sizeof(E) * 10);
}

template<class E>
ArrayStack<E>::~ArrayStack() {
    delete array;
}

template<class E>
void ArrayStack<E>::growArray() {
    size += size >> 1;
    //重新开辟内存空间
    array = (E *) realloc(array, size * sizeof(E));
}


#endif //NDK38_ARRAYSTACK_H
