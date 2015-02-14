#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <fstream>
#include "llistint.h"

using namespace std;

int main (int argc, char* argv[]){

    if (argc < 3){
        cout << "Error: Need both an input and output file given.\n";
        return 1;
    }

	ifstream input(argv[1]);
	if (input.fail() ){
		cout << "Unable to open input file: " << argv[1] << endl;
		return 1;
	}

	ofstream output(argv[2]);
	if (output.fail() ){
		cout << "Unable to open output file: " << argv[2] << endl;
		return 1;
	}

    int count_num_arg = 0;
    for (int i = 0; i < argc; i++){
    	count_num_arg++;
    }

    int page_num = 1;
    string word;
    bool hyphen_ = false;
    bool insertOK = true;
    map<string, LListInt> phrase;
    map<string, LListInt>::iterator it;

    while (input >> word){
    	LListInt l1;
    	it = phrase.begin();
      	int len = word.length();
        if (word == "<pagebreak>"){
        	page_num += 1;
        	insertOK = false;
        }
        if (ispunct(word[0]) != 0){
        	word.erase(0, 0);
        }
        if (ispunct(word[len - 1]) != 0){
        	word.erase(len - 1, 1);
        }
        len = word.length();
        for (int i = 0; i < len; i++){
            char certain = word.at(i);
        	if (ispunct(certain) != 0){
        		insertOK = false;
        		if (certain == '\''){
        			insertOK = true;
        		}
        		if (certain == '-'){
                    hyphen_= true;
                    while (word.find("-") != string::npos ) {
                    	string brokeword = word;
                    	int pos_hyphen = word.find("-");
                    	int wordlen = word.length() - 1;
                    	brokeword.erase(pos_hyphen, wordlen);

        				if(brokeword.length() > 2){
        					int m = 0;
                        	while (word[m]){
                				word[m] = tolower(word[m]);
                				m++;
                    		}
        					it = phrase.find(brokeword);
                			if (it == phrase.end()){
                				l1.push_back(page_num);
        						phrase.insert( pair<string, LListInt> (brokeword, l1) );
                			}
               				else {
                				phrase.erase(brokeword);
                				for (int i = 0; i < page_num; i++){
                					l1.push_back(i+1);
        	        			}
        					phrase.insert( pair<string, LListInt> (brokeword, l1) );	
            	    		}

		        		}
                        word.erase(0, pos_hyphen);
                    }

        		}
        	}
        }

        if (word == "<pagebreak>"){
        	insertOK = false;
        }

        if (insertOK == true && hyphen_ == false){
        	if(word.length() > 2){
        		int m = 0;
        		while (word[m]){
                	word[m] = tolower(word[m]);
                    m++;
                }
        		it = phrase.find(word);
                if (it == phrase.end()){
                	l1.push_back(page_num);
        			phrase.insert( pair<string, LListInt> (word, l1) );
                }

               else {
                	phrase.erase(word);
                	for (int i = 0; i < page_num; i++){
                		l1.push_back(i+1);
                	}
        			phrase.insert( pair<string, LListInt> (word, l1) );	
                }

        	}
        }
        insertOK = true;
        hyphen_ = false;
        l1.~LListInt();
    }

    for (int j = 3; j < count_num_arg; j++){
    	it = phrase.begin();
    	it = phrase.find(argv[j]);
    	if (it == phrase.end()){
    		output << "None" << endl;
    	}
    	else {
    		LListInt temp = it->second;
    		output << "{ ";
    		for (int k = 0; k < temp.size(); k++){
    			output << temp.get(k) << " ";
    		}
    		output << "}" << endl;
    	}
    }

    input.close();
    output.close();
    return 0;
}