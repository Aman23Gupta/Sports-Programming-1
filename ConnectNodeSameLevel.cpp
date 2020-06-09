void f(Node* node){
    vector<Node*> v;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp!=nullptr){
            if(temp->left!=nullptr)v.push_back(temp->left);
            if(temp->right!=nullptr)v.push_back(temp->right);
        }
        if(q.empty() && !v.empty()){
            int n=v.size();
            for(int i=0;i<n-1;i++){
                v[i]->nextRight=v[i+1];
            }
            v[n-1]->nextRight=nullptr;
            for(auto u:v){
                q.push(u);
            }
            v.clear();
        }
    }
}

void connect(Node *p){
   f(p);
}
