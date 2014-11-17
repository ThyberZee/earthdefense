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

void createLevels() {
    ofstream lvl1("Level1");
    lvl1 << "score 0\n" \
            "enemy  101 -300 200 0\n" \
            "enemy  102  840 200 0\n" \
            "enemy  103  940 400 0\n" \
            "enemy  104 -400 300 0\n" \
            "enemy  105  740 50  0\n" \
            "enemy  106 -500 100 0\n";
    ofstream lvl2("Level2");
    lvl2 << "enemy  101 -300 200 0\n" \
            "enemy  102 840 200 0\n" \
            "enemy  103 940 200 0\n" \
            "enemy  104 740 400 0\n" \
            "trackingenemy 105 -100 100 0\n" \
            "trackingenemy 106 -200 200 0\n" \
            "trackingenemy 107 -300 30 0\n" \
            "trackingenemy 108 1040 40 0\n" \
            "trackingenemy 109 1240 150 0\n";
    ofstream lvl3("Level3");
    lvl3 << "enemy  101 -300  200 0\n" \
            "enemy  102  840  200 0\n" \
            "enemy  103  1040 200 0\n" \
            "enemy  104 -600  300 0\n" \
            "enemy  105  740  400 0\n" \
            "enemy  106 -1000 600 0\n" \
            "enemy  107 -1500 100 0\n" \
            "enemy  112 -1300 150 0\n" \
            "trackingenemy 108 1040 400 0\n" \
            "trackingenemy 110 -1340 100 0\n" \
            "trackingenemy 111 -400 -300 0\n" \
            "trackingenemy 109 1240 240 0\n";
    ofstream lvl4("Level4");
    lvl4 << "trackingenemy 108 1040 400 0\n" \
            "trackingenemy 110 1140 100 0\n" \
            "trackingenemy 111 400 -300 0\n" \
            "trackingenemy 109 1240 150 0\n" \
            "trackingenemy 105 -100 100 0\n" \
            "trackingenemy 106 -300 200 0\n" \
            "trackingenemy 107 -500 300 0\n" \
            "trackingenemy 112 -1040 400 0\n" \
            "trackingenemy 113 1240 150 0\n";
    lvl1.close();
    lvl2.close();
    lvl3.close();
    lvl4.close();
}

