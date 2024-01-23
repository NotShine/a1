 # include <iostream>

 int main (){


int arr [5] = {2,7,3,9,1};

int max = *arr;


for ( int i = 1; i < 5; i++){

    {
        if (* arr > *arr + i){
            max = *arr;
        }
    }
std::cout <<max;
}








    return 0 ;
 }