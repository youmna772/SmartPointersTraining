#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std ; 
class test {
private:
int data ; 
public:
test() :data{0} {
cout<<"/t Test constructor(" << data << ")" << endl; }
test (int data):data {data} {   cout<<"/t Test constructoe(" << data << ")" << endl;} 
int get_data() const {return data ;}
~test () {cout<<"Test desstructor(" << data << ")" << endl; }

    };

unique_ptr <vector <shared_ptr<test>>> make(){
    // reserve space in the heap for vector of shared pointers then declare a unique pointer point to the vector and return it 
unique_ptr <vector <shared_ptr<test>>> p1 = make_unique<vector <shared_ptr<test>>> () ;
return p1 ;
    }
void fill (vector <shared_ptr<test>> &vec , int num){
// we pass pointer to a vector of shred pointers called vec and integer number 
// needed to make shared pointer & test objects = num and ask the user for each data in each object 
for (int i =0 ; i<num ; i++ )
{  cout<< "please enter point [" << (i+1) << "]: "  ;
 int dataa  ; 
 cin >> dataa ;
shared_ptr<test> p1 = make_unique<test> (dataa) ;
 vec.push_back(p1);   
    }

    }
void display (const  vector <shared_ptr<test>> &vec){
   cout<< "Displaying vevtor data" << endl ;
 for (size_t i =0 ; i<vec.size() ; i++ )   
 {    
    cout << (vec[i])-> get_data() << endl;
  }
    } 
int main()
{
 unique_ptr<vector <shared_ptr<test>>> vec_ptr = {}; 
 vec_ptr = make() ;
 cout<< "How many data points dy you want to enter: ";
 int num ; 
 cin >> num ;
fill(*vec_ptr,num); 
 display(*vec_ptr);
 return 0 ;
}
