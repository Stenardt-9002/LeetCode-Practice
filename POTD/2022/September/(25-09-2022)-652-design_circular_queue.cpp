// https://leetcode.com/problems/design-circular-queue/



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;

const long long int mod2 =  1e18 ;




class MyCircularQueue {
public:
    int front = 0;
    int rear = -1;
    int *arr1;
    int size ;
    MyCircularQueue(int k) 
    {
        size = k;
        arr1 = new int[k];
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        rear = (rear+1)%size;
        arr1[rear] = value ;
        return true ;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false ;
        if(front == rear)
        {
            front = 0;
            rear = -1 ;
        }
        else 
            front = (front+1)%size;

        return true ;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return arr1[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return arr1[rear];
    }
    
    bool isEmpty() {
        return (rear==-1);
    }
    
    bool isFull() {
        return !isEmpty() && front == (rear+1)%size ;
    }
};



