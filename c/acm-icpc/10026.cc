/**********************************************************
    Program:    Shoemaker's Problem
    Author:     Saúl Martínez Vidals
    Date:       06/26/07
***********************************************************
	@JUDGE_ID: 63787VV 264 C++ "Mathematic Formula"
**********************************************************/

#include <iostream>
#include <string>

using namespace std;

/* función principal */
int main()
{
    int j, n, m, t[1000], s[1000], solucion[1000];
    
    cin >> n;
    
    for(int i = 0; i < n; i ++)
    {
        cin >> m;
        for(j = 0; j < m; j ++)
        {
            cin >> t[j];
            cin >> s[j];
        }
        
        for(k = 0; k < m; k ++)
            cout << solucion[k] << " ";
        cout << endl;
    }
    return 0;
}
