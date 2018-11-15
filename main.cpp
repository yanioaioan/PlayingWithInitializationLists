#include <iostream>
#include <memory>

using namespace std;

struct A
{
    int x;
    int y;
    int z;
};



class B
{
    public:
        int x;
        int y;
        int z;
        
        B(int n,int d, int e): x(n),y(2),z(4)  {}
};

struct C
{
    std::shared_ptr<A> m_a;
    explicit C(std::shared_ptr<A> _a) : m_a(_a) {cout<<" inited shared ptr m_a " << m_a->x <<'\n';}
};

int main() {
	
	struct A a={11,22,33};
	B b(1,2,3);
	
	
	//struct A *pointerAStruct=&a;
	
	C c( make_shared<A>(a) );
	C c1{ make_shared<A>(a) };
	
	
	/*
	13.3.1.7 Initialization by list-initialization [over.match.list]
When objects of non-aggregate class type T are list-initialized (8.5.4), overload resolution selects the constructor in two phases:

— Initially, the candidate functions are the initializer-list constructors (8.5.4) of the class T and the argument list consists of the initializer list as a single argument.

— If no viable initializer-list constructor is found, overload resolution is performed again, where the candidate functions are all the constructors of the class T and the argument list consists of the elements of the initializer list.

If the initializer list has no elements and T has a default constructor, the first phase is omitted. In copy-list-initialization, if an explicit constructor is chosen, the initialization is ill-formed. [ Note: This differs from other situations (13.3.1.3, 13.3.1.4), where only converting constructors are considered for copy-initialization. This restriction only applies if this initialization is part of the final result of overload resolution. — end note ].
	*/
	// The following line is ill-formed per standard,as long as the C constrcutor is made explicit. 11/2018/c++14
	C c2 =  { std::make_shared<A>(a) } ;
	
	//cout<<" = \n" << a.x;
	//cout<<" = " << b.x;
}

