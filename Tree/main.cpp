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

	void removeChildNode(int nodeValue){
		int diff = nodeValue - this->nodeValue;

		if(diff < 0){
			if(this->left == nullptr){ std::cout << nodeValue << " hasn't been found."; }
			else if(this->left->nodeValue == nodeValue){
				delete this->left;
				this->left = nullptr;
			}
			else{ this->left->removeChildNode(nodeValue); }
		}
		else if(diff > 0){
			if(this->right == nullptr){ std::cout << nodeValue << " hasn't been found."; }
			else if(this->right->nodeValue == nodeValue){
				delete this->right;
				this->right = nullptr;
			}
			else{ this->right->removeChildNode(nodeValue); }
		}

	}
};

class Tree{
	public:
	Tree(int nodeValue): root{new Node(nodeValue)}{}
	Node* root;

	Node* searchNode(int target){
		Node* current = this->root;
		bool finishSearch = false;

		while(!finishSearch){
			if(current->nodeValue == target){
				finishSearch = true;
			}
			else if(current->nodeValue < target && current->left != nullptr){
				current = current->left;
			}
			else if(current->nodeValue > target && current->right != nullptr){
				current = current->right;
			}
			else{
				finishSearch = true;
				current = nullptr;
			}
		}
		
		return current;
	}

	void addNode(int newValue){
		if(newValue < this->root->nodeValue) { this->root->left->addChildNode(newValue); }
		else if(newValue > this->root->nodeValue) { this->root->right->addChildNode(newValue); }
		else{ std::cout << newValue << " has already been added."; }
	}

	void removeNode(int removedValue){
		if(removedValue < this->root->nodeValue){ this->root->left->removeChildNode(removedValue); }
		else if(removedValue > this->root->nodeValue){ this->root->right->removeChildNode(removedValue); }
		else{
			delete this->root;
			this->root = nullptr;
		}
	}
};

int main(){
	return 0;
}
