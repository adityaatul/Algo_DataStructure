#include<bits/stdc++.h>
using namespace std;
#define no_of_chars 256
void solve(string given_str,string given_pattern ,int sl1 , int sl2)
{



    if (sl1 < sl2)
    {

        cout<<-1<<endl;
    }

    int hash_given_pattern[no_of_chars] = {0};
    int hash_given_str[no_of_chars] = {0};


    for (int i = 0; i < sl2; i++)
        hash_given_pattern[given_pattern[i]]++;

    int start = 0, start_index = -1, min_len = INT_MAX;


    int count = 0;
    for (int j = 0; j < sl1 ; j++)
    {

        hash_given_str[given_str[j]]++;


        if (hash_given_pattern[given_str[j]] != 0 &&
            hash_given_str[given_str[j]] <= hash_given_pattern[given_str[j]] )
            count++;


        if (count == sl2)
        {

            while ( hash_given_str[given_str[start]] > hash_given_pattern[given_str[start]]
                || hash_given_pattern[given_str[start]] == 0)
            {

                if (hash_given_str[given_str[start]] > hash_given_pattern[given_str[start]])
                    hash_given_str[given_str[start]]--;
                start++;
            }


            int len_window = j - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }


    if (start_index == -1)
    {
    cout<<-1<<endl;
    }

    cout<<given_str.substr(start_index, min_len)<<endl;
}


int main(){
  int t;
  cin>>t;
  while(t--){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    cout<<a<<" "<<b<<endl;
    int i=0,j=0;
    int l1=a.size();
    int l2=b.size();
    solve(a,b,l1,l2);

  }
  return 0;
}
