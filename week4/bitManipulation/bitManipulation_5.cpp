// solution 1
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            vector<int> v;
            v.push_back((n<<d)|(n>>(16-d)));
            v.push_back((n>>d)|(n<<(16-d)));
            
            return v;
        }
};