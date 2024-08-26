// Factory Design Pattern in C++
//Creational Pattern

#include<iostream>
// #include<string>


/*
The Product interface declares the operations that all concrete products must
implement.
*/


class product{
    public:
        virtual ~product() {}
        virtual std::string Operation() const = 0;

};



//Concrete Products provide various implementations of the Product interface.

class ConcreteProduct1: public product{
    public:
    std::string Operation() const override {
        return "{Result of Concrete Product 1}";
    }

};

class ConcreteProduct2: public product{
    public:
    std::string Operation() const override {
        return "Result of Concrete Product 2";
    }

};



/*
 * The Creator class declares the factory method that is supposed to return an
 * object of a Product class. The Creator's subclasses usually provide the
 * implementation of this method.
 */



class Creator {
    public:
        virtual ~Creator(){};
        virtual product* FactoryMethod() const = 0;


        std::string someOperation() const {

            product* product = this->FactoryMethod();
            std::string result = "Creator: " + product->Operation();
            delete product;
            return result;

        }

};


/*
 * Concrete Creators override the factory method in order to change the
 * resulting product's type.
 */


class concreteCreator1: public  Creator{
    public:
        product *FactoryMethod() const override {
            return new ConcreteProduct1();
        }


};


class concreteCreator2: public Creator{
    public:
        product *FactoryMethod() const override {
            return new ConcreteProduct2();
        }


};


/*
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */

void ClientCode(const Creator& Creator){
    std::cout<<"Client: I'm not aware of the creator's class, but it still works.\n"
             << Creator.someOperation() << std::endl;


}



/**
 * The Application picks a creator's type depending on the configuration or
 * environment.
 */



int main(){
    std::cout<<"App: Launched with the concreteCreator1. \n";
    Creator* creator = new concreteCreator1();
    ClientCode(*creator);
    std::cout<<std::endl;
    std::cout << "App: Launched with the ConcreteCreator2.\n";
    Creator* creator2 = new concreteCreator2();
    ClientCode(*creator2);

    delete creator;
    delete creator2;
    return 0;
}
