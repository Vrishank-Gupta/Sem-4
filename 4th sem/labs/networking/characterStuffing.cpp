#include <iostream>
#include <cstring>
using namespace std;
string charstuff(string s,char start,char end);
string decodecharstuff(string s,char start,char end);
int main(){
string str;
cout<<"Enter Data: ";
cin>>str;
char start;
cout<<"Enter Starting delimiter: ";
cin>>start;
char end;
cout<<"Enter Ending delimiter: ";
cin>>end;
string result = charstuff(str, start, end);
cout<<"Stuffed Data: "<<result<<endl;
cout<<"De-Stuffed Data: "<<decodecharstuff(result, start, end)<<endl;
}
string charstuff(string s,char start,char end){
string res;
res += start;
for(int i=0; i<s.length(); i++) {
if(s[i] == start) {
res += s[i];
res += s[i];
}
else if(s[i]==end) {
res += s[i];
res += s[i];
}
else {
res+=s[i];
}
}
res+=end;
return res;
}
string decodecharstuff(string s,char start,char end){
string data;
for(int i=1; i<s.length()-1; i++) {
if(s[i]==start && i!=s.length()-2) {
if(s[i+1]==start) {
data += s[i];
i++;
}
}
else if(s[i]==end && i!=s.length()-2) {
if(s[i+1]==end) {
data += s[i];
i++;
}
}
else {
data += s[i];
}
}
return data;
}