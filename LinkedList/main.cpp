#include <vector>
#include <iostream>

struct LinkedElement{
    int value;
    LinkedElement* nextElement;
    void printValue();
};

void LinkedElement::printValue(){
    std::cout << "Element value: " << this->value << "\n";
}

int main(){

    LinkedElement linkedL = { 74, nullptr };
    linkedL.nextElement = new LinkedElement{ 31, nullptr };
    linkedL.nextElement->nextElement = new LinkedElement{ 98, nullptr };

    linkedL.nextElement->nextElement->printValue();
    return 0;
}