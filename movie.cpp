#include "movie.h"
#include "util.h"
using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, 
 int qty, string genre, string rating) : Product(category, name, price, qty) {
    rating_ = rating;
    genre_ = genre;
}

std::set<std::string> Movie::keywords() const {
    set<string> set1;
    set1.insert("movie");
    set1.insert(convToLower(genre_));
    set<string> set2 = parseStringToWords(convToLower(name_));
    
    // ensures only words with 2+ letters are added for name
    for(set<string>::iterator it = set2.begin(); it != set2.end(); it++){
			if((*it).size() >= 2) set1.insert(*it);
		}

    return set1;
}

std::string Movie::displayString() const{
    return name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + 
			to_string(price_) + " " + to_string(qty_) + " left.";
}

void Movie::dump(ostream& os) const{
	Product::dump(os);
	os << genre_ << "\n" << rating_ << endl;
}