#include "product.h"

class Book : public Product {
    //QUESTION: is this supposed to be protected or public?
    public:
        Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string author);
        virtual std::set<std::string> keywords() const;
        virtual std::string displayString() const;
        virtual void dump(std::ostream& os) const;
        //virtual bool isMatch(std::vector<std::string>& searchTerms) const;
    private:
        std::string ISBN_;
        std::string author_;
};