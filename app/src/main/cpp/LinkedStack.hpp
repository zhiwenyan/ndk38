//
// Created by yanzhiwen on 9/28/2018.
//

#ifndef NDK38_LINKEDSTACK_H
#define NDK38_LINKEDSTACK_H

#endif //NDK38_LINKEDSTACK_H

#include <malloc.h>

template<class E>

class Node {
    //下一个节点
public:
    Node<E> *next;
    E value;

public:
    Node(E value, Node<E> *next) {
        this->value = value;
        this->next = next;
    }

};

template<class E>
class LinkedStack {

public:
    //头结点
    Node<E> *head = NULL;
    //栈顶的节点
    Node<E> *top = NULL;
public:
    int size = 0;

    LinkedStack();

    ~LinkedStack();

    /**
   * 将元素压入栈中
   * @param e
   */
    void push(E e);

    /**
    * 弹出栈顶的元素
    * @return
    */
    E pop();

    /**
     *获取栈顶的元素但不弹出
     */
    E peek();

private:
    Node<E> *node(int index);

};

template<class E>
void LinkedStack<E>::push(E e) {
    Node<E> *new_node = new Node<E>(e, NULL);

    if (top) {
        top->next = new_node;
    } else {
        head = new_node;
    }
    top = new_node;
    size++;
}


template<class E>
E LinkedStack<E>::peek() {

}

template<class E>
E LinkedStack<E>::pop() {
    //delete top;
    top = node(size - 1);
    return top->value;
}

template<class E>
Node<E> *LinkedStack<E>::node(int index) {
    Node<E> *h = head;
    for (int i = 0; i < size; ++i) {
        h = h->next;
    }
    return h;
}

template<class E>
LinkedStack<E>::~LinkedStack() {
    Node<E> *h = head;
    while (head) {
        Node<E> *next = h->next;
        delete h;
        head = next;
    }
    head = NULL;
}

template<class E>
LinkedStack<E>::LinkedStack() {

}

