#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "trees.h"

namespace Trees {

    template <typename T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    template <std::totally_ordered T>
    class RedBlackTree : public Tree<T> {
    private:
        Node<T> *root = nullptr;

        //void insertHelper(Node<T>* node) {
        
        //}

        void fixInsert(Node<T>*& node) {
            Node<T>* parent = nullptr;
            Node<T>* gparent = nullptr;

            while(node != root && node->color == RED && node->parent->color == RED) {
                parent = node->parent;
                gparent = parent->parent;
                if(parent == gparent->left) {
                    Node<T>* uncle = gparent->right;
                    if(uncle != nullptr && uncle->color == RED) {
                        uncle->color = BLACK;
                        parent->color = BLACK;
                        gparent->color = RED;
                        node = gparent;
                    } else {
                        if(node == parent->right) {
                            leftRotate(parent);
                            node = parent;
                            parent = node->parent;
                        }
                        rightRotate(gparent);
                        swap(parent->color, gparent->color);
                        node = parent;
                    }
                } else {
                    Node<T>* uncle = gparent->left;
                    if(uncle != nullptr && uncle->color == RED) {
                        uncle->color = BLACK;
                        parent->color = BLACK;
                        gparent->color = RED;
                        node = gparent;
                    } else {
                        if (node == parent->left) {
                            rightRotate(parent);
                            node = parent;
                            parent = node->parent;
                        }
                        leftRotate(gparent);
                        swap(parent->color, gparent->color);
                        node = parent;
                    }
                }
            }

            root->color = BLACK;
        
        }

        void removeHelper(Node<T>* node) {
            Node<T>* u = replaceBST(node);

            bool bothBlack = ((u == nullptr || u->color == BLACK) && (node->color == BLACK));
            Node<T>* parent = node->parent;

            if (u == nullptr) {
                if (node == root) {
                    root = nullptr;
                } else {
                    if (bothBlack) {
                        fixDoubleBlack(node);
                    } else {
                        if (node->getSibling() != nullptr)
                            node->getSibling()->color = RED;
                    }

                    if (node == node->parent->left) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                }

                delete node;
                node = nullptr;
                return;
            }

            if (node->left == nullptr || node->right == nullptr) {
                if (node == root) {
                    node->value = u->value;
                    node->left = nullptr;
                    node->right = nullptr;
                    delete u;
                    u = nullptr;
                } else {
                    if (node == node->parent->left) {
                        parent->left = u;
                    } else {
                        parent->right = u;
                    }

                    delete node;
                    node = nullptr;
                    u->parent = parent;

                    if(bothBlack) {
                        fixDoubleBlack(u);
                    } else {
                        u->color = BLACK;
                    }
                }
                
                return;
            }

            swap(node->value, u->value);
            removeHelper(u);
        }


        void leftRotate(Node<T>*& node) {
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

        void rightRotate(Node<T>*& node) {
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


/*        
        void leftRotate(Node<T>* node) {
            Node<T>* newParent = node->right;
            if(node == root)
                root = newParent;

            node->moveDown(newParent);

            node->right = newParent->left;

            if(newParent->left != nullptr)
                newParent->left->parent = node;

            newParent->left = node;
        }
       
        void rightRotate(Node<T>* node) {
            Node<T>* newParent = node->right;
            if(node == root)
                root = newParent;

            node->moveDown(newParent);

            node->left = newParent->right;

            if(newParent->right != nullptr)
                newParent->right->parent = node;

            newParent->right = node;
        }
*/
        void fixDoubleRed(Node<T>* node) {
            if(node == root){
                node->color = BLACK;
                return;
            }

            Node<T>* parent = node->parent;
            Node<T>* gparent = node->parent->parent;
            Node<T>* uncle = node->getUncle();

            if(parent->color != BLACK) {
                if(uncle == nullptr || uncle->color == BLACK) {
                    if(gparent != nullptr && parent == parent->parent->left) {
                        if(node == node->parent->left) {
                            swap(parent->color, gparent->color);
                        } else {
                            leftRotate(parent);
                            swap(node->color, gparent->color);
                        }
                        
                        rightRotate(gparent);
                    } else {
                        if(node == node->parent->left) {
                            rightRotate(parent);
                            swap(node->color, gparent->color);
                        } else {
                            swap(parent->color, gparent->color);
                        }

                        leftRotate(gparent);
                    }
                }
            }
        }

        Node<T>* successor(Node<T>* node) {
            Node<T>* temp = node;

            while(temp->left != nullptr)
                temp = temp->left;

            return temp;
        }

        void fixDoubleBlack(Node<T>* node) {
            if(node == root)
                return;

            Node<T>* sibling = node->getSibling();
            Node<T>* parent = node->parent;

            if(sibling == nullptr) {
                fixDoubleBlack(parent);
            } else {
                if(sibling->color == RED){
                    parent->color = RED;
                    sibling->color = BLACK;
                    if (sibling == sibling->parent->left){
                        rightRotate(parent);
                    } else {
                        leftRotate(parent);
                    }
                    fixDoubleBlack(node);
                } else {
                    if (sibling->hasRedChild()) {
                        if (sibling->left != nullptr && sibling->left->color == RED) {
                            if (sibling == sibling->parent->left) {
                                sibling->left->color = sibling->color;
                                sibling->color = parent->color;
                                rightRotate(parent);
                            } else {
                                sibling->left->color = parent->color;
                                rightRotate(sibling);
                                leftRotate(parent);
                            }
                        } else {
                            if (sibling == sibling->parent->left) {
                                sibling->right->color = parent->color;
                                leftRotate(sibling);
                                rightRotate(parent);
                            } else {
                                sibling->right->color = sibling->color;
                                sibling->color = parent->color;
                                leftRotate(parent);
                            }
                        }
                        parent->color = BLACK;
                    } else {
                        sibling->color = RED;
                        if(parent->color == BLACK)
                            fixDoubleBlack(parent);
                        else
                            parent->color = BLACK;
                    }
                }
            }
        }

        Node<T>* replaceBST(Node<T>* node) {
            if (node->left == nullptr && node->right == nullptr)
                return nullptr;

            if (node->left != nullptr && node->right != nullptr)
                return successor(node->right);

            if (node->right != nullptr)
                return node->right;
            
            return node->left;
        }

        Node<T>* search(const T& value) const {
            Node<T>* temp = root;

            while (temp != nullptr) {
                if (value < temp->value) {
                    if (temp->left == nullptr)
                        break;
                    
                    temp = temp->left;
                } else if (value == temp->value) {
                    break;
                } else {
                    if (temp->right == nullptr)
                        break;
                    
                    temp = temp->right;
                }
            }

            return temp;
        }

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

    public:
        
        bool contains(const T& value) const override {
            if (root == nullptr)
                return false;

            Node<T>* v = search(value);
            return (v->value == value);
        }
        
        void insert(const T& value) override {
            Node<T>* node = new Node(value);
            root = BSTInsert(root, node);
            fixInsert(node);
        }

        void remove(const T& value) override {
            if(root == nullptr)
                return;

            Node<T>* v = search(value);
            if(v->value != value) 
                return;
            
            removeHelper(v);
        }

        void printTree() {
            Tree<T>::print(root, 4);
        }

        ptrdiff_t getHeight() const {
            return Tree<T>::height(root);
        }

        void clearTree() {
            Tree<T>::clear(root);
        }

    };
}













#endif
