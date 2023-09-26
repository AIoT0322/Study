// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//인라인함수 예제

#include <iostream>
using namespace std;

/*inline int SQUARE(int x)
{
    return x * x;
}

int main()
{
    cout << SQUARE(5) << endl;
    cout << SQUARE(12) << endl;
    return 0;
}*/

template <typename T>
inline T SQUARE(T x)
{
    return x * x;
}

int main(void)
{
    cout << SQUARE(5.5) << endl;
    cout << SQUARE(12) << endl;
    return 0;
}