/*
Una clase abstracta se usa para servir de clase base a otras clases. En terminología C++ se dice que una clase abstracta es aquella que posee al menos un método virtual puro.
 */
class Account {
public:
   Account( double d );   // Constructor.
   virtual double GetBalance();   // obtener balance.
   virtual void PrintBalance() = 0;   // Función virtual pura.
private:
    double _balance;
};
