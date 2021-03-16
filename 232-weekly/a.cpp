class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<int> ind;
        for (int i = 0; i < s1.size(); i++)
        {
            // cout<<s1[i]<<" "<<s2[i]<<endl;
            if (s1[i] != s2[i])
            {
                ind.push_back(i);
            }
        }
        // debug(ind);
        if (ind.size() > 2 || ind.size() == 1)
        {
            return 0;
        }
        if (ind.size() == 0)
        {
            return 1;
        }
        string temp = s1;
        char c = temp[ind[0]];
        temp[ind[0]] = temp[ind[1]];
        temp[ind[1]] = c;
        // debug(temp);
        // swap(temp[ind[0]],temp[ind[1]]);
        if (temp == s2)
        {
            return 1;
        }
        temp = s2;
        c = temp[ind[0]];
        temp[ind[0]] = temp[ind[1]];
        temp[ind[1]] = c;
        // swap(temp[ind[0],ind[1]]);
        if (temp == s1)
        {
            return 1;
        }
        return 0;
    }
};
