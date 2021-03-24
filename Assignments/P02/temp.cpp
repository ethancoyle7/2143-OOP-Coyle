#include<sstream>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


//below is an instance of our node that will create a node to print out to 
//and link to other nodes
class Node
{
private:
	//private attributes
	string EdgeColor;
	string FillColor;
	string OutlineColor;
	string EdgeStyle;
	string Name;

public:
	Node(){};// default constructor
	//overloaded default method for our node
	Node(string name, string fillcolor, string edge, string outline)
	{
		Name = name;
		FillColor = fillcolor;
		EdgeStyle = edge;
		OutlineColor = outline;
		EdgeColor= EdgeCol;
	}

	//setters for out attributes
	void SetEdgeStyle(string);
	void SetOutlineColor(string);
	void SetFillColor(string);
	void SetName(string);
	void SetEdgeColor(string);

	//getters for our attributes
	string getEdgeStyle();
	string getOutlineColor();
	string getFillColor();
	string getName();
	string getEdgeColor();
	
	~Node(){};// destructor for our node class
};

//set the pointer edge style
void Node::SetName(string name)
{
	Name = name;//name of the node
}
void Node::SetEdgeStyle(string edge)
{
	EdgeStyle = edge;//assign edge to edgestyle
}
//set the outline color attribute
void Node::SetOutlineColor(string color)
{
	OutlineColor = color;//assign outline color
}
//set the fill attribute
void Node::SetFillColor(string Fill)
{
	FillColor = Fill;//assign the fill color
}
void Node::SetEdgeColor(string EdgeCol)
{
	EdgeColor = EdgeCol;
}

//getters to obtain the attribute names

string Node::getName()
{
	return Name;
}
string Node::getOutlineColor()
{
	return OutlineColor;// return the string color
}

string Node::getEdgeStyle()
{
	return EdgeStyle;//return the edge style
}
string Node::getFillColor()
{
	return FillColor; // return the fill color attribute
}
string Node::getEdgeColor()
{
	return EdgeColor; // return the fill color attribute
}

