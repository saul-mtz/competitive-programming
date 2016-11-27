#include <iostream>

using namespace std;

/* función principal */
int main()
{
    short i, j, k, l, m, p, s;
    int caso = 0;
    char datos[2500][50];

    while(cin >> p >> k >> m)
    {
        s = 0;
        for(i = 0; i < m; i ++)
        {
            for(j = 0; j < p; j ++, s ++)
            {
                for(l = 0; l < k; l ++)
                    cin >> datos[s][k];
            }
        }
        cout << "Case " << ++ caso << ":\n";
    }

    return 0;
}
