#ifndef __CHARACTERISTICS_H_
#define __CHARACTERISTICS_H_

#include "DigitsSequence.h"
#include "SequencesContainer.h"

	class Characteristics {
	public:
		// сколько цифр в последовательности
		static const int sequenceLength_ = 4;
		// сколько цифр принимает участие в загадывании
		static const int symbolsCount_ = 10;
		// максимальное количество всех возможных последовательностей без учетов повторов
		static const int maxSequenceCount_;

		static SequencesContainer getAllSequences();

	private:
		static SequencesContainer allSequences_;
	};

	bool isCorrectSequenceLenght(int);

#endif
