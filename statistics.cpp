#include <iostream>
#include <limits>
#include <cmath>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
};

class Mean : public IStatistics {
public:
	Mean() {
	    m_mean = 0;
	    sum = 0;
		count = 0; 
	}

	void update(double next) override {
			count += 1;
			sum += next;
			m_mean = sum/count;
	}

	double eval() const override {
		return m_mean;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double m_mean;
	int count;
	double sum;
};

class Std : public IStatistics {
public:
	Std() {}

	void update(double next) override {
			count += 1;
			sum += next;
			m_mean = sum/count;
			sum2 += pow((next - m_mean),2);
			std = sqrt(sum2/(count-1));
	}

	double eval() const override {
		return std;
	}

	const char * name() const override {
		return "std";
	}
    
private:
	double std;
	double m_mean;
	int count;
	double sum;
	double sum2;
};


int main() {

	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];


	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	std::cout << "\n";
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}