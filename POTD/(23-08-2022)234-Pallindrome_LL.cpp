// https://leetcode.com/problems/palindrome-linked-list/



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct ListNode 
{
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};



bool pallindrome_uitl(ListNode**head ,ListNode *headend)
{
    if(headend==NULL)
        return true ;
    bool endpoints = pallindrome_uitl(head , headend->next);
    if (!endpoints)
        return false ;
    
    bool datamatch = (*head)->val == headend->val;
    *head = (*head)->next ;
    return datamatch ;
    
}



bool isPalindrome(ListNode* head) 
{
    return pallindrome_uitl(&head , head);
}





