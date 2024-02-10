#include "bits/stdc++.h"
using namespace std;

int main()
{
    // Set Items are : Sorted , Unique (u can't type one value 2 times or more) ,  I can't Edit its items

    // U can make multiset => in this case u can type one item more than one time. (with the same properties,functions).

    set<int>s1{1,1,8,2,3,9,0,4,5,4};
    cout<<"Set before insert(6) : ";
    for(int s : s1)
        cout<<s<<" "; // 0 1 2 3 4 5 8 9
    cout<<endl;
    s1.insert(6); // Will be added in its order ==> 0 1 2 3 4 5 6 8 9
    cout<<"Set after insert(6) : ";
    for(int s : s1)
        cout<<s<<" "; // 0 1 2 3 4 5 8 9
    cout<<endl;
    auto itS1 = s1.equal_range(3); // it gives me the value and the next value
    cout<<"*itS1.first : "<<*itS1.first<<endl; // 3 => The value
    cout<<"*itS1.second : "<<*itS1.second<<endl; // 4 => next value after 3
    cout<<"-----------------------\n";

    // I can order my element from lower to higher or higher to lower
    set<int>s = {10,225,90,22,400,7064,358,100,63458};
    cout<<"Set ordered from lower to higher : ";
    for(auto i : s)
        cout<<i<<" ";
    cout<<endl;
    set<int ,greater<int> >ss = {10,225,90,22,400,7064,358,100,63458};
    cout<<"Set ordered from higher to lower : ";
    for(auto i : ss)
        cout<<i<<" ";
    cout<<endl;

    cout<<"-----------------------\n";
    // See the next Code => its The best Case and its time complexity = O(1)
    set<string>s2;
    auto itS = s2.begin();
    s2.emplace_hint(itS,"Menna");
    itS = s2.emplace_hint(itS,"Ahmed"); // O(1)
    itS = s2.emplace_hint(itS,"Mohamed"); // O(1)
    itS = s2.emplace_hint(itS,"Tarek"); // O(1)
    s2.emplace_hint(s2.end(),"Yasser"); // O(1)
    cout<<"The O(1) Example : "<<endl;
    for(auto it : s2)
        cout<<it<<endl;
    cout<<"-----------------------\n";

    // Each iterator in the set has 2 jobs => Bool checks if its in the set (.second) / *the value of it (.first)
    set<string>s3{"Ali"};
    auto itSS = s3.emplace("Ahmed");
    cout<<"*itSS.first (Ahmed) : "<<*itSS.first<<endl; // Ahmed
    cout<<"itSS.second (Ahmed) : "<<itSS.second<<endl; // 1 because it isn't in the set
    itSS = s3.emplace("Ali");
    cout<<"*itSS.first (Ali) : "<<*itSS.first<<endl; // Ali
    cout<<"itSS.second (Ali) : "<<itSS.second<<endl; // 0 because it's in the set already
    cout<<"-----------------------\n";

    // Deleting :
    set<int>s4{10,20,30,40,50,60,70,80,90,100};
    cout<<"Set : ";
    for(auto i : s4)
        cout<<i<<" ";
    cout<<endl;
    cout<<"s4.count(110) : "<<s4.count(110)<<endl; // Bool value checks if this int is in the set or not.
    cout<<"s4.count(100) : "<<s4.count(100)<<endl; // Bool value checks if this int is in the set or not.
    s4.erase(50); // 50 will be removed.
    cout<<"Set with erase(50) : ";
    for(auto i : s4)
        cout<<i<<" ";
    cout<<endl;
    auto itSSS = s4.begin(); // what if I wanna go to 30 (2 steps after the begin)
    ++++itSSS; // 1+1+begin=third item.
    s4.erase(itSSS);
    cout<<"Set with erase(50) , ++++itSSS : ";
    for(auto i : s4)
        cout<<i<<" ";
    cout<<endl;
    itSSS = s4.find(70); // now my iterator has 70
    s4.erase(itSSS,s4.end()); // Delete from 70 to the end.
    cout<<"Set with erase(50) , ++++itSSS , itSSSS=s4.find(70)=>s4.end() : ";
    for(auto i : s4)
        cout<<i<<" ";
    cout<<endl;
    cout<<"-----------------------\n";
    set<int>s5{10,20,30,40,50,60,70,80,90,100};
    cout<<"Set : ";
    for(auto i : s5)
        cout<<i<<" ";
    cout<<endl;
    auto itLow = s5.lower_bound(30);
    auto itUpp = s5.upper_bound(60);
    s5.erase(itLow,itUpp); // Delete items from 30 to 60
    cout<<"Set with erase(itLow,itUpp) : ";
    for(auto i : s5)
        cout<<i<<" ";
    cout<<endl;
    cout<<"-----------------------\n";

    // Compare :
    set<int>s6 = {10,20,30,40,50,60,70,80,90};
    auto com = s6.key_comp(); // I user key_compare when I wanna print some values .. Like from 10 to 60
    auto it = s6.begin();
    int c = 70; // Here i put the last element I wanna go to.
    for(it ; com(*it,c) ; it++)
        // com(*it,c) => I check if *it reachs 70 or not (s6.begin(),20,30,40,50,60) ,when we reach 70 the loop stops.
    {
        cout<<*it<<" ";
    }
    cout<<endl;


    return 0;
}
