#pragma once

namespace Listas {
	
	template<class TL>
	class Lista 
	{
		public:
			Lista() : pPrim(NULL), pUlt(NULL), tam(0) {}
			~Lista() { limpar(); }
			template <class TE>
			class Elemento {

				private:
					Elemento<TE>* pProx;
					TE* pinfo;
				public:
					Elemento() :pProx(NULL), pinfo(NULL) {}
					~Elemento() { }
					void setProx(Elemento<TE>* pE)
					{
						pProx = pE;
					}
					Elemento<TE>* getProx() const { return pProx; }
					void setInfo(TE* pi)
					{
						if (pi)
						{
							pinfo = pi;
						}

					}
					TE* getInfo() const { return pinfo; }
			};
            template <class TE>
            class Iterator
            {
                private:
                    Elemento<TE>* atual;
                public:
                    Iterator(Elemento<TE>* pa = NULL) : atual(pa) {}
                    ~Iterator() {}
					Iterator& operator++()
					{
						atual = atual->getProx();
						return *this;
					}
                    bool operator==(const Elemento<TE>* pe) const
                    {
                        return atual == pe;
                    }
                    bool operator!=(const Elemento<TE>* pe) const
                    {
                        return !(atual == pe);
                    }
					bool operator==(const Iterator<TE>& outro) const {
						return atual == outro.atual;
					}
					bool operator!=(const Iterator<TE>& outro) const {
						return atual != outro.atual;
					}
                    void operator=(Elemento<TE>* pe)
                    {
						atual = pe;
                    }
					Elemento<TE>* getAtual() const
					{
						return atual;
					}
					TE* operator*() const
					{
						return atual->getInfo();
					}
            };
			private:
				Elemento<TL>* pPrim;
				Elemento<TL>* pUlt;
				int tam;
			public:
				void incluir(TL* pElem)
				{
					if (pElem)
					{
						Elemento<TL>* aux = new Elemento<TL>();
						if (aux)
						{
							aux->setInfo(pElem);
							if (!pPrim)
							{
								pPrim = aux;
								pUlt = pPrim;
								tam++;
							}
							else
							{
								pUlt->setProx(aux);
								pUlt = aux;
								tam++;

							}

						}
					}
					else { return; }
				}
				void remover(TL* pElem) {
					if (!pElem || !pPrim) return;

					Elemento<TL>* aux = pPrim;
					Elemento<TL>* ant = NULL;

					while (aux != NULL && aux->getInfo() != pElem) {
						ant = aux;
						aux = aux->getProx();
					}

					if (aux == NULL) return;


					if (aux == pPrim) {
						pPrim = aux->getProx();
					}
					else {

						ant->setProx(aux->getProx());
					}

					if (aux == pUlt) {
						pUlt = ant;
					}

					tam--;
					delete aux;
				}
				void limpar()
				{
					Elemento<TL>* aux = NULL;
					while (pPrim)
					{
						aux = pPrim;
						pPrim = pPrim->getProx();
						if (aux->getInfo() != NULL) {
							delete aux->getInfo();
						}

						delete aux;

					}
					tam = 0;
					pPrim = NULL;
					pUlt = NULL;
				}
				void inicializa() 
				{
					pPrim = NULL;
					pUlt = NULL;
					tam = 0;
				}
				Iterator<TL> begin() {

					return Iterator<TL>(pPrim);
				}
				Iterator<TL> end() {

					if (pUlt) {
						return Iterator<TL>(pUlt->getProx());
					}
					else { return Iterator<TL>(NULL); }
				}
				Elemento<TL>* getPrim()
				{

					return pPrim;
				}
	};

}