class Solution
{
public:
  //Insert one char from stringstream
    Solution():index(0)
    {
        for(int i=0;i<256;i++)
            hasht[i]=-1;
    }
    void Insert(char ch)
    {
         if(hasht[ch]==-1)
             hasht[ch]=index;
        else if(hasht[ch]>=0)
            hasht[ch]=-2;
        index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int minI=INT_MAX;
        char cc;
        bool Isa=false;
        for(int i=0;i<256;i++)
        {
            if(hasht[i]>=0&&hasht[i]<minI)
            {
                cc=char(i);
                minI=hasht[i];
                Isa=true;
            }
        }
        if(Isa)
            return cc;
        else
            return '#';
    }
private:
    int index;
    int hasht[256];
};
