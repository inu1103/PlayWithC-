/*Program to find the number of duplicate elements 
  and, the number with the highest and lowest frequency*/

#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n; // No. of elements to be working with
    cin>>n;
    int a[n]; // An array of that size to store the elements
    cout<<"Enter "<<n<<" elements of your giving a space between each :-"<<endl;
    for(int i=0; i<n; i++) cin>>a[i]; // Enter n choices
    sort(a,a+n); // Sorts the array in increasing/ascending order
    set<int> s; // An STL class, that contains only unique values
    for(int i=0; i<n; i++) s.insert(a[i]); // Copying array elements into Set, so that every number will be taken only once, and the no. of elements can be known
    vector<int> v,v1; // An STL class Vector, for storing occurrence of each number and copying the Set list
    for(int x:s) v1.push_back(x); // inserts element at the last of the Vector
    int i=0,index;
    while(i<n){
        int count=1; // Since we already have every element once already present
        for(int m=i+1; m<n; m++){
            // Comparing an element with its following elements
            if(a[i]==a[m]){
                index=m; // Since array is already sorted, we can skip that much elements after first the count of first element
                count++;
            }
        }
        if(count==1) i+=1; // Element is present only once, so we just want to shift once
        else i=index+1; // Skipping the occurrences of one element
        v.push_back(count); // Storing of the counts, now to work on it only further
    }
    /* Vector "v" stores the count in such a way that counts are arranged in the manner as the number above it in the sorted list
       Ex.:-
              Sorted Array : 1 2 3 4 5
              Occurrences :  8 2 1 6 6 ( thus, arranged for the above sorted list, and not in ascending or descending order)
     */

    int dup=0;
    for(int x:v) // Traversing the Count-Vector
        if(x>1) dup++; // Calculating total number of duplicate elements

    cout<<"So, there are total "<<dup<<" duplicate elements, and they are :- ";

    for(int k=0; k<s.size(); k++)
        if(v[k]>1) cout<<v1[k]<<" "; // Displaying each duplicate element, by finding that its count is more than one

    cout<<endl<<"\nOccurrence of all the elements are respectively :- "<<endl;
    for(int k=0; k<s.size(); k++)
        cout<<v1[k]<<" - "<<v[k]<<" times"<<endl; // Displaying the count of each element in front of it
    cout<<endl;

    int max=v[0],min=v[0],index1=0,index2=0,max_freq=0, min_freq=0;

    // Finding the largest count in the Count Vector list, and noting its index
    for(int k=1; k<v.size(); k++){
        if(v[k]>max){
            max=v[k];
            index1=k;
        }
    }

    // The least count
    for(int k=1; k<v.size(); k++){
        if(v[k]<min){
            min=v[k];
            index2=k;
        }
    }
    for(int k=0; k<v.size(); k++)
        if(v[k]==max) max_freq++; // If there are more than one elements with the highest count

    for(int k=0; k<v.size(); k++)
        if(v[k]==min) min_freq++; // If there are more than one elements with the least count

    //Displaying the Numbers with the largest and the least count :-

    if(max_freq==1) cout<<"Number with highest frequency :- "<<v1[index1]; // Case where only one element is present largest time

    // Multiple elements with largest count
    else{
        cout<<"There are "<<max_freq<<" numbers, whose frequencies are equal and highest among all, and they are :- ";
        for(int k=0; k<v.size(); k++){
            if(v[k]==max) cout<<v1[k]<<" ";
        }
    }
    cout<<endl;
    if(min_freq==1) cout<<"Number with lowest frequency :- "<<v1[index2]; // Case where only one element is present least time

    // Multiple elements with least count
    else{
        cout<<"There are "<<min_freq<<" numbers, whose frequencies are equal and lowest among all, and they are :- ";
        for(int k=0; k<v.size(); k++){
            if(v[k]==min) cout<<v1[k]<<" ";
        }
    }
    cout<<endl;
    return 0;
}

