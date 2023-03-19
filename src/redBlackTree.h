#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "trees.h"

#define BLACK false
#define RED true

namespace Trees {

    template <typename T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

//red black tree
    template <std::totally_ordered T>
    class RedBlackTree : public Tree<T> {
    private:
        Node<T> *root;
        
        Node<T>* BSTInsert(Node<T>*& r, Node<T>*& value) {
            if(r == nullptr) {
                return value;
            } else if(value->value < r->value) {
                r->left = BSTInsert(r->left, value);
                r->left->parent = r;
            } else if (value->value > r->value) {
                r->right = BSTInsert(r->right, value);
                r->right->parent = r;
            }

            return r;
        }

        Node<T>* BSTDelete(Node<T>*& r, const T& value) {
			if (!r) {
				return nullptr;
			}

			if (value < r->value) {
				r->left = BSTDelete(r->left, value);
				if (r->left) {
				    r->left->parent = r;
				}
			} else if (value > r->value) {
				r->right = BSTDelete(r->right, value);
				if (r->right) {
				    r->right->parent = r;
				}
			} else {
				if (r->left == nullptr) {
				    Node<T>* right = r->right;
				    delete r;
				    return right;
				} else if (r->right == nullptr) {
				    Node<T>* left = r->left;
				    delete r;
				    return left;
				} else {
				    Node<T>* minRightNode = minNode(r->right);
				    r->value = minRightNode->value;
				    r->right = BSTDelete(r->right, minRightNode->value);
				    if (r->right) {
				        r->right->parent = r;
				    }
				}
			}

			return r;
		}

        Node<T>* minNode(Node<T>* r) {
            while(r->left != nullptr) {
                r = r->left;
            }

            return r;
        }

        void fixDelete(Node<T>* node) {
			while (node != root && node->color == BLACK) {
				if (node == node->parent->left) {
				    Node<T>* sibling = node->parent->right;
				    if (sibling->color == RED) {
				        sibling->color = BLACK;
				        node->parent->color = RED;
				        rotateLeft(node->parent);
				        sibling = node->parent->right;
				    }
				    if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
				        sibling->color = RED;
				        node = node->parent;
				    } else {
				        if (sibling->right->color == BLACK) {
				            sibling->left->color = BLACK;
				            sibling->color = RED;
				            rotateRight(sibling);
				            sibling = node->parent->right;
				        }
				        sibling->color = node->parent->color;
				        node->parent->color = BLACK;
				        sibling->right->color = BLACK;
				        rotateLeft(node->parent);
				        node = root;
				    }
				} else {
				    Node<T>* sibling = node->parent->left;
				    if (sibling->color == RED) {
				        sibling->color = BLACK;
				        node->parent->color = RED;
				        rotateRight(node->parent);
				        sibling = node->parent->left;
				    }
				    if (sibling->right->color == BLACK && sibling->left->color == BLACK) {
				        sibling->color = RED;
				        node = node->parent;
				    } else {
				        if (sibling->left->color == BLACK) {
				            sibling->right->color = BLACK;
				            sibling->color = RED;
				            rotateLeft(sibling);
				            sibling = node->parent->left;
				        }
				        sibling->color = node->parent->color;
				        node->parent->color = BLACK;
				        sibling->left->color = BLACK;
				        rotateRight(node->parent);
				        node = root;
				    }
				}
			}
			node->color = BLACK;
		}

        void fixInsert(Node<T>*& node) {
            Node<T>* parent = nullptr;
            Node<T>* gparent = nullptr;

            while(node != root && node->color == RED && node->parent->color == RED) {
                parent = node->parent;
                gparent = parent->parent;
                if(parent == gparent->left) {
                    Node<T>* uncle = gparent->right;
                    if(uncle->color == RED) {
                        uncle->color = BLACK;
                        parent->color = BLACK;
                        gparent->color = RED;
                        node = gparent;
                    } else {
                        if(node == parent->right) {
                            rotateLeft(parent);
                            node = parent;
                            parent = node->parent;
                        }
                        rotateRight(gparent);
                        swap(parent->color, gparent->color);
                        node = parent;
                    }
                } else {
                    Node<T>* uncle = gparent->left;
                    if(uncle->color == RED) {
                        uncle->color = BLACK;
                        parent->color = BLACK;
                        gparent->color = RED;
                        node = gparent;
                    } else {
                        if (node == parent->left) {
                            rotateRight(parent);
                            node = parent;
                            parent = node->parent;
                        }
                        rotateLeft(gparent);
                        swap(parent->color, gparent->color);
                        node = parent;
                    }
                }
            }

            root->color = BLACK;
        }

        void rotateLeft(Node<T>*& node) {
			Node<T>* right = node->right;
			node->right = right->left;
			if (right->left != nullptr) {
				right->left->parent = node;
			}
			right->parent = node->parent;
			if (node->parent == nullptr) {
				root = right;
			} else if (node == node->parent->left) {
				node->parent->left = right;
			} else {
				node->parent->right = right;
			}
			right->left = node;
			node->parent = right;
		}

        void rotateRight(Node<T>*& node) {
			Node<T>* left = node->left;
			node->left = left->right;
			if (left->right != nullptr) {
				left->right->parent = node;
			}
			left->parent = node->parent;
			if (node->parent == nullptr) {
				root = left;
			} else if (node == node->parent->left) {
				node->parent->left = left;
			} else {
				node->parent->right = left;
			}
			left->right = node;
			node->parent = left;
		}

        public:
            RedBlackTree() : root(nullptr) {}
            ~RedBlackTree(){
                Tree<T>::clear(root);
            }

            //returns true if the tree contains value
        bool contains(const T& value) const override {
            Node<T>* current = root;
            while(current != nullptr) {
                if (value == current->value) {
                    return true;
                } else if (value < current->value) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }

            return false;
        }

        //inserts value into the tree
        void insert(const T& value) override{
            Node<T>* node = new Node(value);
            root = BSTInsert(root, node);
            fixInsert(node);
        }

        void remove(const T& value) override {
            Node<T>* node = BSTDelete(root, value);
            if(node != nullptr) {
            	fixDelete(node);
            	delete node;
            	node = nullptr;
            }
        }

        void printTree() const {
            Tree<T>::print(root, 4);
        }

        void clearTree() {
            Tree<T>::clear(root);
        }
    };
}


#endif
