

class Inventory {
// ... // no fly function is declared

};
class Consumables: public Inventory { public:
virtual void hasExpired();
// expiration date:
// ... 
};

class Clothes: public Inventory {
// ... // no fly function is declared
};
