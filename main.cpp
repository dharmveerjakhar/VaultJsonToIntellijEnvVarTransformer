#include<bits/stdc++.h>
using namespace std;

string res;
bool flag = false;

void convertJsonConfigToIntellijEnvVar(string s) {

	for(int i=0;i<s.size();i++) {
		if(s[i]=='"') {
			flag=1-flag;
		} else if(s[i]==',') {
			if(flag) {
				res.push_back(s[i]);
			} else {
				res.push_back(';');
			}
		} else if(s[i]==':') {
			if(flag) {
				res.push_back(s[i]);
			} else {
				res.push_back('=');
			}
		} else if(s[i]==' ') {
		    if(!(res.size() > 0 and (res[res.size()-1]=='=' or res[res.size()-1]==';'))) {
		        res.push_back(s[i]);
		    }
		} else {
		    res.push_back(s[i]);
		}
	}
	
}

int main() {

	string s;

    while(getline(cin, s)) {
        convertJsonConfigToIntellijEnvVar(s);
    }
    
    cout<<res.substr(3, res.size()-4);

	return 0;
}
