#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		Obstaculo::Obstaculo(float x, float y) : Entidade(), danoso(false) {
		}
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
		bool Obstaculo::getDanoso() {
			return danoso;
		}
	}
}