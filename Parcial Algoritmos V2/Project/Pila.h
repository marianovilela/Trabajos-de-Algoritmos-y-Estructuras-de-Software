//#include <iostream>
//#include <cstdlib>
//#include <functional>
//
//using namespace std;
//
//template <typename T>
//class Nodo
//{
//public:
//    T elem;
//    Nodo<T>* ant;
//    Nodo<T>* sig;
//    Nodo(T e)
//    {
//        elem = e;
//        ant = sig = nullptr;
//    }
//};
//
//template <typename T>
//class Pila
//{
//private:
//    Nodo<T>* ini;
//    Nodo<T>* fin;
//    long c;
//
//public:
//    Pila()
//    {
//        fin = ini = nullptr;
//        c = 0;
//    }
//
//    void push(T e)
//    {
//        Nodo<T>* nuevo = new Nodo<T>(e);
//        if (c == 0)
//            ini = fin = nuevo;
//        else
//        {
//            fin->sig = nuevo;
//            nuevo->ant = fin;
//            fin = nuevo;
//        }
//        ++c;
//    }
//    void pop()
//    {
//        if (c > 0)
//        {
//            if (c == 1)
//            {
//                ini->elem = fin->elem = 0;
//                ini = fin = nullptr;
//            }
//            else
//            {
//                Nodo<T>* aux = fin;
//                fin = fin->ant;
//                fin->sig = nullptr;
//                delete aux;
//            }
//            c--;
//        }
//    }
//    long size() { return c; }
//    void top(function<void(T)> f)
//    {
//        if (c != 0)
//            f(fin->elem);
//    }
//};
