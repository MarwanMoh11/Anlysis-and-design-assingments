//
// Created by Marwan on 5/12/2024.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    int m, n;
    cout << "Enter the length of the axis and the number of queries, separated by a space: ";
    cin >> m >> n;

    map<int,int> mp;
    set<int> st;
    vector<int> axis(m+1,0); // 1-indexed to initialize color of each axis

    while(n--){
        int w, c;
        cout << "Enter a pair of integers representing a query (coordinate and color), separated by a space: ";
        cin >> w >> c;
        if(mp[axis[w]]>0){
            mp[axis[w]]--;
            if(mp[axis[w]]==0){
                st.erase(axis[w]);
            }
        }
        axis[w] = c;
        mp[c]++;
        st.insert(c);

        cout << "Total number of distinct colors after executing the query: " << st.size() + 1 << endl;
    }
    return 0;
}