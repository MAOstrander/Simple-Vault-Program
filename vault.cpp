#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std ;

//A random fact generator created by Mathew Ostrander, 12/8/09 
int main()
{
    //Variable declaration
 int menu = 0;    
 int counterthing = 0;
 int randoindex = 0;
 int mew, meow, idiot;
 string newquote;
 long pos;
 char ch;
 bool flag = false;
   string line;
   vector<string> lines;
   
//Menu system  
    do {
    system("CLS");
    cout << "Select an option below:\n";
    cout << "To read the instructions press 1\n";
    cout << "To view a random fact press 2\n";
    cout << "To view a random quote press 3\n";
    cout << "To input a new fact press 4\n";
    cout << "To input a new quote press 5\n";
    cout << "To quit press 6\n";

//User menu choice
     do {                  //Simple logical loop to make sure the input is a number
    cin >> menu;
                if (!cin.good()) {
                    cout << "I SAID A NUMBER!!!" << endl;
                    idiot++;
                    flag = true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                } else {
            flag = false;
                }
                if (idiot>3){
                      system("CLS");
                      cout << "You are unable to follow simple instructions.\nGood day to you.\n";
                      system("PAUSE");           
                      return 0;
                             }
    } while (flag); 
    
    if (menu == 1){
     cout << "This is a random fact generator that uses a text file as a source file.\n";
     cout << "It reads in each line of the text file and randomly displays one upon command.\n";
     cout << "The menu relies on an integer from the user to determine what to do next,\n";
     cout << " 1 obviously opens the help instructions, \n 2&3 opens a text file and displays a new fact,\n";
     cout << " 4&5 allows you to type in any amount of text, stopping at the first ~ it sees.\n";
     cout << "Since the program works on a 'by line' basis, when inputting new facts avoid \n";
     cout << "using the enter key, as this will cause the program to input it as a seperate\n";
     cout << "fact per return pressed. (And don't worry, the ~ won't show up in the facts,\n";
     cout << "it's just something to let the program know that it's reached the end.)\n";
     cout << " 6 will simply exit the program.\n";
     system("PAUSE");             
    }
        else if (menu == 2){       //View another fact
        ifstream file("fact.txt");        //Reo-opens the file so that new facts are included
                 if (file.is_open()){
        lines.clear();
        while( getline( file, line ) ) lines.push_back( line );
        meow = lines.size();
        randoindex = rand() % meow;
        cout << lines[randoindex] << '\n';
        system("PAUSE");
        }
                 else{
        cout << "Oh noes!  Where is the file?\n";
        cout << "Please check that the source file is in the same directory as the program.\n";
        system("PAUSE");     
        } 
        }
        else if (menu == 3){       //View another fact
        ifstream file("quote.txt");        //Reo-opens the file so that new facts are included
                 if (file.is_open()){
        lines.clear();
        while( getline( file, line ) ) lines.push_back( line );
        meow = lines.size();
        randoindex = rand() % meow;
        cout << lines[randoindex] << '\n';
        system("PAUSE");    
        }
                 else{
        cout << "Oh noes!  Where is the file?\n";
        cout << "Please check that the source file is in the same directory as the program.\n";
        system("PAUSE");     
        }
    } 
        else if (menu == 4){ //Input a new fact
          ofstream outfile;
          outfile.open ("fact.txt", ios::out | ios::app);

          cout << "Input a new fact here: (End each fact with a ~)\n";
            while (ch!='~'){
             ch=cin.get();
             if (ch!='~'){
                outfile.put (ch);
                }
             }
             ch=cin.get();
            outfile.close();
        }
        else if (menu == 5){ //Input a new fact
          ofstream outfile;
          outfile.open ("quote.txt", ios::out | ios::app);

          cout << "Input a new quote here: (End each quote with a ~)\n";
            while (ch!='~'){
             ch=cin.get();
             if (ch!='~'){
                outfile.put (ch);
                }
             }
             ch=cin.get();
            outfile.close();
        }
        else if (menu == 6){  //Exit Loop
        system("CLS");
        cout << "Go with Grace";
        cout << endl;
        system("PAUSE");    
        }
        else{                //For those who can't read...
        menu = 0;
        cout << "I said to press either 1, 2, 3, 4, 5, or 6...\n";
        system("PAUSE");                                  
        }    
    } while (menu != 6);
    return 0;
}


