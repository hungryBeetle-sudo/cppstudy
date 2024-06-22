class Node{
	public:
	Node(int value): nodeValue{value}, left{nullptr}, right{nullptr}{}
	int nodeValue;
	Node* left;
	Node* right;
	
	void addNode(int nodeValue){
		if(nodeValue < this->nodeValue){
			if(this->left == nullptr){ this->left = new Node(nodeValue); }
			else{ this->left->addNode(nodeValue); }
		}
		else{
			if(this->right == nullptr){ this->right = new Node(nodeValue); }
			else{ this->right->addNode(nodeValue); }
		}
	}
};

class Tree{
	Tree(int nodeValue): root{new Node(nodeValue)}{}
	public:
	Node* root;
};

int main(){
	return 0;
}
