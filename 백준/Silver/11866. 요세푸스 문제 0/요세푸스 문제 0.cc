#include <iostream>
using namespace std;



int main()
{
    int N, K; cin >> N >> K;

    bool visited[1002] = { false,  };
    int pointer = -1;
    int temp = 0;
    cout << "<";
    for (int i = 0; i < N; i++)
    {
        temp = 0;
        while (temp<K)
        {
            pointer++;
            if (pointer >= N) pointer %= N;
            while (visited[pointer])
            {
                pointer++;
                if (pointer >= N) pointer %= N;
            }
            temp++;
        }

        visited[pointer] = true;

        cout << pointer +1;
        if (i < N - 1) cout << ", ";
    }
    cout << ">";

    return 0;
}