// Hello world! Cplayground is an online sandbox that makes it easy to try out
// code..

#include <iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//life is a suffering
class tree{
  class treeNode{
      public:
      string data;
      vector<treeNode *> children;
      
      treeNode(string d){
          this->data=d;
      }
  };
    treeNode* root;  
  public:
  tree(){
      root=NULL;
  }
 void show(){
     //dfs
     if(root!=NULL){
         stack<treeNode*> s;
         s.push(root);
         
         treeNode* tmp=NULL;
         
         while(!s.empty()){
             tmp=s.top();
             s.pop();
             
             cout<<tmp->data<<endl;
             vector<treeNode*> &cld=tmp->children;
             int k=cld.size()-1;
             while(k>=0){
                 s.push(cld[k]);
                 k--;
             }
         }
     }
 }
  
 void addRoot(string d){
     if(root==NULL){
         root=new treeNode(d);
     }else{
         //exeption
     }
 }
 
 void addChild(string d,string parent){
     treeNode *tmp=NULL;
     treeNode *parentptr=NULL;
     
     stack<treeNode*> s;
     s.push(root);
     
     while(!s.empty()){
         tmp=s.top();
         s.pop();
         
         if(tmp->data==parent){
             parentptr=tmp;
             break;
         }else{
             for(vector<treeNode*>::iterator it=tmp->children.begin();it!=tmp->children.end();it++){
                    s.push(*it);
                }

         }
     }
     if(parentptr!=NULL){
            parentptr->children.push_back(new treeNode(d));
        }else{
            //exeption
            cout<<"parent is null"<<endl;
        }

 }
 
 
 
};
int main(){
    tree t;
    t.addRoot("root");
    t.addChild("child1","root");
    t.addChild("child2","root");
    t.addChild("child3","child1");
    t.addChild("child4","child1");
    t.addChild("child5","child2");
    t.addChild("child6","child2");


    t.show();

}