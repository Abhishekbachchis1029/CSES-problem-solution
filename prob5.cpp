#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fr(i,s,f) for(int i=s;i<f;i++)
#define dr(i,s,f) for(int i=s;i>=f;i--)
#define prnt(v) for(auto &z:v) cout<<z<<' ';cout<<'\n'
#define db cout<<"db: "
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define B begin()
#define E end()
#define all(v) v.B,v.E
#define sz(v) (int)((v).size())
#define vi vector<int>
#define vii vector<pair<int,int>>
const int MOD=1e9+7;
//-------------------------------------TIPS---------------------------------------------------//
//1.if u want to find number in range[a,b] first precompute then either think about lower and upper bound or think about prefix sum to find the count using s[b]-s[a-1]=count
//2.some time map of int,vector is also usefull 
//3.for MEx u can maintain a set of (x+1) for each x value until x+1 is not in the original set to find the mex and then take lower bound
//4.dealing with fraction either store them in pair of int ,int rahter than calulating a/b ie stay far away from floating point errors
//5.dealing with fraction also take /0 under case and also deal with the negatives think about reducing the fraction etc
//6.make a class or struct for handling the fraction
//7.sometime in greedy in sorting we use exchange argument type think about it also
//printf("%02d:%02d\n", h, mi); this help to print int upto digit like 5->05 ansd 2->02 etc
//instead of erasing a value from the vector we have a start varaible pointing to start of the vector and then move it ahead if we want to delete the first value of the vector
//------------------------------------bit manupilation----------------------------------------//
/*
int have base 10 while bit have base 2
operator are used for bitmanupilation 
AND(&)= two same thing give 1
OR(|)
left shift(<<)=multiply the given number with two to the power the number of place to be shifted or add 0 at the begining
right shift(>>)=devide the given number with two to the power the number of place to be shifted or add 0 at the end
so to check for the i th bit to be set then 
if x & (1 << i)==0 i th bit is not set
to set the i th bit of a number then take or of that number with left shifting 1 to i bits
to unset a set bit we take a xor it 1^1==0
and if we dont know what the bit is then take & with the complement of the left shifted bit to i th position
12=1100
12-1=1011
12&(12-1)=1000 so the right most bit is unset 
ie for unsetting the right most bit of a number take x&(x-1)
similarly if we have 
32=10000
32-1=01111
take 32&(32-1)==00000
so for chaecking if a number is in the power of 2 s then x&(x-1)==0
OR operation also increases while and always decreases or is equal
if we have tow number then xor of number is same then it will give 0 else will give the number of non similar bit in the two 
if u want to add 2 things but for diff i like if i is even then something else other thing and i should keep on increasing then use xor for t=0 t^=1 so t becomes 1,0,1,0.....
*/


//-----------------------------------------STL-----------------------------------------------//
//sort(arr,arr+x); goes till lenght x exclusive of x
//reverse(arr,arr+x)
//next_permutation(arr,arr+x);gives the next permutation of the arr element in the length this make the next permutation and return a value in bool if the permutation exist or not
//.find() and .count  are usefulas they do the work in logn rather than O(n) time complexity
//sort(v.begin(),v.end(),greater<int>()) this will sort the vector in descending order and greater works like a custom comparitor
//a comparator function in c++ does not include= on comparision as because a comparator should be irreflexive,asymmetric and transitive
//if we wNant a cut point in any array like to find median so we can maintain to multiset out of which one will contain the smaller element and the other will contain the larger element and shifting will occur between them
//similarly in case of finding element with highest frequency in a dynamic seqeuence we can use a combination of map and multiset as multiset will contain pair of element as (freq,element) and to delete and insert an element with changing freq map will be used
//if sorted array and prefix sum u can also think about lower and upper bound
//we can also use array of vectors
// in priority queue of pair the elements get sorted according to the first element then it is sorted by the second element
// we can not modify the container like multitset or map while iterating over it
// want to find high or low value with respect to something then use upper or lower bound
//prev is also used to find the itreatore to the pervious element of some other itreator in map ,set or multiset

//-------------------------------------Bit manupilaation------------------------------------//
//1.2^N==1<<n

//------------------------------------MOD OPERATION------------------------------------------//
//#define MOD (10^9)+7// we take this a s because first the no is prime number and the inverse modulo required during devide is unique for every number and exit;
//(a+b)%MOD=((a%m)+(b%m))%m
//Lcm(a,b)*hcf(a,b)=a*b
//similar for multiplication
//(a*b*c)%mod=(((a%Mod)*(b%mod))%MOD*(c%MOD))%mod
//(a-b)%MOD=((a%mod)-(b%mod)+mod)%mod
//(a^b)%MOD=if b=0->a%mod;
//else if b=even->cal pw(a,b/2,m); pw is a recursive function
/*
int pow(int a,long long int b,int m){
    if(b==0){
    return 1;
    int half=pow(a,b/2,m);
    if(b%2==0){
        return 1LL*half*half%m;
        }
    else{
        return (1LL*half*half)%m*a%m;
        }
}
for a/b%m= a * (b)^-1
when m is prime
so we fermatt little theroem so according to which inverse_modulow of(x)=pow(x,m-2,m)
or a^p-1%p=1 where p is a prime number
therefore ******a/b%m== a * inverse_modulow(b)== a * pow(b,m-2,m) % m ....ans
when m is not prime then we can use euler totient function

4 rule to deal with modulo expression that too large one 
1.make expression tree
2.deal with input like if they are alredy in overflow range than take modulo at the starting onyly
3.check for negative outputs
4.check while merging the ans of decision tree

*/



//----------------------------------SOME VECTOR OPERATIONS----------------------------------------//
//to find the first index where the sequence changes us the following function
//for finding form begining
//int x1 = find_if_not(v.begin(), v.end(), [&](int num){ return num == v[0]; }) - v.begin() - 1;
// Find last position where elements change
//int y1 = n - (find_if_not(v.rbegin(), v.rend(), [&](int num){ return num == v[n-1]; }) - v.rbegin());
// lambda function [capture clause](para){funct def}
//all_of(v.begin(),v.end(),lmbda fun)
//any_of(v.begin(),v.end(),lmbda fun)
//none_of(v.begin(),v.end(),lmbda fun)
// if u only want to check existence in a set u can also use .count() fun in place of .find() for a set
// instead of using a set to count the unique elements we can use a vector and then use the following line of code to remove all duplicates from the vector
// but firsr have to sort the vector v.resize(unique(v.begin(),v.end())-v.begin()); this is much faster than set



//---------------------------------STRING OPERATION FUNCTIONS-------------------------------------//
//how to take substring of a string
//s.substr(i,j-i+1);/where i is the starting point of the substring and j is the last char of the substring
// s.substr(i,length) where i is the starting index of the substring and length of the substring you want 
// s.find(string p) is used to find the string in the string s if it is not present then the function will give string::npos with no () at end
// so compair s.find(p)!=string::npos npos stand for null pos in the string
//s.substr(l-1,r-l+1)for substring bte l and r index inclusive
//use a dummy getline to remove the '\n'after a cin else the \n will be first taken by the getline then the next or the actual line 
//dummy getline== make an unintialised variable temp then use the getline to store the \n in temp like this getline(cin,temp);
//getline(cin,variable)
//stringstream ss(variable) make a string stream of the word seprated by space hence used when want the words to be seprated by spacess
//these are then stored in other string variable like ss>>v1 or ss>>v2 ..... so on 
// similarly if u want a part of string to be seprate by any char then use getline(ss,segment,'char') here ss is the string stream segment is a string to store the string seprated by the character
//this can also be done using simple cin>>variable in while loop and to print the word with spaces btw them we can use a flag
//we can use s.erase(i+1,1) ie this remove the character or str starting form index i+1 and of length 1. lenght can be more than one also
//master theorum= t(n)=a*t(n/b)+c find a,b,c for a program

//------------------BASIC MATH-----------------------------------------//
//GCD PROPERUTES
//1.gcd(a,b)==gcd(a,b%a)==gcd(a,b-a) as if a number /a and b then it eill also devide their difference and this can also give the gcd -ve
//so gcd(x+a,y+a,z+a...)=gcd(x+a,y-x,z-x.....) using above property
//number of diagonal in a n sided polygon=n*(n-2)/2
//double x;
//cin>>x;
//cout<<fixed<<setprecision(2);
/*. FIXED-> means everything next happens for after the floating point part only.
  setprecision(2) -> Now on, every print will happen with roundoff to 2 decimal places. */
//cout<<x<<'\n'; // will print the number. 
//cin>>n; 
// ceil=a+b-1/b and  floor=a/b round of =2*a+b/2*b
//long double is used for preciese calculation of the floating point or we also use an epcilen value like 1e-10 etc and add it to the result
/*string s;
        cin>>s;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count++;
            }
        }
        cout<<count<<endl;
// if we want to find a pair of n different variable then we can do it by fixing one and then iterating over the min and max possible value of the fixed variable and then find the range or the nimber of pair possible for the changing varaibles
//there is an identity called Bezouts identity according to which there will be int value satisfying the equation ax+by=c if and ony if the gcd(a,b) will devide c compeletly ie ax+by=gcd(a,b) ie the samllest c will be the gcd of both a and b ex= if a=3 and b=2 then the equation 3x+2y can give us 1 and -1 and zero if x=0 ans y=0 
reduction of sum of digit mean to take % with 9 as sum will be reduce until sum is less than 10

//n+1c2 is smae as n(n+1)/2


//-----------------------------------------SOME MATH ALGORITHM AND FUNCITON------------------------------//        
// prime number using square root tc=O(n*sqrt(n))
so if iis a factor of n ie 
n%i==0 and i<sqrt(n) then the other factor ie n/i will be >sqrt(n) hence this factor also give n%n/i==0 therfore these will be the two factor other than 1 and n
hence if we found a factor between 2 to sqrt(n) then there must be a factor whihc will be greater than the sqrt(n) hence the number wont be a prime number
therefore to declare a number non prime we have to find a factor till sqrt(n)
code:
for(int i=2;i<=n;i++){
    for(int j=2;j*j<=i;j++){
        if(i%j==0){
            non prime
        }
    }
}
// to take log with base 2=log(x)/log(2);
or recursive deivde by 2
    //seive of erthothenes
        vector<bool>v(120001,true);
    v[0]=v[1]=false;
    int n=v.size();
    for(int i=2;i<n;i++){
        if(v[i] && i*i<n){
            for(int j=i*i;j<n;j+=i){
                v[j]=false;
            }
        }
    }
    //
    my code for seive
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=0;
    for(int i=2;i<=n;i++){
        if(prime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    binary pow exponent=if(eg 2^13->2*2^12->2*4^6->2*16^3->2*16*16^2->32*256  TC=O(n/2) and if you have to take modular with any number then take modular while multilpying with result and in case of odd and even)

    //--------ITERATIVE BINARY SEARCH------------------------------------//
    int binary_s(vector<int>&v,int low,int high,int& d,int &ans){
    while(low<=high){
        int mid=low+(high-low)/2;
        if(pos(v,d,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    //sorted element and finding the first or last occurence of some element if multiple values are present then think about lower and upper bound
}
 */
int gcd(int a,int b){
    if(b==0){// see if a=0 b=2 then a%b=0 which goes as b and a=2 therefore if u do a==0 return b then this will be missed and a%b will be calculated 
        return a; //which will cause floating point error
    }
    return gcd(b,a%b);
}
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};//make matrix and then use these
bool sort_pair(const pair<int,int>&a,const pair<int,int>&b){
    return a.first<b.first;
}
//vector<bool>v(1e7+1,true);
//unordered_set<int>s1;
/*void seive(){
    v[0]=v[1]=false;
        int n=v.size();
        for(int i=2;i<n;i++){
            if(v[i] && i*i<n){
                for(int j=i*i;j<n;j+=i){
                    v[j]=false;
                }
            }
        }
}
class frac_red{
    public:
        pair<int,int>data;
        frac_red(int n,int d){
            data.first=n;
            data.second=d;
        }
        void red(){
            if(data.second<0){
                data.first=-1*data.first;
                data.second=-1*data.second;
            }
            if(data.second==0){
                data.first=1;
                data.second=0;//making 1/0 form as we will check for a and b
            }
            else if(data.first==0){
                data.second=1;
            }
            else{
                int gd=gcd(abs(data.first),abs(data.second));
                data.first/=gd;
                data.second/=gd;
            }
        }
};*/
/*int get_pow(int a,int b,int m){
    if(b==0){
        return 1;
    }
    int half=get_pow(a,b/2,m);
    if(b%2==0){
        return (half%m*half%m);
    }
    return (a%m*half%m*half%m)%m;
}*/
int log_fc(int x){
    int count=0;
    while(x>1){
        x=(x+1)/2;
        count++;
    }
    return count;
}
int get_pow(int a,int b,int m){
    if(b==0){
        return 1;
    }
    int half=get_pow(a,b/2,m);
    if(b%2==0){
        return (half%m*half%m);
    }
    return (a%m*half%m*half%m)%m;
}
int freq[1001000];
/*void bubble_sort(vi &a,vector<pair<int,int>>&s1,int k){
    int n=a.size();
        fr(i,0,n-1){
            bool flag=true;
            fr(j,0,n-1-i){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    flag=false;
                    s1.push_back({k,j+1});
                }
            }
            if(flag){
                return;
            }
        }
}*/
bool check(vector< pair<int,int> >&v,int r,int c){
    for(auto it:v){
        if(it.first!=r && it.second!=c){
            return false;
        }
    }
    return true;
}
void solve(){
    int n;
    cin>>n;
    if(n>1 && n<=3){
        cout<<"NO SOLUTION\n";
        return;
    }
    for(int i=n-1;i>=1;i-=2){
        cout<<i<<" ";
    }
    for(int i=n;i>=1;i-=2){
        cout<<i<<" ";
    }
    cout<<"\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t;
    //cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}
/*
    problem:-2117E for stress testing
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    map<int,int>a1;
    map<int,int>b1;
    fr(i,0,n){
        cin>>a[i];
        a1[a[i]]=i;
    }
    fr(i,0,n){
        cin>>b[i];
        b1[b[i]]=i;
    }
    int ans=0;
    fr(i,0,n-1){
        if(a[i]==a[i+1] || b[i]==b[i+1] || a[i]==b[i]){
            ans=max(ans,i+1);
        }
    }
    for(auto it:a1){
        auto it2=b1.find(it.first);
        if(it2!=b1.end() && abs(it.second-it2->second)!=1){
            ans=max(ans,min(it.second,it2->second)+1);
        }
    }
    cout<<ans<<"\n";
    */
