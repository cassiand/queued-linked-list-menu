// Cassian
// 10/15/22
// week 6 assignment
// creating a queued linked list with menu options

#include <iostream>

using namespace std;

class Link
{
public:
    double dData;                 
    Link* pNext;                   // pointer to next link
    
    Link(double d) :dData(d), pNext(NULL)  // constructor
    {  }
    
    void displayLink()                // display link
    {
        cout << dData << " ";
    }
    
};  
class FirstLast
{
private:
    Link* pFirst;                  // ptrs to first and last links
    Link* pLast;                   
public:
    
    FirstLast() : pFirst(NULL), pLast(NULL)  // constructor
    {  }
    
    ~FirstLast()                  // destructor
    {                              
        Link* pCurrent = pFirst;        // set pCurrent to first link
        while (pCurrent != NULL)        // as long as you aren't at the end of list
        {
            Link* pTemp = pCurrent;     // set temp to current link
            pCurrent = pCurrent->pNext; // move to next link
            delete pTemp;               // delete previous remembered link 
        }
    }
    
    bool isEmpty()                    //true if empty
    {
        return pFirst == NULL;
    }
    
    void insertLast(double dd)        // declare method to insert item at end
    {
        Link* pNewLink = new Link(dd); // create new link
        if (isEmpty())                 
            pFirst = pNewLink;          // if list is empty, first link is this new link
        else
            pLast->pNext = pNewLink;    // if not empty, set previous last link to new link
        pLast = pNewLink;              
    }
   
    double removeFirst()              // method to remove first item
    {                              
        Link* pTemp = pFirst;          
        double temp = pFirst->dData;
        if (pFirst->pNext == NULL)      // if only one link
            pLast = NULL;               
        pFirst = pFirst->pNext;        // new first is the old next link
        delete pTemp;                  // delete the old first link
        return temp;
    }
    
    void displayList()  // declare method to display list
    {
        Link* pCurrent = pFirst;        
        while (pCurrent != NULL)         // as long as you aren't at end of list
        {
            pCurrent->displayLink();     // print link
            pCurrent = pCurrent->pNext;  // set current to next link
        }
        cout << endl;
    }
    
};  
class LinkQ 
{
private:
    FirstLast userList;
public:
    
    bool isEmpty()          // returns true if queue is empty, false otherwise
    {
        return userList.isEmpty();
    }
    
    void insert(double x)      // declare method to insert double into queue
    {
        userList.insertLast(x);
    }
    
    double remove()            // declare method to remove first item from queue
    {
        return userList.removeFirst();
    }
   
    void displayQueue() // declare method to print queue
    {
        cout << "Queue (front-->rear): ";
        userList.displayList();
    }
   
};  

int main()
{
    LinkQ userQueue;       //make a queue
    int i = 1; // set i to 1
    do    // do the code below...
    {
        cout << "\nSelect an option:\n1. Is queue empty?\n2. Pop front\n3. Push back\n4. Display queue" << endl; // print menu options
        int userChoice; // declare variable for input
        cin >> userChoice; // get input
        int number;

        switch (userChoice) // use switch case block for menu options
        {
        case 1:
            printf(userQueue.isEmpty() ? "Yes" : "No\n"); 
            // formatted output for printing bool answer as yes/no found from https://stackoverflow.com/questions/17307275/what-is-the-printf-format-specifier-for-bool
            break;

        case 2:
            userQueue.remove(); // call remove method
            break;

        case 3:
            cout << "Enter a number to push into the queue" << endl; // prompt user for input
            cin >> number; // get input
            userQueue.insert(number); // call insert method with user number
            break;

        case 4:
            userQueue.displayQueue(); // call print method
            break;

        }
    } while (i == 1); // set infinite loop, since i is declared to =1
   
}  //end main()







