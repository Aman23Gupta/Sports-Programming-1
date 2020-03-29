struct node{
    node* par=nullptr;
    node* child[26]={nullptr};
    int occ=0;
};

void ins(node* root, string s){
    node* cur=root; //cur is the pointer to the current node;
    int n=s.length();
    rep(i,0,n){
        if(cur->child[s[i]-'a']==nullptr){ //if it is not initialized
            cur->child[s[i]-'a']=new node(); //we initialize
            cur->child[s[i]-'a']->par=cur; // we set its parent as cur
        }
        cur=cur->child[s[i]-'a']; //cur node is changed and child becomes new cur
    }
    cur->occ++; //finally when cur points to last string element we increase the occurrence
}

//How to delete a word
// search for the word
// if the word exists, then we start at the ending node
// the first thing we do is decrement the occurrence of the node by one

//Delete the Node if
//1. it has no children
//2. It's occurrence is 0
//3. Move to the parent node and repeat

node* look(node* root,string s){
    node* cur=root;
    int n=s.length();
    rep(i,0,n){
        if(cur->child[s[i]-'a']!=nullptr){//as long as we have non-null child
            cur=cur->child[s[i]-'a'];//cur is changed to child of cur
        }
        else return nullptr;// if no child is found we return null
    }
    return cur->occ!=0?cur:nullptr;//if no words end at cur we return null
}

void del(node* root,string s){
    int n=s.length();
    node* cur=look(root,s);
    if(cur!=nullptr){
        cur->occ--;// decrease occurrence
        node* parent=nullptr;//variable parent initialized
        bool isleaf=true;// variable isleaf that checks if parent of cur is leaf node or not

        for(int i=0;i<26;i++){
            if(cur->child[i]!=nullptr){// if any child of cur has non-null child it means it is not leaf
                isleaf=false;
                break;
            }
        }
        while(cur->par!=nullptr && isleaf && cur->occ==0){
            parent=cur->par;// variable parent is not cur's parent
            for(int i=0;i<26;i++){
                if(parent->child[i]==cur){//if a child of parent is found equal to cur
                    parent->child[i]=nullptr;//we make it null
                    delete cur;//delete it
                    cur=parent;// now cur points to parent
                }
                else if(parent->child[i]!=nullptr){//in case before coming across cur we get any other child that is not null means parent is not leaf
                    isleaf=false;
                }
            }
        }
    }
}
