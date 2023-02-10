#include "book.h"
#include "util.h"
using namespace std;

Book::Book(const std::string category, const std::string name, double price, 
  int qty, string ISBN, string author) : Product(category, name, price, qty) {
    ISBN_ = ISBN;
    author_ = author;
}

std::set<std::string> Book::keywords() const {SBN_);
    // QUESTION: is the type a keyword?> set2 = parseStringToWords(convToLower(author_));
    set<string> set3 = parseStringToWords(convToLower(name_));
    
    // ensures only words with 2+ letters are added
    for(set<string>::iterator it = set2.begin(); it != set2.end(); it++){
		if((*it).size() >= 2) set1.insert(*it);
	}
    
    // ensures only words with 2+ letters are added
    for(set<string>::iterator it = set3.begin(); it != set3.end(); it++){
		if((*it).size() >= 2) set1.insert(*it);
	}

    //set<string> set4 = setUnion(set1, set2);
    return set1;
}

std::string Book::displayString() const{
    return name_ + "\nAuthor: " + author_ + " ISBN: " + ISBN_ + "\n" + 
			to_string(price_) + " " + to_string(qty_) + " left.";
}

void Book::dump(ostream& os) const{
	Product::dump(os);
	os << ISBN_ << "\n" << author_ << endl;
}