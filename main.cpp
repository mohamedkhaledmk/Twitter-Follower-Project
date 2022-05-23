#include <bits/stdc++.h>
using namespace std;
string user,temp;
bool sortByVal(const pair<string, int> &a,const pair<string, int> &b);  //strings to copy lines from excel file to data structure.

int main()
{
  set<string> twit;                                 //creating the set to remove the repeated rows
  std::map<std::string, int> userFollowers;         //creating the map to count the followers of each user #id
  fstream fin;                                      //file pointer
  fin.open("twitter.csv", ios::in);                 // Open an existing file
  while(!fin.eof()){                                // keep reading until end-of-file    -- //O(N)
     getline(fin, user);
     twit.insert(user);
   }

    set<string>::iterator itr;                      //iterator to loop over the set
    for (auto itr : twit) {
        int pos = itr.find(",");                        //finding the pos of the comma
        temp = itr.substr(pos+1);                      //cutting the string after the comma, "second comma" the user being followed.   ---O(N)
        ++userFollowers[temp];                          //increasing the number of followers to this user #id.
    }



vector<pair<string, int>> vec;                      //creating the vector to sort the number of followers desc
 map<string, int> :: iterator it2;                  //  to iterate over the map
  for (it2=userFollowers.begin(); it2!=userFollowers.end(); it2++)
  {
    vec.push_back(make_pair(it2->first, it2->second));          //copying the map to the vector    --O(N)
  }

    sort(vec.begin(), vec.end(), sortByVal);                    //sorting the vector desc       (N*logN) quickSort

    while(1){
    int index;
    cout<<"enter 1 for the top-influenecer, 2 for the next top-influenecer ...etc./n Enter 0 to Exit "<<endl; //printing   ----O(N)
    cin>>index;
    if(index==0) return 0;
    cout<<"user number "<<vec[index-1].first<<" has " << vec[index-1].second << " followers"<<endl;
    }

    return 0;
}




/////////////////////////////////////////////////////////
bool sortByVal(const pair<string, int> &a,
               const pair<string, int> &b)          //third paramter in sort function to sort the vector of pair desc
{
    return (a.second > b.second);
}

