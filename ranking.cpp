map<long, long> score_mapping;
vector<int> v;
int rank = 1;
score_mapping[scores[0]] = rank;
for(size_t i = 1; i <= scores.size(); i++) {
    if(scores[i] == scores[i - 1])
        continue;
    score_mapping[scores[i - 1]] = rank;
    rank++;
}
for(size_t i = 0; i < alice.size(); i++) {
    // cout<<alice[i]<<" ";
    for(map<long, long>::iterator it = score_mapping.begin(); it != score_mapping.end(); it++ )
    {
        // cout << it->first  << ':' << it->second <<endl;
        if(alice[i] < it->first) {
            v.push_back(it->second + 1);
            break;
        }
        else if(alice[i] == it->first) {
            v.push_back(it->second);
            break;
        }
        if(it->second == 1 && alice[i] > it->first){
            v.push_back(it->second);
            break;
        }
    }
}
return v;