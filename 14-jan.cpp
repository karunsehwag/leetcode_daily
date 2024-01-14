class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> vec(26,0);
        vector<int> vec1(26,0);
        for(char it:word1)
        {
            vec[it-'a']++;
        }
        for(char it:word2)
        {
            vec1[it-'a']++;
        }
        for(int i=0;i<26;i++)
        {
           
                if(vec[i]!=vec1[i]&&vec[i]!=0&&vec1[i]!=0)
                {
                     for(int j=i;j<26;j++)
            {

                if(vec[i]==vec1[j])
                {
                    swap(vec1[i],vec1[j]);
                    break;
                }
            }
            }
        }
      for(int i=0;i<26;i++)
      {
          if(vec[i]!=vec1[i])
            return 0;
      } 
      return 1; 
    }
};
