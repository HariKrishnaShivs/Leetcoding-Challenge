#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    map<Node*,Node* > mp;
    Node* func(Node* root)
    {
        if(mp.find(root)!=mp.end())
            return mp[root];
        Node* temp=new Node(root->val);
        mp[root]=temp;
        for(int i=0;i<root->neighbors.size();i++)
        {
            temp->neighbors.push_back(func(root->neighbors[i]));
        }
        return temp;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        Node* temp=func(node);
        mp.clear();
        return temp;
    }
};