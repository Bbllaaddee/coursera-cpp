#include <iostream>
#include <algorithm>
#include <vector>

class FunctionPart
{
public:
	FunctionPart(char new_operation, double new_value) : operation(new_operation), value(new_value) {}
	double Apply(double source_value) const
	{
		if(operation=='+') { return source_value + value; }
		else if(operation=='-') { return source_value - value; }
	}
	void Invert()
	{
		if(operation=='+') { operation = '-'; }
		else if(operation=='-') { operation = '+'; }
	}
private:
	char operation;
	double value;
};

class Function
{
public:
	void AddPart(char operation, double value) { parts.push_back({operation,value}); }
	double Apply(double value) const
	{
		for(const auto& part : parts) { value = part.Apply(value); }
		return value;
	}
	void Invert()
	{
		for(auto& part : parts) { part.Invert(); }
		std::reverse(parts.begin(), parts.end());
	}
private:
	std::vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params, const Image& image)
{
	Function function;
	function.AddPart('-', image.freshness * params.a + params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image)
{
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params, const Image& image, double weight)
{
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}
