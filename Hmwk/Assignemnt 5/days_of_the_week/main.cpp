/* 
 * Author: Deepak Menon
 *Purpose: Template code for conditionals in C++
 * Created on October 6, 2015, 1:41 PM
 */

//Libraries
#include <iostream>
#include <cstdlib>

using namespace std;

//Execution begins here
int main(int argc, char** argv) {

   char days;
   
   cout<<"Enter the first letter of day which you attend class on [M-F]: ";
   cin>>days;
   
   switch(days){
    case 'M': 
        cout<<"11";
        break;
    case 'W': 
        cout<<"11";
    break;
    case 'T': 
        cout<<"5";
    break;
       case 'TH':
           cout<<"5";
           break;
       default:
           cout<<"0";
   }
    return 0;
}

