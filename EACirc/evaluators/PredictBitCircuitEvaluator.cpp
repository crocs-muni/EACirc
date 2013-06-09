#include "PredictBitCircuitEvaluator.h"

PredictBitCircuitEvaluator::PredictBitCircuitEvaluator()
    : IEvaluator(EVALUATOR_BIT) { }

void PredictBitCircuitEvaluator::evaluateCircuit(unsigned char* outputs, unsigned char* correctOutputs, unsigned char* usePredictorsMask, int* pMatch, int* pTotalPredictCount, int* predictorMatch = NULL){
	// OUTPUT LAYER ENCODES DIRECTLY THE EXPECTED BITS
	// COUNT NUMBER OF CORRECT BITS 
    for (int out = 0; out < pGlobals->settings->circuit.sizeOutputLayer; out++) {
		for (int bit = 0; bit < BITS_IN_UCHAR; bit++) {
			if (usePredictorsMask[out] == 1) {
				// COMPARE VALUE ON bit-th POSITION
				if ((outputs[out] & (unsigned char) pGlobals->precompPow[bit]) == (correctOutputs[out] & (unsigned char) pGlobals->precompPow[bit])) {
					(*pMatch)++;
					if (predictorMatch != NULL) (predictorMatch[out])++;
				}
	                    
				(*pTotalPredictCount)++;                    
			}
		}
	}
}

string PredictBitCircuitEvaluator::shortDescription() {
    return "No description yet.";
}