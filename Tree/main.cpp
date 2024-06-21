class Node{
	Node(int value): nodeValue{value}, left{nullptr}, right{nullptr}{}
	public:
	int nodeValue;
	Node* left;
	Node* right;

};

class Tree{
	Tree(): root{nullptr}{}
	public:
	Node* root;
};

int main(){
	return 0;
}
