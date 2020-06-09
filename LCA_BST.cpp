Node* LCA(Node *root, int n1, int n2){
    if(root==nullptr)return root;
    int val=root->data;
    int a=max(n1,n2);
    int b=min(n1,n2);
    if(a>=val && b<=val)return root;
    if(a>val && b>val)return LCA(root->right,a,b);
    if(a<val && b<val)return LCA(root->left,a,b);
    
}
