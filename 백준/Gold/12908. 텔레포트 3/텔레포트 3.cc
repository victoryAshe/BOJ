#include <iostream>

using ll = long long;
const int MAX = 8;


struct Point { ll x, y; };

Point Make_Point()
{
    ll x,y;
    std::cin >> x >> y;

    return { x,y };
}

ll Manhattan(Point a, Point b)
{
    return std::llabs(b.x - a.x) + std::llabs(b.y - a.y);
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    // Get Edge
    Point Start = Make_Point(), End = Make_Point();

    ll dist[MAX][MAX] = { };
    Point arr[MAX] = { Start,End, };
    int size = 2;
    
    for (int i = 0; i < 3; i++)
    {
        Point TelStart = Make_Point(), TelEnd = Make_Point();
        arr[size] = TelStart; arr[size+1] = TelEnd;

        dist[size][size + 1] = dist[size + 1][size] = std::min(Manhattan(TelStart,TelEnd), 10LL);
        
        size+=2;
    }
    
    // Calc Manhattan
    for (int j = 0; j < MAX; j++)
    {
        dist[0][j] = dist[j][0] = Manhattan(Start, arr[j]);
        dist[1][j] = dist[j][1] = Manhattan(End, arr[j]);
    }
    
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (i == j) dist[i][j] = 0;
            else if (dist[i][j] == 0)
            {
                dist[i][j] = dist[j][i] = Manhattan(arr[i], arr[j]);
            }
        }
    }
    
    // Floyd Warshall
    for (int k = 0; k < MAX; k++)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                ll temp = dist[i][k] + dist[k][j];
                if (temp < dist[i][j]) dist[i][j] = temp;
            }
        }
    }

    // Print(Start-End).
    std::cout << dist[0][1];
    return 0;
}