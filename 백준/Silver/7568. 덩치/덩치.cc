#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person
{
public:
    int weight;
    int height;
    int rank;
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<Person> people;
    int weight, height;
    for (int i = 0; i < N; i++)
    {
        Person person;
        cin >> weight >> height;
        person.weight = weight;
        person.height = height;
        people.push_back(person);
    }


    for (int i = 0; i<N; i++)
    {
        int rank = 1;
        for (int j = 0; j < N; j++)
        {
            if (i == j) continue;
            if (people[i].height < people[j].height && people[i].weight < people[j].weight) rank++;
        }
        people[i].rank = rank;
        cout << rank << " ";
    }
    
    
    return 0;
}