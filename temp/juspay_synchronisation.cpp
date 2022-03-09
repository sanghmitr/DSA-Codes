
#include<bits/stdc++.h>
#define FOR(i,a) for(int i =0;i<a;i++)
using namespace std;


int w = 1;
struct Tree{
    public:
    bool isLocked;
    bool isLockable;
    int id;
    int ma;
    int no_locked_descd;
    bool processing;
    Tree* p;
    vector<Tree*> c;
    Tree(){
        isLocked = false;
        isLockable = true;
        id = -1;
        ma= w++;
        p = NULL;
        no_locked_descd = 0;
        processing = false;
    }

    Tree(Tree* parent){
        isLocked = false;
        isLockable = true;
        id = -1;
        ma = w++;
        p = parent;
        no_locked_descd = 0;
        processing = false;
    }
};

bool locking(Tree* n,int uuid){
    Tree *temp = n;
    while(n->processing == true){
      continue;
    }
    if( (n->isLocked) || n->no_locked_descd > 0) 
      return false;

      n->processing = true;
      temp = temp->p;
  // Traverse all parents and check if they are already locked or not.
      while(temp != NULL)
      {
        while(temp-> processing == true){
          continue;
        }
          if(  (temp->isLocked))
              return false;
          temp = temp->p;
      }
      temp = n;
  // Since locking possible
      while(temp->p != NULL)
      {
          temp = temp->p;
          temp->no_locked_descd += 1;
      }
  
    n->isLocked = true;
    n->processing = false;
    n->id = uuid;
    return true;
}


bool unlocking(Tree* n, int uuid){
    if(n->isLocked == false || (n->isLocked && uuid != n->id))           return false;
  
    Tree* T = n;
    n->isLocked = false;
    n->id = -1;

    Tree *temp = n;

    temp = temp->p;
    // Decrease all ancestor's number of locked descendent count by 1;
    // reset ancestor's user id.
    while(temp != NULL)
    {
        temp->no_locked_descd -= 1;
        temp = temp->p;
    }
    
    return true;
}


bool update(Tree* n,int uuid){
    if(n->isLocked== true) return false;
  
    Tree* T = n;
    queue<Tree*>q;
    if (T->no_locked_descd > 0){
    
    	 q.push(T);
        while(!q.empty()){
            Tree* temp = q.front();
            q.pop();
            for(auto x: temp->c){
                if(x->isLocked == true && x->id != uuid) {return false;}
                q.push(x);
            }
        }
        
        
      T = n;
      queue<Tree*> q;
    
      q.push(T);
      while(!q.empty()){
          Tree* temp = q.front();
          q.pop();
          for(auto x: temp->c){
              if(x->isLocked){
                  if(!unlocking(x,uuid)) return false;
              }
              q.push(x);
          }
      }
      return locking(n,uuid);
    }
    return false;
}



unordered_map<string, Tree*> sToT;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    Tree* t = new Tree();
    string d;
    cin>>d;

    sToT[d] = t;
    queue<Tree*> queue;
    queue.push(t);
    int k = 1;
    while(!queue.empty()){
        auto temp = queue.front();
        queue.pop();
        while(k<n && (int)temp->c.size() <m){
            string s;
            cin>>s;
            Tree* u = new Tree(temp);
            sToT[s] = u;
            temp->c.push_back(u);
            queue.push(u);
            k++;

        }
    }

    FOR(i,q){
        int qn,uuid;
        string name;
        bool ans;
        cin>>qn>>name>>uuid;
        if(qn == 1){
            ans = locking(sToT[name],uuid);
        }
        else if(qn == 2){
            ans = unlocking(sToT[name],uuid);
        }
        else{
            ans = update(sToT[name],uuid);
        }
        if(ans) cout <<"true\n";
        else cout <<"false\n";


    }
    return 0;
}

