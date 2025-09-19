#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT
            
            for(int i = 0; i < index; i++){
                Entry current = array[i];

                if(current.compare(entry)){
                    array[i] = array[i+1];
                }
                if(index == 5 && array[index - 1] < entry->score){
                    cout << entry->name <<"'s score is too low to be added!";
                }
            }

            return;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};