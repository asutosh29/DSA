#include<iostream>
using namespace std;

void p1(){
    const int N = 5;
    const int M = 10;
    float* float_arr = (float*)malloc(N*sizeof(float));
    float* float_arr_2 = (float*)calloc(N, sizeof(float)); // 0 defaults

    // Values before initialisation
    for (int i = 0; i < N; i++)
    {
        cout << *(float_arr+i) <<" -- "<< *(float_arr_2+i) << endl;
    }
    cout << "-----" << endl;
    float_arr_2 = (float*)realloc(float_arr_2, M*sizeof(float));
    float_arr_2[5] = 10.1;
    float_arr_2[6] = 10.6;
    float_arr_2[7] = 10.7;
    cout << "###" << endl;
    for (int i = 0; i < M; i++)
    {
        cout << *(float_arr_2+i) << endl;
    }
    
    free(float_arr);
    free(float_arr_2);
    
    cout << "###" << endl;
    float* new_ptr = new float[N];
    for (int i = 0; i < N; i++)
    {
        *(new_ptr+i) = 0;
        cout << *(new_ptr+i) << endl;

    }

    delete[] new_ptr;
}

int main(){
    p1();
    return 0;
}