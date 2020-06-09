// THE EXERCISE
// ***************************
// This exercise showcases the use of the break and continue statements.
// Solution Created By: Dustin Kaban
// Date: June 9th, 2020
// ***************************

#include <iostream>

using namespace std;

int main() {
    int count = 0;
    while(true)
    {
        count += 1;

        //end loop if count is greater than 8
        if(count > 8)
            break;

        //skip the number 3 and the number 7
        if(count == 3 || count == 7)
            continue;

        cout << count << endl;
    }
    return 0;
}
