#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    string nome;
    int altura;
    Node* left;
    Node* right;

    Node(string n, int h) : nome(n), altura(h), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Função recursiva para inserir um novo nó ou atualizar altura
    Node* insert(Node* node, string nome, int altura) {
        if (node == nullptr) {
            return new Node(nome, altura);
        }

        if (nome < node->nome) {
            node->left = insert(node->left, nome, altura);
        } else if (nome > node->nome) {
            node->right = insert(node->right, nome, altura);
        } else {
            // Caso o nome já exista, atualiza a altura
            node->altura = altura;
        }
        return node;
    }

    // Função recursiva para buscar a altura de uma pessoa
    Node* search(Node* node, string nome) {
        if (node == nullptr || node->nome == nome) {
            return node;
        }

        if (nome < node->nome) {
            return search(node->left, nome);
        }
        return search(node->right, nome);
    }

    // Função recursiva para encontrar a maior altura
    int findMaxHeight(Node* node) {
        if (node == nullptr) {
            return -1; // Caso a árvore esteja vazia
        }
        while (node->right != nullptr) {
            node = node->right;
        }
        return node->altura;
    }

    // Função recursiva para listar as pessoas em ordem alfabética
    void list(Node* node) {
        if (node == nullptr) return;
        list(node->left);
        cout << node->nome << ": " << node->altura << " cm" << endl;
        list(node->right);
    }

public:
    BST() : root(nullptr) {}

    // Função pública para inserir um novo registro ou atualizar a altura
    void insert(string nome, int altura) {
        root = insert(root, nome, altura);
    }

    // Função pública para buscar a altura de uma pessoa
    void search(string nome) {
        Node* result = search(root, nome);
        if (result) {
            cout << "Altura de " << nome << ": " << result->altura << " cm" << endl;
        } else {
            cout << nome << " nao encontrado" << endl;
        }
    }

    // Função pública para encontrar a maior altura registrada
    void findMaxHeight() {
        int maxHeight = findMaxHeight(root);
        if (maxHeight != -1) {
            cout << "Maior altura registrada: " << maxHeight << " cm" << endl;
        } else {
            cout << "Nao ha registros" << endl;
        }
    }

    // Função pública para listar os registros em ordem alfabética
    void list() {
        list(root);
    }
};

int main() {
    BST tree;
    string command;
    while (true) {
        getline(cin, command);
        
        if (command == "FIM") {
            break;
        } else if (command.substr(0, 7) == "INSERIR") {
            size_t pos = command.find(" ");
            string nome = command.substr(8, pos - 8);
            int altura = stoi(command.substr(pos + 1));
            tree.insert(nome, altura);
        } else if (command.substr(0, 6) == "BUSCAR") {
            string nome = command.substr(7);
            tree.search(nome);
        } else if (command == "MAIOR") {
            tree.findMaxHeight();
        } else if (command == "LISTAR") {
            tree.list();
        } else {
            cout << "Comando invalido" << endl;
        }
    }

    return 0;
}
