//#include <cstddef>
//#include <functional>
//using std::function;
//typedef unsigned int uint;
//
//template <typename T>
//struct Nodo
//{
//    T elem;
//    Nodo<T>* sig;
//    Nodo(T e)
//    {
//        elem = e;
//        sig = nullptr;
//    }
//};
//
//template <typename T>
//class ListaS
//{
//private:
//    Nodo<T>* ini;
//    Nodo<T>* fin;
//    uint lon;
//
//public:
//    ListaS() : ini(nullptr), fin(nullptr), lon(0) {}
//    ~ListaS();
//
//    // Agregar elemento
//    void insInicio(T elem);
//    void insFinal(T elem);
//    void insPos(T elem, uint pos);
//    // Eliminar elemento
//    void elimInicio();
//    void elimFinal();
//    void elimPos(uint pos);
//    // Modificar elemento
//    void modInicio(T elem);
//    void modFinal(T elem);
//    void modPos(T elem, uint pos);
//    // Obtener elemento
//    T obtInicio();
//    T obtFinal();
//    T obtPos(uint pos);
//    // Otras
//    uint longitud();
//    bool esVacia();
//    bool buscar(T elem);
//    bool comparar(T elem, uint pos, function<bool(T, T)> f);
//    void invertir();
//    void rotar(uint n, bool iniFin);
//};
//
//template <typename T>
//ListaS<T>::~ListaS()
//{
//    Nodo<T>* aux = ini;
//    while (aux != nullptr)
//    {
//        aux = ini;
//        ini = ini->sig;
//        delete aux;
//    }
//}
//
//// Agregar elemento
//template <typename T>
//void ListaS<T>::insInicio(T elem)
//{
//    //nuevo->sig = ini;
//    Nodo<T>* nuevo = new Nodo<T>(elem);
//    if (nuevo != nullptr)
//    {
//        if (lon == 0)
//        {
//            // nuevo->sig = nullptr;
//            ini = fin = nuevo;
//        }
//        else
//        {
//            nuevo->sig = ini;
//            ini = nuevo;
//        }
//        ++lon;
//    }
//    else
//        delete nuevo;
//}
//
//template <typename T>
//void ListaS<T>::insFinal(T elem)
//{
//    Nodo<T>* nuevo = new Nodo<T>(elem);
//    if (nuevo != nullptr)
//    {
//        if (lon == 0)
//        {
//            delete nuevo;
//            insInicio(elem);
//        }
//        else
//        {
//            // nuevo->sig = nullptr;
//            fin->sig = nuevo;
//            fin = nuevo;
//            //fin = fin->sig;
//            ++lon;
//        }
//    }
//    else
//        delete nuevo;
//}
//
//template <typename T>
//void ListaS<T>::insPos(T elem, uint pos)
//{
//    if (pos >= 0 && pos < lon)
//    {
//        if (pos == 0)
//            insInicio(elem);
//        else if (pos == lon - 1)
//            insFinal(elem);
//        else
//        {
//            Nodo<T>* aux = ini;
//            for (size_t i = 0; i < pos - 1; i++)
//                aux = aux->sig;
//            Nodo<T>* nuevo = new Nodo<T>(elem);
//            nuevo->sig = aux->sig;
//            if (nuevo != nullptr)
//            {
//                aux->sig = nuevo;
//                ++lon;
//            }
//            else
//                delete nuevo;
//        }
//    }
//}
//
//// Eliminar elemento
//template <typename T>
//void ListaS<T>::elimInicio()
//{
//    if (lon > 0)
//    {
//        if (lon == 1)
//        {
//            //delete ini;
//            //delete fin;
//            ini->sig = fin->sig = nullptr;
//            ini = fin = nullptr;
//        }
//        else
//        {
//            Nodo<T>* aux = ini;
//            ini = ini->sig;
//            delete aux;
//        }
//        --lon;
//    }
//}
//
//template <typename T>
//void ListaS<T>::elimFinal()
//{
//    if (lon > 0)
//    {
//        if (lon == 1)
//            elimInicio();
//        else
//        {
//            Nodo<T>* aux = ini;
//            for (size_t i = 0; i < lon - 2; i++)
//                aux = aux->sig;
//            // delete fin;
//            fin = aux;
//            aux = aux->sig;
//            delete aux;
//            --lon;
//        }
//    }
//}
//
//template <typename T>
//void ListaS<T>::elimPos(uint pos)
//{
//    if (pos >= 0 && pos < lon)
//    {
//        if (pos == 0)
//            elimInicio();
//        else if (pos == lon - 1)
//            elimFinal();
//        else
//        {
//            Nodo<T>* aux = ini;
//            for (size_t i = 0; i < pos - 1; i++)
//                aux = aux->sig;
//            Nodo<T>* aux2 = aux->sig;
//            aux->sig = aux2->sig;
//            delete aux2;
//            --lon;
//        }
//    }
//}
//
//// Modificar elemento
//template <typename T>
//void ListaS<T>::modInicio(T elem) { ini->elem = elem; }
//
//template <typename T>
//void ListaS<T>::modFinal(T elem) { fin->elem = elem; }
//
//template <typename T>
//void ListaS<T>::modPos(T elem, uint pos)
//{
//    if (pos >= 0 && pos < lon)
//    {
//        if (pos == 0)
//            modInicio(elem);
//        else if (pos == lon - 1)
//            modFinal(elem);
//        else
//        {
//            Nodo<T>* aux = ini;
//            for (size_t i = 0; i < pos; i++)
//                aux = aux->sig;
//            aux->elem = elem;
//        }
//    }
//}
//
//// // Obtener elemento
//template <typename T>
//T ListaS<T>::obtInicio()
//{
//    if (ini != nullptr)
//        return ini->elem;
//    return 0;
//}
//
//template <typename T>
//T ListaS<T>::obtFinal()
//{
//    if (fin != nullptr)
//        return fin->elem;
//    return 0;
//}
//
//template <typename T>
//T ListaS<T>::obtPos(uint pos)
//{
//    if (pos >= 0 && pos < lon)
//    {
//        if (pos == 0)
//            obtInicio();
//        else if (pos == lon - 1)
//            obtFinal();
//        else
//        {
//            Nodo<T>* aux = ini;
//            for (size_t i = 0; i < pos; i++)
//                aux = aux->sig;
//            return aux->elem;
//        }
//    }
//    else
//        return 0;
//}
//
//// Otras
//template <typename T>
//uint ListaS<T>::longitud() { return lon; }
//
//template <typename T>
//bool ListaS<T>::esVacia() { return lon == 0; }
//
//template <typename T>
//bool ListaS<T>::buscar(T elem)
//{
//    Nodo<T>* aux = ini;
//    while (aux != nullptr)
//    {
//        if (elem == aux->elem)
//            return true;
//        aux = aux->sig;
//    }
//    return false;
//}
//
//template <typename T>
//bool ListaS<T>::comparar(T elem, uint pos, function<bool(T, T)> f)
//{
//    if (ini != nullptr)
//        return f(obtPos(pos), elem);
//    else
//        return false;
//}
//
//template <typename T>
//void ListaS<T>::invertir()
//{
//    if (lon > 1)
//    {
//        int auxLon = lon;
//        for (size_t i = 0; auxLon > 0; i++)
//        {
//            insPos(fin->elem, i);
//            elimFinal();
//            auxLon--;
//        }
//    }
//}
//
//template <typename T>
//void ListaS<T>::rotar(uint n, bool iniFin)
//{
//    // Si iniFin == 1, entonces rotara los n primeros elementos
//    // al final
//    // Si iniFin == 0, entonces rotara los n ultimos elementos
//    // al inicio
//    if (lon > 1)
//    {
//        if (iniFin)
//        {
//            for (size_t i = 0; i < n; i++)
//            {
//                insFinal(ini->elem);
//                elimInicio();
//            }
//        }
//        else
//        {
//            for (size_t i = 0; i < n; i++)
//            {
//                insInicio(fin->elem);
//                elimFinal();
//            }
//        }
//    }
//}
//
