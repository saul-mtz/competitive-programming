#include <iostream>

using namespace std;

int main()
{
    unsigned long i, j, k, n = 1, m = 1, iterador = 1;
    
    while(n <= 9999)
    {
        for(i = 0; i < iterador; i ++)
        {
            for(j = 0; j < iterador; j ++, n ++)
            {
                cout << "f(" << n << ") = " << m << endl;
            }
            m ++;
        }
        iterador ++;
    }
    system("pause");
    
    return 0;
}
