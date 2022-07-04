class Solution {
public:

vector<int>parent;
int find(int u)
{
    if(parent[u]==u)
        return u;
    return  find(parent[u]);
}
vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests)
{
    for(int i=0;i<n;i++)
    {
        parent.push_back(i);
    }
    vector<bool>res;
    
    for(int i=0;i<requests.size();i++)
    {
        int u=requests[i][0];
        int v=requests[i][1];
        int a=find(u);
        int b=find(v);
        bool valid=true;
        if(a==b)
        {
            valid=true;
            res.push_back(valid);
            continue;
        }
        for(int j=0;j<restrictions.size();j++)
        {
            int u1=restrictions[j][0];
            int v1=restrictions[j][1];
            int a1=find(u1);
            int b1=find(v1);
            if(a1==a && b1==b || a1==b && b1==a )
            {
                res.push_back(false);
                valid =false;
                break;
            }
        }
        if(valid==true)
        {
            res.push_back(true);
            parent[b]=a;
        }
            
    }
    return res;
    
}
};