#include <iostream>

template<class TType> class UP {
public:
    UP(TType* aData) :mData{ aData } {};
    UP(const UP&) = delete;//
    //
    ~UP() {
        if (mData) {
            delete mData;
        }
    };//
    //
    void reset(TType* aData) {
        if (mData = aData) return;
        if (mData) delete mData;
        mData = aData;
    };//
    //
    TType* release() {
        TType* oldData = mData;
        mData = nullptr;
        return oldData;
    };//
    //
    
    TType& operator*() const {
        return *mData;
    };//
    //

private:
    UP &operator = (const UP& aOther) = delete;
    TType* mData{ nullptr };
};




struct Node {
    Node() { std::cout << "Node\n"; };
    ~Node() { std::cout << "~Node\n"; };
    void data() { std::cout << "HELLO\n"; };
    int dataNode{ 10 };
};

int main()
{
    UP<Node> ptrNode(new Node());
    (*ptrNode).data();
    std::cout << (*ptrNode).dataNode << std::endl;


}