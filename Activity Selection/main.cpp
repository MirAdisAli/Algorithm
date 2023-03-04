#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

int selectMaxActivities(int start_times[],int end_times[],int n) {
    
    vector<pair<int,int>>activities;
    
    for(int i=0; i<n; i++)
    activities.push_back({start_times[i],end_times[i]});
    
    int j = 0; 
    unordered_set<int> setidx;
 
    if (activities.size() > 0) {
        setidx.insert(0);
    }
    
    sort(activities.begin(), activities.end(),
        [](auto const &left, auto const &right) {
            return left.second < right.second;
        });
 
    for (int i=1; i<activities.size(); i++)
    {
        if (activities[i].first >= activities[j].second)
        {
            setidx.insert(i);
            j = i;            
        }
    }

    return setidx.size();
}

int main() {
    ifstream fin("Input-ActivitySelection.txt");
    ofstream fout("Output-ActivitySelection.txt");
    
    int T; 
    fin >> T;
    
    for(int t=1; t<=T; t++){
    int n;
    fin >> n;
      
    int start_times[n];
    
    for(int i=0; i<n; i++){
        fin >> start_times[i];
    }
    
    int end_times[n];
    for(int i=0; i<n; i++){
        fin >> end_times[i];
    }
    
    int ans = selectMaxActivities(start_times, end_times, n);
    cout << "Test Case #" << t << ", # Max Activities = " << ans << endl;
    
    fout << "Test Case #" << t << ", # Max Activities = " << ans << endl;
    }

fin.close();
}