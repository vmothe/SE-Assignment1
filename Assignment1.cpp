//Title: Fermat's Last Theorem
//Group members: Vikas Mothe, Vkhethavath
//Email Address: VikasMothe@lewisu.edu, VishnuKhethavath@lewisu.edu
#include <iostream>
#include <math.h> //It is used for Power function
#include <limits.h> // It is used for INT_MAX
using namespace std;
int main() {
    
    int x,y,z,n; //variables for the equation
    int lowerlimit_k = 10; // lower limit of K specified in the requirements
    int upperlimit_k = 50;// upper limit of K that we gave manually
    int nearest_miss = INT_MAX; // maximum value is assigned to nearest miss 
    int analyzetime; // How many time the equation will be solved with different values of x and y in one run of program
    cout<<"How many times you want to Analyze :: ";
    cin>>analyzetime; //take this input from user
    for (int i =0; i<analyzetime; i++) //this forloop will solve the equation analyzetime times 
    {
        bool check = false;
        while(check!=true) // this while loop is taking inputs and checking the conditions if condition will be wrong then it will help the user to take the input right after wrong entry
        {
            cout<<"Enter x = ";
            cin>>x;
            cout<<"Enter y = ";
            cin>>y;
            cout<<"Enter n = ";
            cin>>n;
            //check the values of x, y and n that they are in specified range
            if((x>=lowerlimit_k && x<=upperlimit_k) && (y>=lowerlimit_k && y<=upperlimit_k) && (n>2))
            {
                check = true; // means input is in the correct range
            }
        }
        // first step of equation x square + y square and store the result in xplusy
        long xplusy = (int) (pow (x, n) + pow (y, n));
        // taking the n root of xplusy value and which will be equal to z
        z = (int) pow (xplusy, 1.0/n);
        //finding the miss value
        int miss = xplusy - pow (z, n);
        //calculating the relative miss
        double relative_miss = 100. * miss / xplusy;
        cout<<"\nMiss ==> "<< miss <<" *=========* Relative Miss ==> "<<relative_miss<<endl;
        //to set the latest nearest miss value
        if(relative_miss<nearest_miss)
        {
            nearest_miss = relative_miss;
        }
        cout<<"Nearest Miss ==> "<<nearest_miss<<endl;
    }
    
    cout<<"  Task Completed  "<<endl;

    return 0;
}