#include "mydatastore.h"
#include "user.h"
#include "datastore.h"
using namespace std;

MyDataStore::MyDataStore(){ }

MyDataStore::~MyDataStore(){
	// deletes all the products
	for(set<Product*>::iterator i = products.begin(); i != products.end(); i++){
		delete *i;
	}

	// deletes all the users
	for(map<string, User*>::iterator it = users.begin(); it != users.end(); it++){
		delete it->second;
	}
}

void MyDataStore::addProduct(Product* p){
	products.insert(p);
	set<string> words = p->keywords();

	for(set<string>::iterator it = words.begin(); it != words.end(); it++){
		if(keys.find(*it) != keys.end()){
			keys.find(*it)->second.insert(p);
		}
		else{
			set<Product*> newset;
			newset.insert(p);
			keys.insert(make_pair(*it, newset));
		}
	}
}

void MyDataStore::addUser(User* u){
	cout << u->getName() << endl;
	users.insert(make_pair(u->getName(), u));
	vector<Product*> cart;
	carts.insert(make_pair(u->getName(), cart));
}

/**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
	set<Product*> hits;
	vector<Product*> results;
	bool first = true;
	// associated with that term, keep iterating
	for(unsigned i = 0; i < terms.size(); i++){
		// if it finds it, then do stuff
		if(keys.find(terms[i]) != keys.end()){
			// returns the set of products that this string maps to
			set<Product*> matches = keys.find(terms[i])->second;
			if(first){
				hits = matches;
				first = false;
			}
			else{
				if(type == 0){
					hits = setIntersection(matches, hits);
				}
				if(type == 1){
					hits = setUnion(matches, hits);
				}
			}
		}
	}
	
	for(set<Product*>::iterator it = hits.begin(); it != hits.end(); it++){
		results.push_back(*it);
	}

	return results;

}

bool MyDataStore::addToCart(string user, Product* p){
	if(users.find(user) != users.end()){
		// User* u = users.find(user)->second;
		// check that the user is valid and that the product exists
		// if yes, add the product to their cart
		carts.find(user)->second.push_back(p);
		return true;
	}
	// if no, print "invalid username"
	return false;
}

void MyDataStore::buyCart(string user){
	if(users.find(user) != users.end()){
		User* u = users.find(user)->second;
		// check that the user is valid
		if(users.find(u->getName()) != users.end()){
			vector<Product*>& c = carts.find(u->getName())->second;
			for(unsigned i = 0; i < c.size(); i++){
				if(u->getBalance() >= c.front()->getPrice() && c.front()->getQty() >= 1){
					c[i]->subtractQty(1);
					u->deductAmount(c.front()->getPrice());
					c.erase(c.begin() + i);
					i--;
				} else {
					// if the user doesn't have enough money, continues
					continue;
				}
			}
		}
	}

	// QUESTION: do i need this?
	else cout << "invalid username" << endl;
	// check that the user has enough money to buy their cart
	// remove items from cart
	// update quantity
	// if they're out of money, break the loop
}

void MyDataStore::viewCart(string user){
	if(users.find(user) != users.end()){
		// call displayString for each product in the User's cart
		for(unsigned i = 0; i < carts.find(user)->second.size(); i++){
			cout << "item " << i + 1 << endl;
			cout << carts.find(user)->second[i]->displayString() << endl;
		}
	}
	else cout << "invalid username" << endl;
}

void MyDataStore::dump(std::ostream& ofile){
	ofile << "<products>" << endl;
	for(set<Product*>::iterator i = products.begin(); i != products.end(); i++){
		(*i)->dump(ofile);
	}
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
	for(map<string, User*>::iterator it = users.begin(); it != users.end(); it++){
		it->second->dump(ofile);
	}
	ofile << "</users>" << endl;
}