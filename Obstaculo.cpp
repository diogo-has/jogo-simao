#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		Obstaculo::Obstaculo(float x, float y) : Entidade(), danoso(false) {
		}
		Obstaculo::Obstaculo() : Entidade(), danoso(false) {
		}
		Obstaculo::~Obstaculo() {
		}
		bool Obstaculo::getDanoso() {
			return danoso;
		}
	}
}