//
// Created by NAMND on 5/28/2023.
//
#include <bits/stdc++.h>
using namespace std;

class Singleton
{
private:
    int a = 5;
    static Singleton *theInstance;
    Singleton() {}
public:
    static Singleton *Instance()
    {
        if (theInstance == nullptr)
            theInstance = new Singleton();
        return theInstance;
    }
    void helloworld()
    {
        cout << theInstance->a << endl;
    }
};

Singleton *Singleton::theInstance = nullptr;
int main()
{
    Singleton* s = Singleton::Instance();
    s->helloworld();
}