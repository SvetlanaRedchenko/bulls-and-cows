#ifndef __GAME_H_
#define __GAME_H_

#include <memory>

class ProposalInterface;
class QuestionInterface;

class Game {
    public:
    static int play(
	    std::shared_ptr<ProposalInterface>,
	    std::shared_ptr<QuestionInterface>);
};

#endif
