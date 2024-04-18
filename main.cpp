#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

struct Funcionario {
	int prontuario;
	string nome;
	double salario;
	Funcionario *prox;
};

Funcionario* init() {
	return NULL;
}

bool isEmpty(Funcionario* lista) {
	return (lista == NULL);
}

Funcionario* insert(Funcionario* lista, int prontuario, string nome, double salario) {
	Funcionario* novo = new Funcionario();
	novo->prontuario = prontuario;
	novo->nome = nome;
	novo->salario = salario;
	novo->prox = lista;
	return novo;
};

void printLista(Funcionario* lista) {
	Funcionario* aux;
	string line(20, '-');
	aux = lista;
	double totalSalarios = 0;
	if (isEmpty(lista)) {
		cout << "Lista vazia." << endl;
	} else {
		cout << "Lista de funcionários: \n" << endl;
		cout << line << endl;
		while (aux != NULL) {
			cout << "Prontuário: " << aux->prontuario << endl;
			cout << "Nome: " << aux->nome << endl;
			cout << "Salário: " << aux->salario << endl;
			cout << line << endl;
			totalSalarios = totalSalarios + aux->salario;
			aux = aux->prox;
		}
		cout << "\nTotal de salários: " << totalSalarios << endl;
		cout << "\nFim da lista." << endl;
	}
}

void printFuncionario(Funcionario* lista, int prontuario) {
	Funcionario* aux;
	aux = lista;
	while (aux != NULL && aux->prontuario != prontuario) {
		aux = aux->prox;
	}
	if (aux) {
		cout << "\nFuncionário encontrado: " << endl;
		cout << endl;
		cout << "Prontuário: " << aux->prontuario << endl;
		cout << "Nome: " << aux->nome << endl;
		cout << "Salário: " << aux->salario << endl;
	} else {
		cout << "\nFuncionário não encontrado." << endl;
	}
}

Funcionario* find(Funcionario* lista, int prontuario) {
	Funcionario* aux;
	aux = lista;
	while (aux != NULL && aux->prontuario != prontuario) {
		aux = aux->prox;
	}
	return aux;
}

Funcionario* remove(Funcionario* lista, int prontuario) {
	Funcionario* aux;
	Funcionario* ant = NULL;
	aux = lista;

	while (aux != NULL && aux->prontuario != prontuario) {
		ant = aux;
		aux = aux->prox;
	}

	if (aux == NULL) {
		return lista;
	}

	if (ant == NULL) {
		lista = aux->prox;
	}

	else {
		ant->prox = aux->prox;
	}

	free(aux);
	return lista;
}

void freeLista(Funcionario* lista) {
	Funcionario* aux;
	aux = lista;
	while (aux != NULL) {
		Funcionario *ant = aux->prox;
		free(aux);
		aux = ant;
	}	
}

int main() {
	setlocale(LC_ALL, "");
	
  	Funcionario *listaFuncionarios;
	listaFuncionarios = init();
	int prontuario;
	string nome;
	double salario;
  	int opcao;
  
  	do {
		string line(40, '-');
		cout << "0. Sair\n";
		cout << "1. Incluir\n";
		cout << "2. Excluir\n";
		cout << "3. Pesquisar\n";
		cout << "4. Listar\n";
		cout << "Opção: ";
		cin >> opcao;

    		switch (opcao) {
			case 0:
				cout << line << endl;
				cout << "Encerrando programa...\n";
				break;
			
			case 1:
				cout << line << endl;
        			cout << "Digite o prontuario: ";
				cin >> prontuario;
				if (find(listaFuncionarios, prontuario)) {
					cout << "Funcionário já cadastrado!\n";
					cout << line << endl;
					break;
				}
				cout << "Digite o nome: ";
				cin >> nome;
        			cout << "Digite o salario: ";
				cin >> salario;
				listaFuncionarios = insert(listaFuncionarios, prontuario, nome, salario);
        			cout << "Funcionário cadastrado com sucesso!" << endl;
				cout << line << endl;
			break;

			case 2:
				cout << line << endl;
				cout << "Digite o prontuário do funcionário a ser excluído: ";
				cin >> prontuario;
				listaFuncionarios = remove(listaFuncionarios, prontuario);
				cout << "Funcionário excluído com sucesso!" << endl;
				cout << line << endl;
			break;
			
			case 3:
				cout << line << endl;
				cout << "Digite o prontuário do funcionário a ser pesquisado: ";
				cin >> prontuario;
				printFuncionario(listaFuncionarios, prontuario);
				cout << line << endl;
			break;

			case 4:
				cout << line << endl;
				printLista(listaFuncionarios);
				cout << line << endl;
		}  	
  } while (opcao != 0);

	freeLista(listaFuncionarios);

	return 0;
}
