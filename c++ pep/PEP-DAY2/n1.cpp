//receive n number of values from the user and build binary search tree of the t 
//now ask for the type of traverssal user wants and perform that traversal
//inorder, preorder, postorder

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *buildBST(vector<int> &v, int start, int end)
{
   //base case
    if(start > end)
    {
         return NULL;
    }
    int mid = start + (end-start)/2;
    Node *root = new Node(v[mid]);
    root->left = buildBST(v, start, mid-1);
    root->right = buildBST(v, mid+1, end);
    return root;
}

void inorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    vector<int> v;
    while(true)
    {
        cout<<"1. Add value"<<endl;
        cout<<"2. Inorder"<<endl;
        cout<<"3. Preorder"<<endl;
        cout<<"4. Postorder"<<endl;
        cout<<"5. Exit"<<endl;
        int choice;
        cin>>choice;
        if(choice == 1)
        {   //enter values seprated by space
            string s;
            cout<<"Enter values"<<endl;
            cin.ignore();
            getline(cin, s);
            int i = 0;
            while(i < s.size())
            {
                string temp = "";
                while(i < s.size() && s[i] != ' ')
                {
                    temp += s[i];
                    i++;
                }
                v.push_back(stoi(temp));
                i++;
            }
        }
        else if(choice == 2)
        {
            Node *root = buildBST(v, 0, v.size()-1);
            inorder(root);
            cout<<endl;
        }
        else if(choice == 3)
        {
            Node *root = buildBST(v, 0, v.size()-1);
            preorder(root);
            cout<<endl;
        }
        else if(choice == 4)
        {
            Node *root = buildBST(v, 0, v.size()-1);
            postorder(root);
            cout<<endl;
        }
        else if(choice == 5)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}