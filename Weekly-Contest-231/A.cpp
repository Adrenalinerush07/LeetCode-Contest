class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        bool f = 0, f2 = 0;
        for (auto i : s)
        {
            if (i == '1' and !f)
            {
                f = 1;
            }
            if (f and i == '0')
            {
                f2 = 1;
            }
            if (f2 and i == '1')
            {
                return 0;
            }
        }
        return 1;
    }
};