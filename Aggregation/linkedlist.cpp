# include <iostream>

struct Node{
    
    int data;
    Node* prev = NULL;
    Node* next = NULL;
};

int main (){

Node nOne;
nOne.data = 10;
nOne.prev = &nOne;
nOne.next = &nOne;

Node nTwo;
nTwo.data = 20;
nTwo.prev = &nOne;
nTwo.next = NULL;

Node nThree;
nThree.data = 30;
nThree.prev = &nTwo;
nThree.next = NULL;

    return 0;
}