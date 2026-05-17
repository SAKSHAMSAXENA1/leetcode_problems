class Seg{
  vector<int> seg;
public:
    Seg(vector<int> &nums,int &n)
    {
        seg.resize(4*n);
        build(0,0,n-1,nums);
    }

    void build(int idx,int low,int high,vector<int> &nums)
    {
        if(low==high)
        {
            seg[idx] = nums[low];
            return;
        }

        int mid = (low+high)/2;

        build(2*idx+1,low,mid,nums);
        build(2*idx+2,mid+1,high,nums);

        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
    }

    int query(int idx,int low,int high,int l,int r)
    {
        if(high<l || r<low) return INT_MIN;

        if(l<=low && high<=r) return seg[idx];

        int mid = (low+high)/2;

        int left = query(2*idx+1,low,mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);

        return max(left,right);
    }
};
class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),res=0;
        vector<Seg> sgt;

        for(int i=0;i<m;i++)
            {
                sgt.emplace_back(matrix[i],n);
            }

        for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        int x = matrix[i][j];

                        if(x==0) continue;

                        int mx=x;

                        int s=i-x,e=i+x;

                        for(int row=max(s,0);row<=min(e,m-1);row++)
                            {
                                int l = j-x + (row==s || row==e);
                                l=max(l,0);
                                int r = j+x - (row==s || row==e);
                                r=min(r,n-1);

                                mx = max(mx,sgt[row].query(0,0,n-1,l,r));
                            }

                        res+= mx==x;
                    }
            }

        return res;
    }
};