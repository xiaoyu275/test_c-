#include <iostream> 
#include <fstream> 
#include <string> 

#include <vector> 
#include <algorithm> 
#include <iostream> 
int ia[ 10 ] = { 
  51, 23, 7, 88, 41, 98, 12, 103, 37, 6 }; 

using namespace std;
int main() 
{ 
  vector< int > vec( ia, ia+10 ); //左闭右开集合
  
 // 排序数组 
  sort( vec.begin(), vec.end() ); 
  
 // 获取值 
 int search_value; 
  cin >> search_value; 
  
 // 搜索元素 
 vector<int>::iterator found; 
  found = find( vec.begin(), vec.end(), search_value ); 
  if ( found != vec.end() ) 
    cout << "search_value found!\n" << search_value << endl; 
  else cout << "search_value not found!\n"; 
  
 // 反转数组 
  reverse( vec.begin(), vec.end() ); 
  for(found =vec.begin();found !=vec.end();found ++)
	cout<<*found <<endl;
 // ... 
} 

//int main() 
//{ 
//  ofstream outfile( "out_file" ); 
//  ifstream infile( "in_file" ); 
//  if ( ! infile ) { 
//    cerr << "error: unable to open input file!\n"; 
//  return -1; 
// } 
//  if ( ! outfile ) { 
//    cerr << "error: unable to open output file!\n"; 
//  return -2; 
// } 
// string word; 
//  while ( infile >> word ) 
//    outfile << word << ' '; 

// return 0; 
//} 
              