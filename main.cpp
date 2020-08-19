#include <iostream>

using namespace std;

class celula
{
private:
		string nome;
		char sexo;
		int idade;
		bool bebe ;
		celula *proxima;
public:
	celula()
	{
		proxima = NULL;
	}
	celula (string n, char s, int i, bool b, celula*p)
	{
		nome = n;
	   	sexo = s;
		idade = i;
		bebe = b;
		proxima =p;
	}
	string getNome()
	{
		return nome;
	}
	
	void setNome(string n)
	{
		nome = n;
	}
	
	char getSexo ()
	{
		return sexo;
	}
	
	void setSexo(char s)
	{
		sexo = s;
	}
	
	int getIdade()
	{
		return idade;
	}
	
	void setIdade (int i)
	{
		idade = i;
	}
	
	bool getBebe ()
	{
		return bebe;
	}
	
	void setBebe (bool b)
	{
		bebe = b;
	}
	
	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
};


class listachurrasco
{
private:
	celula * inicio;

public:
	listachurrasco()
	{
		inicio = NULL;
	}
	~listachurrasco(){
		esvaziar();
	}
	

	void inserirInicio(string n, char s, int i, bool b)
	{
		celula *nova = new celula(n,s,i,b,inicio);
		inicio = nova;
	}

	void inserirFim(string n, char s, int i, bool b)
	{
		if(inicio == NULL)
		{
			inserirInicio(n, s, i, b);
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			celula *nova = new celula();
			nova->setNome(n);
			nova->setIdade(i);
			nova->setSexo(s);
			nova->setBebe(b);
			nova->setProxima(NULL);
			aux->setProxima(nova); 
		}
	}


	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
			while(aux != NULL)
			{
				cout << aux->getNome() ;
				cout<< " - " << aux->getIdade() ;
				cout << " - " << aux->getSexo() ;
				cout << " - " ;
				aux->getBebe() ? cout << "Bebe " : cout << "Nao Bebe " ;
				cout << endl;
				aux = aux->getProxima();
			}
		}
	}
	
	void esvaziar(){
		celula *aux = inicio;
		while(aux != NULL){
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\n----Memoria liberada----\n";
	}
};

int main()
{
	listachurrasco presenca;
	presenca.inserirInicio("Sergio" , 'M', 23 , true );
	presenca.inserirFim("Alexandre" , 'M', 25 , false );
	presenca.inserirInicio("Andre" , 'M' , 24 , true );
	presenca.inserirFim("Mailson" , 'F' , 28 , true );
	presenca.imprimir();
	return 0;
}
