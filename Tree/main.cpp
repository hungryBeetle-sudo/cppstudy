#include <iostream>

class Node{
	public:
	Node(int value): nodeValue{value}, left{nullptr}, right{nullptr}{}
	int nodeValue;
	Node* left;
	Node* right;
	
	void addChildNode(int nodeValue){
		int diff = nodeValue - this->nodeValue;

		if(diff < 0){ 
			if(this->left == nullptr){ this->left = new Node(nodeValue); }
			else{ this->left->addChildNode(nodeValue); }
		}
		else if(diff > 0){ 
			if(this->right == nullptr){ this->right = new Node(nodeValue); }
			else{ this->right->addChildNode(nodeValue); }
		}
		else{ std::cout << nodeValue << " has already been added."; }
	}
};

class Tree{
	public:
	Tree(int nodeValue): root{new Node(nodeValue)}{}
	Node* root;

	void addNode(int newValue){
		if(newValue < this->root->nodeValue) { this->root->left->addChildNode(newValue); }
		else if(newValue > this->root->nodeValue) { this->root->right->addChildNode(newValue); }
		else{ std::cout << newValue << " has already been added."; }
	}
};

int main(){
	return 0;
}
