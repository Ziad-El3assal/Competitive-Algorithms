//
// Created by zacks on 9/20/2023.
//
#include <bits/stdc++.h>
using namespace std;

struct point2d{
    double x,y;
    point2d(){};
    point2d(double _x,double _y):x(_x),y(_y){};
};

struct Event {

    int x,y;
    bool isleft;
    int index;
    Event(){};
    Event(int _x,int _y,bool _isleft,int _index):x(_x),y(_y),isleft(_isleft),index(_index){};
    bool operator<(const Event&e)const{
        if(y==e.y)return x<e.x;
        return y<e.y;
    }
};

struct Segment{
    point2d left,right;
};

bool onSegment(point2d p,point2d q,point2d r){
    if(q.x<=max(p.x,r.x)&&q.x>=min(p.x,r.x)&&q.y<=max(p.y,r.y)&&q.y>=min(p.y,r.y))return true;
    return false;
}
int orientation(point2d p,point2d q,point2d r){
    double val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val==0)return 0;
    return (val>0)?1:2;
}
bool doIntersect(Segment s1,Segment s2){
    int o1=orientation(s1.left,s1.right,s2.left);
    int o2=orientation(s1.left,s1.right,s2.right);
    int o3=orientation(s2.left,s2.right,s1.left);
    int o4=orientation(s2.left,s2.right,s1.right);
    if(o1!=o2&&o3!=o4)return true;
    if(o1==0&&onSegment(s1.left,s2.left,s1.right))return true;
    if(o2==0&&onSegment(s1.left,s2.right,s1.right))return true;
    if(o3==0&&onSegment(s2.left,s1.left,s2.right))return true;
    if(o4==0&&onSegment(s2.left,s1.right,s2.right))return true;
    return false;
}

set<Event>::iterator pred(set<Event> &s,set<Event>::iterator it){
    return it==s.begin()?s.end():--it;
}
set<Event>::iterator succ(set<Event> &s,set<Event>::iterator it){
    return ++it;
}
int isIntersect(Segment arr[], int n)
{
    unordered_map<string,int> mp;
    vector<Event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(Event(arr[i].left.x, arr[i].left.y, true, i));
        e.push_back(Event(arr[i].right.x, arr[i].right.y, false, i));
    }

    sort(e.begin(), e.end(), [](Event &e1, Event &e2) {return e1.x < e2.x;});

    set<Event> s;
    int ans=0;
    for (int i=0; i<2*n; i++)
    {
        Event curr = e[i];
        int index = curr.index;

        if (curr.isleft)
        {
            auto next = s.lower_bound(curr);
            auto prev = pred(s, next);
            bool flag=false;
            if (next != s.end() && doIntersect(arr[next->index], arr[index])){
                string s=to_string(next->index+1)+" "+to_string(index+1);
                if(mp.count(s)==0){mp[s]++;ans++;}
            }
            if (prev != s.end() && doIntersect(arr[prev->index], arr[index])){
                string s=to_string(prev->index+1)+" "+to_string(index+1);
                if(mp.count(s)==0){mp[s]++;ans++;}
            }
            if(prev != s.end() && next != s.end() && next->index==prev->index)ans--;


            s.insert(curr);
        }

        else
        {
            auto it=s.find(Event(arr[index].left.x, arr[index].left.y, true, index));
            auto next = succ(s, it);
            auto prev = pred(s, it);

            if (next != s.end() && prev != s.end())
            {  string s=to_string(next->index+1)+" "+to_string(prev->index+1);
                string s1=to_string(prev->index+1)+" "+to_string(next->index+1);
                if (mp.count(s)==0&&mp.count(s1)==0&&doIntersect(arr[prev->index], arr[next->index]))
                    ans++;
                mp[s]++;
            }

            s.erase(it);

        }
    }

    for(auto &pr:mp){
        cout<<"Line: "<<pr.first<<"\n";
    }
    return ans;
}

int main(){

   int n;
   cin>>n;
    Segment s[n];
   for(int i=0;i<n;i++){
       double x,y;
       cin>>x>>y;
         point2d p1(x,y);
         cin>>x>>y;
            point2d p2(x,y);
            s[i].left=p1;
            s[i].right=p2;
   }
   cout<<endl;
    cout<<endl<<isIntersect(s,n)<<endl;
   return 0;

}
