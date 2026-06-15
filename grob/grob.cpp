// c 
// b 
// c 

#include <iostream>
using namespace std;

#include <cstdlib>

// Задание 2

/*class EventLog{
private:
    string* lines;
    int capacity;
    int count;
public:
    EventLog(const EventLog&) = delete;
    EventLog& operator = (const EventLog&) = delete;
    
    EventLog(int capacity){
        lines = new string[capacity];
        this->capacity = capacity;
        count = 0;
    }
    ~EventLog(){
        delete[] lines;
        lines = nullptr;
        capacity = 0;
        count = 0;
    }
    
    void Add(const string& line){
        if (count < capacity){
            lines[count] = line;
            count++;
        } else{
            for (int i = capacity - 1; i < 0; i--){
                lines[i - 1] = lines[i];
            }
            lines[capacity - 1] = line;
        }
    }
    
    void Print() const{
        for (const string& line : lines){
            cout << line << " ";
        }
    }
};*/


struct DamageRecord{
    string attackName;
    string targetName;
    int damage;
};

class DamageHistory{
private:
    DamageRecord* records;
    int capacity;
    int count;
public:
    DamageHistory(int capacity){
        records = new DamageRecord[capacity];
        this->capacity = capacity;
        count = 0;
    }
    ~DamageHistory(){
        delete[] records;
        records = nullptr;
        capacity = 0;
        count = 0;
    }
    DamageHistory(const DamageHistory& other){
        records = new DamageRecord[other.capacity];
        capacity = other.capacity;
        count = other.count;
    }
    DamageHistory& operator = (const DamageHistory& other){
        if (this == &other) return *this;
        
        delete[] records;
        
        capacity = other.capacity;
        count = other.count;
        records = new DamageRecord[capacity];

        for (int i = 0; i < count; i++){
            records[i] = other.records[i];
        }
        return *this;
    }
    
    void Add(const string& attacker, const string& target, int damage){
        if (count < capacity){
            records[count] = DamageRecord{attacker, target, damage};
            count++;
        } else{
            for (int i = 0; i < capacity - 1; i++){
                records[i] = records[i + 1];
            }
            records[capacity - 1] = DamageRecord{attacker, target, damage};
        }
    }
    void Print() const{
        for (int i = 0; i < capacity; i++){
            cout << i + 1 << ". ";
            cout << records[i].attackName << " -> ";
            cout << records[i].targetName << ": ";
            cout << records[i].damage << " damage";
            cout << endl;
        }
    }
};


int main(){
    // задание 1:
    /*int count = 10;
    int total = 0;
    int* damages = new int[count];
    for (int i = 0; i < count; i++){
        damages[i] = i;
        total += i;
    }
    cout << "total damage: " << total << endl;
    delete[] damages;
    damages = nullptr;*/
}
