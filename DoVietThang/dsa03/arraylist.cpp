#include<iostream>
#include<vector>
#include<conio.h>

using namespace std;

class ArrayList{
    public:
        static const int MAX_SIZE = 100;
        ArrayList(){
            last = -1;
            current = -1;
        };
        bool empty() const{
            if (last == -1) return true;
            return false;
        };
        int length(){
            return last + 1;
        }
        void insert(const int x, int i){
            last ++;
            for (int j = last; j > i; j--){
                element[j] = element[j-1];
            }
            element[i] = x;
        };
        void append(const int x){
            last ++;
            element[last] = x;
        };
        void erase(int i){
            for (int j = i; j < last; j++){
                element[j] = element[j+1];
            }
            last --;
        };
        int *at(int i){
            return &element[i];
        }
        void print() const{
            for (int i = 0; i <= last; i++){
                cout << element[i] << ", ";
            }
             cout << endl;
        };
    private:
        int element[MAX_SIZE];

        int current;
        int last;
};

int main(){

    ArrayList a;
    for(int i = 1; i <= 3; i++) a.append(i);
    for(int i = 3; i <= 5; i++) a.append(i);
    cout << "A = ";
    a.print();

    if(a.empty()==0){
        cout << "empty(A) : " << "false" << endl;
    }
    else{
        cout << "empty(A) : " << a.empty() << endl;
    }
    cout << "length(A) ->  " << a.length() << endl;
    cout << "element(A,0) -> " << *a.at(0) << endl;
    cout << "element(A,2) -> " << *a.at(2) << endl;

    a.insert(10,2);
    cout << "insert(A,10,2) -> A = " ;
    a.print();

    a.append(-5);
    cout << "append(A,-5) -> A = ";
    a.print();

    a.erase(3);
    cout << "del(A,3) -> A = ";
    a.print();

    a.erase(1);
    cout << "del(A,1) -> A = ";
    a.print();

    return 0;
}
