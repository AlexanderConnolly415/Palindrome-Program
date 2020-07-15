//Name: Alexander Connolly
//Date: 7/9/2020
//Description: Palindrome Program
//Source: Tutor Jack Davis suggested calling MakeCap in line 126 to make sure that "end" is processed as "END" 
//such that the program ends whether the user enters lower case end or upper case end
//He also suggested incrementing my variables numSentences and numPalindromes after end because
//the program needs to be finished running before the program counts the number of sentences and the number of 
//palindromes

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//function that reverses the string

    string rString(string userString){
        
        string returnValue;
        
        int n = userString.length()-1;
        
        char userChar1;
        
        while(n >= 0){
            
            userChar1 = userString.at(n);
            
            returnValue += userChar1;
            
            //decrement while n is greater than or equal to 0
            
            n--;
            
        }
        
        return(returnValue);
        
        //userString = reverseString(userString);
        
    }
    
    
    //unction that capitalizes the string
    
    string makeCap(string userString){
        
        unsigned int capLength = userString.length()-1;
        
        string capString;
        
        //counter variable
        for(unsigned int i = 0; i<=capLength; i++){
            
            char userChar1 = userString[i];
            
            capString+=toupper (userChar1);
            
        }
        
        return (capString);
        
    }
    
    //function that filters only the numbers and letters from the string
    
    string makeFilter(string userString){
        
        int filterLength = userString.length()-1;
        
        string filterString;
        
        //for loop that runs from 0 to filterLength
        
        for(int i = 0; i<=filterLength; i++){
            
            //test to see if alnum is true, if not, do something else
            char userChar1 = userString.at(i);
            
            if (isalnum(userChar1))
            
                filterString+=userString[i];
                
        }
        
        return filterString;
        
    }
    
    //palindrome checker function
    
    bool checkPalindrome(string userString){

        string result1;
        
        string result2;
        
        result1 = rString(makeCap(makeFilter(userString)));
        
        result2 = makeCap(makeFilter(userString));
        
        if (result1 == result2)
            
            return (true);
            
        else
            
            return (false);
    }

int main(){
    
    int numSentences, numPalindromes;
    
    numSentences = 0;
    
    numPalindromes = 0;
    
    bool end = false;
    
    string userString;

    while(!end){
        
    //prompts user to enter a string
        
    cout << "Enter a string: " << endl;
    getline(cin,userString);
    
    if (makeCap(userString) == "END")
        end = true;

        
    else{
    
        numSentences++;
     
        //check to see if the user input is a palindrome
    
        if (checkPalindrome(userString) == true){
    
            cout << userString << " is a palindrome." << endl;
        
            numPalindromes++;
        }
        
        //if its not, let the user know that their input is not a palindrome
    
        else 
    
            cout << userString << " is NOT a palindrome." << endl;
    
        //end function
    
        }
        
    }
        
    cout << endl;    
    
    //outputs the number of sentences and palindromes after "END" is entered
        
    cout << "There were " << numSentences << " sentences entered. " << endl;
     
    cout << "There were " << numPalindromes << " palindromes found. " << endl;
    
    //return 0
    return 0;
}