#ifndef COMB_STRAT_CPP
#define COMB_START_CPP

class individual;

class combinationStrategy{
	public:
		combinationStrategy(){};
		virtual individual combine(individual,individual);
};

#endif // comb strat cpp//