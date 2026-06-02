#include "Fase.h"
#include "Boitata.h"

namespace Fases {
	void Fase::criarCenario()
	{
		
	}
	void Fase::criarBoitatas()
	{
		Entidades::Personagens::Boitata* b1 = new Entidades::Personagens::Boitata();
		b1->setPosicao({ 1200.f, 500.f });
		lista_ents.incluir(b1);
		GC.incluirInimigo(b1);
	}
	Fase::Fase()
	{

	}
	Fase::~Fase()
	{
	}


}