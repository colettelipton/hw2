#include "datastore.h"
#include "user.h"
#include <queue>

class MyDataStore : public DataStore {
public:
	// QUESTION: are these virtual? also constructor? destructor?
	MyDataStore();
	~MyDataStore();
	void addProduct(Product* p);
	void addUser(User* u);
	std::vector<Product*> search(std::vector<std::string>& terms, int type);
	bool addToCart(std::string u, Product* p);
	void buyCart(std::string u);
	void viewCart(std::string u);
	void dump(std::ostream& ofile);

// change back
private:
	std::map<std::string, User*> users;
	std::set<Product*> products;
	// the string for the keys are the users
	std::map<std::string, std::vector<Product*>> carts;
	std::map<std::string, std::set<Product*>> keys;
};