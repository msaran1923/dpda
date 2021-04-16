#pragma once


class KernelFunctor {
public:
	virtual double eval(double d) = NULL;
};

class EpanechnikovKernel : public KernelFunctor {
	double eval(double d) override {
		return (3.0 / 4.0) * (1.0 - d * d);
	}
};