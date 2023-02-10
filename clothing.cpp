#include "clothing.h"
#include "util.h"
using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double 
 price, int qty, string size, string brand) : Product(category, name, price, qty) {
    size_ = size;
    brand_ = brand;
}

std::set<std::string> Clothing::keywords() const {
    set<string> set1;
    set1.insert("clothing");
    set<string> set2 = parseStringToWords(convToLower(brand_));
    set<string> set3 = parseStringToWords(convToLower(name_));
    
    // ensures only words with 2+ letters are added
    for(set<string>::iterator it = set2.begin(); it != set2.end(); it++){
			if((*it).size() >= 2) set1.insert(*it);
		}
    
    // ensures only words with 2+ letters are added
    for(set<string>::iterator it = set3.begin(); it != set3.end(); it++){
			if((*it).size() >= 2) set1.insert(*it);
		}

    return set1;
}

std::string Clothing::displayString() const{
    return name_ + "\nSize: " + size_ + " Brand: " + brand_ + "\n" + 
			to_string(price_) + " " + to_string(qty_) + " left.";
}

void Clothing::dump(ostream& os) const{
	Product::dump(os);
	os << size_ << "\n" << brand_ << endl;
}