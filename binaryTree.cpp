#include <iostream>
using namespace std;
class BST{
    
         int data;
         BST *left,*right;

    public:
    BST(){}
    BST(int val){
        data=val;
        left=right=NULL;
    }
    BST* Insert(BST* root, int val){
        if(root==NULL){
            return new BST(val);
                }
                else if(val>root->data)
                      root->right= Insert(root->right, val);
                      else root->left= Insert(root->left,val);

                      return root;
    }
    BST* Inorder(BST* root)
{
    if (root==NULL) {
        return NULL;
    }
   // cout<<"preorder  :- ";
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
BST* Postorder(BST* root)
{
    if (root==NULL) {
        return NULL;
    }
    
    Postorder(root->left);
    Postorder(root->right);
     cout<<root->data<< " ";
}
BST* Preorder(BST* root)
{
    if (root==NULL) {
        return NULL;
    }
    //cout<<"preorder  :- ";
     cout<<root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
    

}
BST* search(int x,BST* root){
if(root==NULL){
    cout<<endl<<"not found or BST empty";
  return NULL;}
  if(root->data==x)
  { cout<<endl<<"Found";
  return root;
  }
  if(x<root->data)
  search(x,root->left);
  else
  search(x,root->right);
}

void remove(int x,BST* root)
{  BST * node=search(x,root);
   if(node->left==NULL&&node->right==NULL)
   delete node;
   if(node->left==NULL)
    {  BST *temp=node->right;
       node=temp;
       delete temp;
    }
    else if(node->left==NULL){
        BST *temp=node->left;
       node=temp;
       delete temp;
    }
    else{
        
        BST* succParent = root;
 
        // Find successor
        BST* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of it   s parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->data = succ->data;
 
        // Delete Successor and return root
        delete succ;

    }
    cout<<endl<<"Deleted: "<<x<<endl;

}

};

int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 40);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 100);
    b.Insert(root, 75);
    b.Insert(root, 66);
    b.Insert(root, 89);
    cout<<"Inorder  :- ";

   b.Inorder(root);
   cout<<endl<<"postorder  :- ";
    b.Postorder(root);
    cout<<endl<<"preorder  :- ";
    b.Preorder(root);
    cout<<endl;
    b.search(30,root);
    b.remove(66,root);
    b.Preorder(root);
}