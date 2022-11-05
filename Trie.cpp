#include <bits/stdc++.h>
using namespace std;
struct trie{
    trie *child[26];
    bool leaf;
};
trie *getnode(){
    trie *node = new trie();
    node->leaf = false;
    for (int i = 0; i < 26; i++)
        node->child[i] = NULL;
    return node;
}
trie *root = getnode();
void add(string s){
    trie *temp = root;
    for (char i : s){
        if (!temp->child[i - 'a'])
            temp->child[i - 'a'] = getnode();
        temp = temp->child[i - 'a'];
    }
    temp->leaf = true;
}
void printTrie(trie *root,string s){
    trie *temp=root;
    if (temp->leaf){
        cout<<s<<"\n";
        return;
    }
    for (int i=0;i<26;i++){
        if (temp->child[i]){
            printTrie(temp->child[i],s+(char)('a'+i));
        }
    }
}
bool searchpre(trie *root,string s,string f){
    trie *temp=root;
    if (s==f)
        return true;
    bool ans=false;
    for (int i=0;i<26;i++)
        if (temp->child[i])
            ans=max(ans,searchpre(temp->child[i],s+(char)('a'+i),f));
    return ans;
}
int main()
{
    int n;cin>>n;
    for (int i=0;i<n;i++){
        string s;cin>>s;
        add(s);
    }
    int q;cin>>q;
    while(q--){
        string f;cin>>f;
        searchpre(root,"",f)?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}
