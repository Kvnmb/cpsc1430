#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void input();

int main(int argc, char *argv[])
{
    string input = "";
    int num = 0;
    char sign;
    string temp;
    Stack stack;

    cout << "\n****Showcasing the first task****";
    cout << "\n\nType the expression (type # to quit):";
    getline(cin, input);

    while(input != "#"){
        temp = "";
        num = 0;
        stringstream stream(input);
        while(stream >> sign){
            if(sign == '+'){
                num = stoi(temp);
                stack.push(num);
                temp = "";
            }else if(sign == '-'){
                if(temp == ""){
                    temp += sign;
                }else{
                    num = stoi(temp);
                    stack.push(num);
                    temp = "";
                    temp += sign;
                }
            }else{
                temp += sign;
            }
        }
        num = stoi(temp);
        stack.push(num);

        cout << "\nThe value of this expression is " ;

        int eval = 0;

        while(!stack.isEmpty()){
            stack.pop(num);
            eval += num;
        }

        cout << eval;

        cout << "\n\nType the expression (type # to quit):";
        getline(cin, input);
    }

    Queue queue;
    ifstream file;
    string filename;

    filename = argv[1];

    file.open(filename);

    while(file >> num){
        queue.enqueue(num);
    }

    file.close();

    int sum = 0;

    int size = stoi(argv[2]);

    cout << "\n\n\n****Showcasing the second task****" ;
    cout << "\nThe averages in each window of size " << size << " are [ ";

    Queue slide;

    while(!queue.isEmpty()){
        sum = 0;
        if(queue.total() < size){
            break;
        }else{
        for(int x = 0; x < size; x++){
            queue.dequeue(num);
            sum += num;
            slide.enqueue(num);
        }

        cout << sum / size << " ";

        while(!queue.isEmpty()){
            queue.dequeue(num);
            slide.enqueue(num);
        }
        
        slide.dequeue(num);

        while(!slide.isEmpty()){
            slide.dequeue(num);
            queue.enqueue(num);
        }
        }
    }

    cout << " ]\n\n";

    return 0;
}


