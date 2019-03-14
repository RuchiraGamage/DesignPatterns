#pragma once
#include<memory>
#include<iostream>
#include<string>
#include<vector>
#include<ostream>

struct Neuron 
{
	std::vector<Neuron*> in, out;
	int id;
	Neuron()
	{
		static int id = 1;
		this->id = id++;
	}

	void connect_to(Neuron& other)
	{
		out.push_back(&other);
		other.in.push_back(this);
	}

	friend std::ostream& operator<<(std::ostream& oss,Neuron& obj)
	{
		for (Neuron* n:obj.in)
		{
			oss << n->id << "\t-->\t[" << obj.id << "]" << std::endl;
		}

		for(Neuron* n :obj.out)
		{
			oss << "[" << obj.id << "]\t-->\t" << n->id << std::endl;
		}
		return oss;
	}

	template<typename T>
	void connect_to(T& other)
	{
		for(auto& target : other)
		{
			this->connect_to(target);
		}
	}
};

struct NeuronLayer :std::vector<Neuron> 
{
	NeuronLayer(int count)
	{
		while(count-->0)
		{
			emplace_back(Neuron{});
		}
	}

	friend std::ostream& operator<<(std::ostream& oss, NeuronLayer& neuroLayer)
	{
		for(auto& u: neuroLayer)
		{
			oss << u;
		}
		return oss;
	}

	template <typename T>
	void connect_to(T& other)
	{
		
	for (Neuron& from : *this)
	{
		from.connect_to(other);
	}
	}
};


