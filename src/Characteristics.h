#ifndef __CHARACTERISTICS_H_
#define __CHARACTERISTICS_H_

#include "DigitsSequence.h"
#include "SequencesContainer.h"

	class Characteristics {
	public:
		// ������� ���� � ������������������
		static const int sequenceLength_ = 4;
		// ������� ���� ��������� ������� � �����������
		static const int symbolsCount_ = 10;
		// ������������ ���������� ���� ��������� ������������������� ��� ������ ��������
		static const int maxSequenceCount_;

		static SequencesContainer getAllSequences();

	private:
		static SequencesContainer allSequences_;
	};

	bool isCorrectSequenceLenght(int);

#endif
