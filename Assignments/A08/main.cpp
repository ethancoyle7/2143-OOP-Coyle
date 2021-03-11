#include <iostream>

using namespace std;

// this show the use of copy constructor using dynam
//allocated memory due to the association with
//pointers that makes a deep copy
class NumContainer
{
 private:
  
    int *array;     // pointer using dynam mem allocation
    int size;       
public:
    NumContainer()
    {
        size = 100;
        array = new int[size];
    }
    NumContainer(int s)
    {
        size = s;
        array = new int[size];
    }
    NumContainer(const NumContainer& other)
    {
        size = other.size;
        array = new int[size];
        for(int i=0;i<size;i++)
        {
            array[i] = other.array[i];
        }
    }
};


// implementation of rgb color class
// that intialize one instance, or three instance
class RgbColor
{
 private:// private by default
    int red;                    // 0-255 red
    int green;                  // 0-255 green
    int blue;                  // 0-255 blue
public: 
    RgbColor();             // def. constructr
    RgbColor(int);          // overloaded 1 color
    RgbColor(int,int,int);  // overload three colors
    
    //3 setters for colors
    void SetR(int);         // set red
    void SetG(int);         // set green
    void SetB(int);         // set blue
   
  // three get functions for color
  
    int GetR();             // get red
    int GetG();             //get green
    int GetB();             //get blue

    void GrayScale();       // averages  of the colors

    // print to the outstream
    friend ostream& operator<<(ostream&,const RgbColor&);

    // overloaded addition operator
    RgbColor operator+(const RgbColor& );

};



class ColorPallete : public RgbColor//class names color palatte
 //that has a access to the rgbcolor class to grab the colors
{
private:
    vector<int> ColorMix;//pass in private colormix palate

public:

    const vector<int> &get_ColorMix() const
    {
        return ColorMix;//grab the colors and combine
    }

    void addColor(const int &color)//instance to add a color
    {
        ColorMix.push_back(color);
    }
};


RgbColor RgbColor::operator+(const RgbColor& other)
{
    int red = (this->red + other.red) / 2;
    int green = (this->green + other.green) / 2;
    int blue = (this->blue + other.blue) / 2;

    return *this;
}
//default constructor
RgbColor::RgbColor()
{
    red = green = blue = 0;
}
// intialize each to color
RgbColor::RgbColor(int color)
{
    red = green = blue = color;
}

// assign variable to make new

RgbColor::RgbColor(int r,int g, int b)
{
    red = r;
    green = g;
    blue = b;
}
//overload ostream using friend function
friend ostream& operator<<(ostream& outfile,const RgbColor& other)
{
    outfile<<"["<<other.red<<","<<other.green<<","<<other.blue<<"]";
    return outfile;
}

int main() 
{
    vector<RgbColor>ColorMix;// creating vector of color mixing pallatee
 
    RgbColor C1(255,200,11);  //create instance of c1
    RgbColor C2(100,14,123);// create instance of c2
    RgbColor C3 = C1 + C2;// first color and second color add together addition overload assign to c3
    cout<<Color3<<endl;// print out c3 obj
  return 0;
}
