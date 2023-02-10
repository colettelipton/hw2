#include "util.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "product.h"
#include "mydatastore.h"
#include "user.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

int main(){
	// is the last word supposed to include the period?
	/* string s = "hi i am-a.person.";
	set<string> test = parseStringToWords(s);
	for(set<string>::iterator it = test.begin(); it != test.end(); it++){
		//cout << *it << endl;
	}

	set<string> test2 = parseStringToWords("hi i am not");
	set<string> test3 = setUnion(test,test2);

	for(set<string>::iterator it = test3.begin(); it != test3.end(); it++){
		//cout << *it << endl;
	}

	Book b("book", "the great gatsby", 5.00, 20, "100-100", "F. Scott Fitzgerald");
	//cout << b.displayString() << endl;

	set<std::string> test4 = b.keywords();
	for(set<string>::iterator it = test4.begin(); it != test4.end(); it++){
		cout << *it << endl;
	} */
	Book b("book", "the great gatsby", 5.00, 20, "100-100", "F. Scott Fitzgerald");
	Movie m("movie", "Shrek", 4.00, 30, "comedy", "G");
	MyDataStore data;
	data.addProduct(&b);
	data.addProduct(&m);

	

	for(map<string, set<Product*>>::iterator it = data.keys.begin(); it != data.keys.end(); it++){
		for(set<Product*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
			cout << (*it2)->getName() << endl;
		}
	}
//std::map<std::string, std::vector<Product*>> carts;
//std::map<std::string, set<Product*>> keys;

	return 0;
}