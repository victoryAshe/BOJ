#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    char vowels[10] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    char input[270];
    string sentence = "";
    string endSignal = "#";
    int ans = 0;
    
    while (sentence != endSignal)
    {
        cin.getline(input, 270);
        sentence = input;
        if (sentence == endSignal) break;

        for (char vowel : vowels)
        {
            ans += count(begin(sentence), end(sentence), vowel);
        }
        cout << ans <<'\n';
        ans = 0;
    }

    return 0;
}