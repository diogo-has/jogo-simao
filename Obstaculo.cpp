#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		Obstaculo::Obstaculo() : Entidade(), danoso(false) {
		}
		Obstaculo::~Obstaculo() {
		}
		void Obstaculo::salvarDataBuffer() {
			Entidade::salvarDataBuffer();

			buffer << " " << danoso;
		}
		void Obstaculo::carregar(ifstream& arquivo) {
			Entidade::carregar(arquivo);

			arquivo >> danoso;
		}
		const bool Obstaculo::getDanoso() const {
			return danoso;
		}
	}
}