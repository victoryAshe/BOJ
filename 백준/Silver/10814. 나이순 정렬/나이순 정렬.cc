#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
public:
    int age;
    string name;
    int idx;
};

bool compare(const Person& a, const Person& b)
{
    if (a.age == b.age) return a.idx < b.idx;
    return a.age < b.age;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<Person> people;
    int age; string name;
    for (int i = 0; i < N; i++)
    {
        Person person;
        cin >> age >> name;
        person.age = age;
        person.name = name;
        person.idx = i;
        people.push_back(person);
    }

    sort(people.begin(), people.end(), compare);
    for (Person p : people)
    {
        cout << p.age << " " << p.name << "\n";
    }

    return 0;
}