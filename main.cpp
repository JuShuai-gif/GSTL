#include "algorithm_test.h"
#include "Stack.h"
#include "GMath.h"
int main()
{
    G::Stack<int> intStack;
    G::Stack<std::string> stringStack;
    int a = 42;
    int b = 45;
    intStack.push(42);
    intStack.push(45);

    std::cout << intStack.top() << std::endl;
    stringStack.push("hello");
    stringStack.push({"template"});
    std::cout << stringStack.top() << std::endl;

    intStack.print(std::cout);
    std::cout << intStack;

    stringStack.print(std::cout);
    std::cout << stringStack;

    G::Stack<std::pair<int,float>> pairStack;
    pairStack.push(std::pair<int,float>(42,45.0f));
    //pairStack.print(std::count);
    //由于pair并不支持<<，所以它是错的
    //std::cout << pairStack;
    intStack.print();
    stringStack.print();

    std::vector<int> x{1,2,3,4,5};
    std::vector<int> y{2,4,1,7,5};
    int xi = 2;
    int dd = G::Lareange(x,y,xi);
    std::cout <<"dd : " << dd << std::endl;

    return 0;
}