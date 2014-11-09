#include "utils.h"


vector<string> split(string text, char c){
    vector<string> parsed;
    string temp;
    int index;
    while(true){
        /*on each iteration, find the first instance of delimeter char.
         *push preceding text into parsed vector and repeat algorithm on remaining
         *text.  only break the loop if delimeter char cannot be found. */
        index = text.find(c);
        if(index == string::npos){
            parsed.push_back(text);
            break;
        }else{
            temp = text.substr(0,index);
            parsed.push_back(temp);
            text = text.substr(index+1,text.length()+1);
        }
    }
    return parsed;
}
