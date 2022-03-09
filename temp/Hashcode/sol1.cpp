#include<bits/stdc++.h>
using namespace std;

struct Output{
    string p_name;
    vector<string> c_name;
};

struct Input_project{
    string p_name;
    int d, s, b, r;
    vector<pair<int, string>> req_skill;
};

struct Input_skill{
    string name;
    int number_of_skills;
    vector<pair<int, string>> skill;
};

bool cmp(struct Input_project &a, struct Input_project &b){
    return a.b < b.b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int contributor, project;
    cin >> contributor >> project;

    vector<Output> output(project);
    vector<Input_project> input_project(project);
    vector<Input_skill> input_skill(contributor);
    map<string, bool> vis;
    map<string, vector<pair<int, string>>> contributor_map;

    for(int i = 0; i < contributor; ++i){
        string name;
        int number_of_skills;

        cin >> name >> number_of_skills;
        input_skill[i].name = name;
        input_skill[i].number_of_skills = number_of_skills;
        vector<pair<int, string>> skill;
        vis[name] = 0;

        for(int j = 0; j < number_of_skills; ++j){
            string nm;
            int sk;

            cin >> nm >> sk;
            skill.emplace_back(sk, nm);
            contributor_map[nm].push_back({sk, name});
        }

        sort(skill.begin(), skill.end());
        input_skill[i].skill = skill;
    }

    map<string, pair<int, string>> proj_map;
    for(int i = 0; i < project; ++i){
        string p_name;
        int d, s, b, r;
        
        cin >> p_name >> d >> s >> b >> r;
        vector<pair<int, string>> req_skill;
        input_project[i].p_name = p_name;
        input_project[i].d = d;
        input_project[i].s = s;
        input_project[i].b = b;
        input_project[i].r = r;

        for(int j = 0; j < r; ++j){
            string skill_name;
            int lvl;

            cin >> skill_name >> lvl;
            req_skill.emplace_back(lvl, skill_name);
            proj_map[skill_name] = {lvl, p_name};
        }

        sort(req_skill.begin(), req_skill.end());
        input_project[i].req_skill = req_skill;
    }

    sort(input_project.begin(), input_project.end(), cmp);
    map<int, int> mark_proj;

    for(int z = 0; z < 50; ++z){
        for(int i = 0; i < project; ++i){
            if(mark_proj[i]){
                continue;
            }

            map<string, int> inc;
            int cnt = 0;
            for(int j = 0; j < input_project[i].r; ++j){
                string nm = input_project[i].req_skill[j].second;
                int lvl = input_project[i].req_skill[j].first;

                bool ok = false;
                vector<string> c_name;
                for(auto &x : contributor_map[nm]){
                    if(!vis[x.second] && lvl <= x.first){
                        ++cnt;
                        c_name.push_back(x.second);
                        vis[x.second] = true;
                        if(lvl == x.first){
                            inc[x.second] = 1;
                        }
                        ok = true;
                    }
                }

                if(cnt == input_project[i].r){
                    for(auto &x : contributor_map[nm]){
                        if(inc[x.second]){
                            ++x.first;
                        }
                    }

                    output[i].p_name = input_project[i].p_name;
                    output[i].c_name = c_name;
                }
                if(!ok){
                    continue;
                }
            }
        }
    }

    cout << output.size() << endl;
    for(auto x : output){
        cout << x.p_name << endl;
        for(auto y : x.c_name){
            cout << y << " ";
        }

        cout << endl;
    }
}