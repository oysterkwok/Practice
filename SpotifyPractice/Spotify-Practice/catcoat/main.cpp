//
//  main.cpp
//  catcoat
//
//  Created by Haoquan Guo on 2/16/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string.h>

using namespace std;

string queue;
map<string, int> offspring;
set<string> momcan, dadcan;

void clean(string & gene);
bool isColor(string gene, string color);

void dfs(int d, string pat);
void dfs2(int d, string pat);

void dfs(int d, string pat) {
    if (d >= 6) {
        momcan.insert(queue);
        return;
    }
    if (pat[d] == '-') {
        if (d < 2) {
            queue.push_back('B');
            dfs(d + 1, pat);
            queue[d] = 'b';
            dfs(d + 1, pat);
            queue.erase(d);
            return;
        }
        if (d < 4) {
            queue.push_back('D');
            dfs(d + 1, pat);
            queue[d] = 'd';
            dfs(d + 1, pat);
            queue.erase(d);
            return;
        }
        queue.push_back('O');
        dfs(d + 1, pat);
        queue[d] = 'o';
        dfs(d + 1, pat);
        queue.erase(d);
    }
    else {
        queue.push_back(pat[d]);
        dfs(d + 1, pat);
        queue.erase(d);
    }
}

void dfs2(int d, string pat) {
    if (d >= 5) {
        dadcan.insert(queue);
        return;
    }
    if (pat[d] == '-') {
        if (d < 2) {
            queue.push_back('B');
            dfs2(d + 1, pat);
            queue[d] = 'b';
            dfs2(d + 1, pat);
            queue.erase(d);
            return;
        }
        if (d < 4) {
            queue.push_back('D');
            dfs2(d + 1, pat);
            queue[d] = 'd';
            dfs2(d + 1, pat);
            queue.erase(d);
            return;
        }
        queue.push_back('O');
        dfs2(d + 1, pat);
        queue[d] = 'o';
        dfs2(d + 1, pat);
        queue.erase(d);
    }
    else {
        queue.push_back(pat[d]);
        dfs2(d + 1, pat);
        queue.erase(d);
    }
}

void clean(string & gene) {
    if (gene.at(0) == 'b' && gene.at(1) == 'B') {
        gene[0] = 'B';
        gene[1] = 'b';
    }
    if (gene.at(2) == 'd' && gene.at(3) == 'D') {
        gene[2] = 'D';
        gene[3] = 'd';
    }
    if (gene.length() == 5) {
        return;
    }
    if (gene.at(4) == 'o' && gene.at(5) == 'O') {
        gene[4] = 'O';
        gene[5] = 'o';
    }
}

bool isColor(string gene, string color) {
    clean(gene);
    // oo or o
    if (gene[4] == 'o') {
        if (gene[0] == 'B' && gene[2] == 'D' && color.compare("Black") == 0) {
            return true;
        }
        if (gene[0] == 'B' && gene[2] == 'd' && color.compare("Blue") == 0) {
            return true;
        }
        if (gene[0] == 'b' && gene[2] == 'D' && color.compare("Chocolate") == 0) {
            return true;
        }
        if (gene[0] == 'b' && gene[2] == 'd' && color.compare("Lilac") == 0) {
            return true;
        }
    }
    
    // OO or O
    if (gene[4] == 'O' && (gene.length() == 5 || gene[5] == 'O')) {
        if (gene[2] == 'D' && color.compare("Red") == 0) {
            return true;
        }
        if (gene[2] == 'd' && color.compare("Cream") == 0) {
            return true;
        }
    }
    
    // Oo
    if (gene.length() == 6 && gene[4] == 'O' && gene[5] == 'o') {
        if (gene[0] == 'B' && gene[2] == 'D' && color.compare("Black-Red Tortie") == 0) {
            return true;
        }
        if (gene[0] == 'B' && gene[2] == 'd' && color.compare("Blue-Cream Tortie") == 0) {
            return true;
        }
        if (gene[0] == 'b' && gene[2] == 'D' && color.compare("Chocolate-Red Tortie") == 0) {
            return true;
        }
        if (gene[0] == 'b' && gene[2] == 'd' && color.compare("Lilac-Cream Tortie") == 0) {
            return true;
        }
    }
    
    return false;
}


int main (int argc, const char * argv[])
{
    map<string, string> pattern;
    set<string> colorset;
    string mom, dad;
    int total_off = 0;
    
    colorset.insert("Black");
    colorset.insert("Blue");
    colorset.insert("Chocolate");
    colorset.insert("Lilac");
    colorset.insert("Red");
    colorset.insert("Cream");
    colorset.insert("Black-Red Tortie");
    colorset.insert("Blue-Cream Tortie");
    colorset.insert("Chocolate-Red Tortie");
    colorset.insert("Lilac-Cream Tortie");

    pattern["Black"] = "B-D-oo";
    pattern["Blue"] = "B-ddoo";
    pattern["Chocolate"] = "bbD-oo";
    pattern["Lilac"] = "bbddoo";
    pattern["Red"] = "--D-OO";
    pattern["Cream"] = "--ddOO";
    pattern["Black-Red Tortie"] = "B-D-Oo";
    pattern["Blue-Cream Tortie"] = "B-ddOo";
    pattern["Chocolate-Red Tortie"] = "bbD-Oo";
    pattern["Lilac-Cream Tortie"] = "bbddOo";

    getline(cin, mom);
    getline(cin, dad);
//    cin >> mom >> dad;
    string pat = pattern.find(mom)->second;
    queue.clear();
    dfs(0, pat);
    pat = pattern.find(dad)->second;
    queue.clear();
    dfs2(0, pat);
    
    
//    cout << "momcan:\n";
//    for (set<string>::iterator iter = momcan.begin(); iter != momcan.end(); iter ++) {
//        cout << *iter << "\t" << 1 << "\n";
//    }
//
//    cout << "dadcan:\n";
//    for (set<string>::iterator iter = dadcan.begin(); iter != dadcan.end(); iter ++) {
//        cout << *iter << "\t" << 1 << "\n";
//    }
//
    for (set<string>::iterator mi = momcan.begin(); mi != momcan.end(); mi ++) {
        for (set<string>::iterator di = dadcan.begin(); di != dadcan.end(); di ++) {
            for (int i = 0; i < 64; i ++) {
                int j = i;
                string str;
                string thismom = *mi;
                string thisdad = *di;
                clean(thisdad);
                clean(thismom);

                str.push_back(thismom[j % 2]);
                j /= 2;
                str.push_back(thisdad[j % 2]);

                j /= 2;
                str.push_back(thismom[j % 2 + 2]);
                j /= 2;
                str.push_back(thisdad[j % 2 + 2]);

                j /= 2;
                str.push_back(thismom[j % 2 + 4]);
                j /= 2;
                if (j % 2 == 0) {
                    str.push_back(thisdad[4]);
                }
//                cout << "M " << thismom << "\nD " << thisdad << "\n";
                //cout << "? " << str << "\n";
                clean(str);
//                cout << "! " << str << "\n";
                for (set<string>::iterator si = colorset.begin(); si != colorset.end(); si ++) {
                    if (isColor(str, *si)) {
//                        cout << "[+]" << str << "->" << *si << " : " << 1 << "\n";
                        map<string, int>::iterator oi = offspring.find(*si);
                        if (oi == offspring.end()) {
                            offspring[*si] = 1;
                        }
                        else {
                            offspring[*si] = oi->second + 1;
                        }
                        total_off += 1;
                        break;
                    }
                }
            }
        }
    }

  //  cout << offspring.size() << " Result done.\n";

    vector<pair<string, int> > result;
    for (map<string, int>::iterator oi = offspring.begin(); oi != offspring.end(); oi ++) {
        result.push_back(pair<string, int>(oi->first, oi->second));
//        cout << "R: " << oi->first << "\t" << oi->second << "\n";
    }

    //cout << result.size() << " Result done.\n";
    
    for (int i = 0; i < result.size() - 1; i ++) {
        for (int j = i + 1; j < result.size(); j ++) {
            int k = strcmp(result[i].first.c_str(), result[j].first.c_str());
            if (result[i].second < result[j].second || (result[i].second == result[j].second && k > 0)) {
                string tmp1 = result[i].first;
                int tmp2 = result[i].second;
                result[i] = pair<string, int>(result[j].first, result[j].second);
                result[j] = pair<string, int>(tmp1, tmp2);
            }
        }
    }
    
//    cout << result.size() << " Result done.\n";
    cout.precision(10);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i].first << " " << 1.0 * result[i].second / total_off << "\n";
    }
    return 0;
}

