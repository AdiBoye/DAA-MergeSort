#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void join(int list[], int first, int midpoint, int last);
void mergesort(int list[], int first, int last);
int main(){ int n; int g;
  ofstream output("details.dat");
  int w = 0;
  cout<<"how many Mergesorts do you want to perform"<<endl;
  cin>>g;
  while  (w<g){
  cout<<"Enter the size of the array"<<endl;
  cin>>n;
    srand((unsigned) time(0));
    int randomNumber;
    int numbers[n];
    for (int index = 0; index < n; index++) {
    randomNumber = (rand() % 100) + 1;
    numbers[index] = randomNumber;}
    cout<<"Elements in array are "<<endl;
    for (int i = 0; i<n; i++){
      cout<<numbers[i]<<",";
    }cout<<endl;
    output<<n<<"            ";
    auto start = high_resolution_clock::now();
    mergesort(numbers,0,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    output<<duration.count()<<endl;
    cout<<"Sorted array is "<<endl;
    for (int q = 0; q<n;q++){
      cout<<numbers[q]<<",";
    }cout<<endl;
    cout<<"Time taken to sort is "<<duration.count()<<" microseconds"<<endl;
     w++;}
    output.close();
    return 0;
}
void mergesort(int list[], int first, int last)
{
    if (first < last)
    {
        int midpoint = first+(last-first)/2;

        mergesort(list, first, midpoint);
        mergesort(list, midpoint+1, last);

        join(list, first, midpoint, last);
    }
}
void join(int list[], int first, int midpoint, int last)
{
    int count1, count2, count3;
    int size1 = midpoint - first + 1;
    int size2 =  last - midpoint;

    int templist1[size1], templist2[size2];

    for (count1 = 0; count1 < size1; count1++)
        templist1[count1] = list[first + count1];
    for (count2 = 0; count2 < size2; count2++)
        templist2[count2] = list[midpoint + 1+ count2];

    count1 = 0;
    count2 = 0;
    count3 = first;
    while (count1 < size1 && count2 < size2)
    {
        if (templist1[count1] <= templist2[count2])
        {
            list[count3] = templist1[count1];
            count1++;
        }
        else
        {
            list[count3] = templist2[count2];
            count2++;
        }
        count3++;
    }

    while (count1 < size1)
    {
        list[count3] = templist1[count1];
        count1++;
        count3++;
    }

    while (count2 < size2)
    {
        list[count3] = templist2[count2];
        count2++;
        count3++;
    }
}
