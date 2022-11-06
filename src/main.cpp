#include <iostream>
#include "TMyVector.h"

int main()
{
    TMyVector<int> arr(10);
 
    std::cout << "size: " << arr.GetSize() << std::endl;
    std::cout << "Rev size: " << arr.GetReservSize() << std::endl;
    
    for (int i = 0; i < 10; i++) {
        arr.PushBack(i + 1);
    }

    arr.Insert(5, 11);
    arr.Insert(0, 11);
    arr.Insert(arr.GetSize(), 11);

    std::cout << "size: " << arr.GetSize() << std::endl;
    std::cout << "Rev size: " << arr.GetReservSize() << std::endl;
 
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr.GetValue(i) << "\n";
    }

    return 0;
}
