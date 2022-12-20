// CPPLesson10Part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
template <typename T>
void print(T* begin, T* end, char delimiter = ' ')
{
    while (begin != end)
    {
        std::cout << *begin++ << delimiter;
    }
    std::cout << '\n';
}
template <typename T, typename Predicate>
int copy_if(T* srcB, T* srcE, T* destB, T* destE,
    Predicate pred)
{
    int copyCount{ 0 };
    while (destB != destE and srcB != srcE)
    {
        if (pred(*srcB))
        {
            *destB++ = *srcB;
            ++copyCount;
        }
        ++srcB;
    }
    return copyCount;
}
class NoSequence
{
    bool init;
    int prevEl;
    int skipel;
public:
    NoSequence() : init{ false }, prevEl{ 0 }, skipel{ 5 } {}
    bool operator()(int el)
    {
        if (init)
        {
            bool result{ prevEl != el };
            if (result)
            {                
                    prevEl = el;
            }
            return result;
        }
        /*if (skipel > 0)
        { 
            skipel--;
            return false;
        }*/
            init = true;
            prevEl = el;
            return true;
       
    }
};
int main()
{
    const int size{ 10 };
    int arr1[size]{ 1,1,1,4,5,5,7,8,9,9 };
    int arr2[size]{};
    int* const arr1Begin{ arr1 };
    int* const arr1End{ arr1 + size };
    int* const arr2Begin{ arr2 };
    int* const arr2End{ arr2 + size };
    int* arr2NewEnd{};
    std::cout << "Original arr1:\n";
    print(arr1, arr1 + size);
    std::cout << "Original arr2:\n";
    print(arr2, arr2 + size);
    std::cout << '\n';
    std::cout << "arr2 copy of arr1 without sequencing "
        "duplicates:\n";
    arr2NewEnd = arr2Begin + copy_if(arr1Begin, arr1End,
        arr2Begin, arr2End, NoSequence{});
    print(arr2, arr2NewEnd);
    std::cout << '\n';
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
