#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
/*Unordered Map*/
    //Creation
    unordered_map<string,int> mp;

    //Insertion
    //1
    pair<string,int> p1 = make_pair("Prem",3);
    mp.insert(p1);
    //2
    pair<string,int> p2("Simran",5);
    mp.insert(p2);
    //3
    mp["Gaurav"] = 2;
//Single entry for every key
    //Updation
    mp["Gaurav"] = 4;

    //Searching
    cout<<mp["Gaurav"]<<endl;
    cout<<mp.at("Prem")<<endl;
    cout<<mp["Mayur"]<<endl;  //Entry 0 made corresponding to the new key "Mayur"
    cout<<mp.at("Mayur")<<endl;
    //cout<<mp.at("Sagar")<<endl; No entry found for "Sagar"
    cout<<mp.size()<<endl;

    //Searching whether a key exists or not
    cout<<mp.count("Prem")<<endl;
    cout<<mp.count("Sagar")<<endl;
    cout<<mp.count("Mayur")<<endl;

    //Deletion
    mp.erase("Mayur");
    cout<<mp.size()<<endl;
    for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
    unordered_map<string,int> :: iterator i = mp.begin();
    while(i!=mp.end()){
        cout<<i->first<<" "<<i->second<<endl;
        i++;
    }

/*Map*/
    //Creation
    map<string,int> m;

    //Insertion
    //1
    pair<string,int> p3 = make_pair("Prem",3);
    m.insert(p3);
    //2
    pair<string,int> p4("Simran",5);
    m.insert(p4);
    //3
    m["Gaurav"] = 2;
//Single entry for every key
    //Updation
    m["Gaurav"] = 4;

    //Searching
    cout<<m["Gaurav"]<<endl;
    cout<<m.at("Prem")<<endl;
    cout<<m["Mayur"]<<endl;  //Entry 0 made corresponding to the new key "Mayur"
    cout<<m.at("Mayur")<<endl;
    //cout<<m.at("Sagar")<<endl; No entry found for "Sagar"
    cout<<m.size()<<endl;

    //Searching whether a key exists or not
    cout<<m.count("Prem")<<endl;
    cout<<m.count("Sagar")<<endl;
    cout<<m.count("Mayur")<<endl;

    //Deletion
    m.erase("Mayur");
    cout<<m.size()<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    map<string,int> :: iterator it = m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
}