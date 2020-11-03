
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr),right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr),right(nullptr) {}
  };
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL)
            return "X ";
        s+=(to_string(root->val)+" ");
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
    }
     
    TreeNode* func(string data,int& ind)
    {
        if((data[ind]=='X')||(ind>=data.length()))
        {
            ind+=2;
            return NULL;
        }
        string sx="";
        while((ind<data.length())&&(data[ind]!=' '))
        {
            sx+=data[ind];
            ind++;
        }
        ind++;
        int temp1=stoi( sx );
        TreeNode* nx=new TreeNode(temp1);
        nx->left=func(data,ind);
        nx->right=func(data,ind);
        return nx;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         int ind=0;
        return func(data,ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;