#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*

Tower of Hanoi - 

The Tower Of Hanoi is a mathematical puzzle where we have three rods and n disks. 

The objective of the puzzle is to move all the disks from one rod to another, with the rule being that:
1) Only one disk can be moved at any given time.
2) Each move consists of taking the uppermost disk from one of the stacks
and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk in its source stack and placing it on top of another stack i.e., a disk can only be placed on top of an empty stack or a stack having smaller disks.
3) No larger disk may be placed on top of a smaller disk.

Three rods/towers are used - 
You may name them:
    
    A                   B                   C
    Source              Auxiliary/          Destination
                        Helper

The idea is to shift (n-1) disks from A to B using C.
Shift the last disk from A to C.
Shift (n-1) disks from B to C using A.
*/

int towerOfHanoi(int n, char rodA, char rodC, char rodB){
    if(n == 1) {
        cout<<"Move disk 1 from "<<rodA<<" to "<<rodC<<endl;
        return 1;
    }

    int moves = 0;

    //Move n-1 disks from source to auxiliary using destination as temp
    moves += towerOfHanoi(n-1, rodA, rodB, rodC);

    cout<<"Move disk "<<n<<" from "<<rodA<<" to "<<rodC<<endl;
    moves++;
    
    //Move n-1 disks from auxiliary to destination using source as temp 
    moves += towerOfHanoi(n-1, rodB, rodC, rodA);

    return moves;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cout<<"Enter number of pegs - ";
    cin>>n;

    int moves = towerOfHanoi(n, 'A', 'C', 'B');
    cout << "\nTotal number of moves taken - "<<moves;

    return 0;
}