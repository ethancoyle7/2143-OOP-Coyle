//**********************************************************
///
//Ethan Coyle
//Assignment 8 create class to combine Colors in Color pall
//Dr. Griffin-OOP 2143
//
//Tuesday/Thursday 9:30A.
//
//Due 3/16/21
//
// thee purpose of this assignment was to create a color 
//pallete to hold our various inputted values for RGB
//and store them inside main we utilize the creation of an
// additional color palette to be store which is user
// inputted and store inside of our vectore called Color
//PalletteMixes.. ideally, we are able to store as many color 
//combinations as we want and furthing this, we also call
//the inputted values to display the created mixture
//
//This program also uses the idea of inheritance in C++ by
//taking on some of the former traits of its
//parent class
//////////////////////////////////////////////////////////////
#include <iostream>
#include < vector>

using namespace std;// stadard namespace

// implementation of rgb Color class
// that intialize one instance, or three instance
class RgbColor
{
 private:// private by default
    int RedColor;                    // 0-255 RedColor
    int GreenColor;                  // 0-255 GreenColor
    int BlueColor;                  // 0-255 BlueColor
public: 
    RgbColor();             // def. constructr
    RgbColor(int);          // overloaded 1 Color
    RgbColor(int,int,int);  // overload three Colors
    
    //3 setters for Colors
    void SetRedColor(int);         // set RedColor
    void SetGreenColor(int);         // set GreenColor
    void SetBlueColor(int);         // set BlueColor
   
  // three get functions for Color
  
    int GetRedColor();             // get RedColor
    int GetGreenColor();             //get GreenColor
    int GetBlueColor();             //get BlueColor

    void GrayScale();       // averages  of the Colors
    void AddColor(RgbColor ColorPalleteMixes);// adding Colors to
    //Colorpallete

    //we create a vecotr now to hold our custom added Colors
    // we need to initialize this so values dont change(static)
    //call the RGbColor class and call it ColorPaletteMix
    static vector <RgbColor> ColorPalleteMix;

    // print to the outstream ostream overloading
    friend ostream& operator<<(ostream&,const RgbColor&);

    // overloaded addition operator
    RgbColor operator+(const RgbColor& );


};
//dot operator to calclulate the averages of the three colors
void RgbColor::GrayScale()
{
    BlueColor = GreenColor = RedColor = ((RedColor + GreenColor
      + BlueColor) / 3);// dividing by three b/c R.G.B three 
}


 void RgbColor::AddColor(RgbColor ColorPalleteMixes)
{
	ColorPalleteMix.push_back(ColorPalleteMixes);
}

RgbColor RgbColor::operator+(const RgbColor& other)
{
    //addtion operator overloader
    int RedColor = (this->RedColor + other.RedColor) / 2;
    int GreenColor = (this->GreenColor + other.GreenColor) / 2;
    int BlueColor = (this->BlueColor + other.BlueColor) / 2;

    return *this;//retrun the dereferenced values
}
//this is the default default constructor
RgbColor::RgbColor()
{
    //initialize all to 0
    RedColor = GreenColor = BlueColor = 0;
}
// intialize each to Color
RgbColor::RgbColor(int Color)
{
    RedColor = GreenColor = BlueColor = Color;
}

// assign variable to make new

RgbColor::RgbColor(int r,int g, int b)
{
    //values are store and assigned to respective
    //colors
    RedColor = r;
    GreenColor = g;
    BlueColor = b;
}

//setters with dot operator for grb color class
//dot operator to intial the actual color of inputted color scheme
//dot operator for rgb color class to hold our mixed colors
//inside of a vectore called colorpallete mixes
// this is so we can store a plethora of different mixes if we
//wanted to
void RgbColor:: SetRedColor(int red)
{
    RedColor = red;
}
void RgbColor::SetGreenColor(int green)
{
    GreenColor = green;
}

void RgbColor::SetBlueColor(int blue)
{
    BlueColor=blue;
}


//initialize getters for colors

int RgbColor:: GetRedColor()
{
    return RedColor;
}

int RgbColor::GetGreenColor()
{
    return GreenColor;
}

int RgbColor::GetBlueColor()
{
    return BlueColor;
}

//overload ostream using friend function
 ostream& operator<<(ostream& outfile,const RgbColor& other)
{
    outfile<<"["<<other.RedColor<<","<<other.GreenColor<<
           ","<<other.BlueColor<<"]";
    return outfile;
    //printing out the value of the other color
}


class ColorPallette: public RgbColor
{
private:
   static vector <RgbColor> ColorPalleteMix;
    RgbColor *array;// integer point to dynamic array
    int ArraySize;  //size of te array

public:
    ColorPallette()//default constictor
    {
        ArraySize = 100;//size of out array
        array = new RgbColor [ArraySize];//ask heap for memory
    }
    //single overloaded consturctor
    ColorPallette(int s)
    
    {
        ArraySize = s;
        array = new RgbColor[ArraySize];
    }
    void AddColors(RgbColor a)
    {
        ColorPalleteMix.push_back(a);
    }
    //copy constructor for a new array of 100 like other array
    ColorPallette(const ColorPallette& other)
    {
        ArraySize = other.ArraySize;
        array = new RgbColor[ArraySize];
        for(int i=0;i<ArraySize;i++)
        {
            array[i] = other.array[i];
        }
    }
    ~ColorPallette(){};//destory the 
};

int main() 
{
RgbColor ColorMix1;
ColorPallette ConcoctionMix;// class concotionmix for class
//instance of presets
 RgbColor C1(255, 200, 11);
    RgbColor C2(100, 14, 123);
    RgbColor C3 = C1 + C2;
    cout << C3 << "\n\n";
// first color and second color add together
//addition overload assign to c3
//cout<<ThirdColor<<endl;// print out 3rdColor obj
int Color_Red,Color_Green, Color_Blue;

//user defined colors
cout << "ether value for red green and blue " << endl;
//user inputs values
cin >> Color_Red >> Color_Blue >> Color_Green;
//intialize the functions to set the values of each of the

//user inputted values go to the setter functions to set
//these values in

ColorMix1.SetRedColor(Color_Red);
ColorMix1.SetGreenColor(Color_Green);
ColorMix1.SetBlueColor(Color_Blue);

//now we must utilize the get functions to obtain the stored value
//GETTING RBG COLORS
ColorMix1.GetRedColor();
ColorMix1.GetGreenColor();
ColorMix1.GetBlueColor();
ColorMix1.AddColor(ColorMix1);//adding these to
//instance and colorpallete

    //output the Color mixture

cout<<"our mixture to Color pallete is : "<<
      ColorMix1 <<endl;
// creating another mixture to our concoction Color pallete
//after this is we want to add more we can as well it dont matter


//now for us to utilize the colorpallete class to make 
//our concoction, we utilize color pallete class
//settters
 ConcoctionMix.SetRedColor(Color_Red);
ConcoctionMix.SetGreenColor(Color_Green);
ConcoctionMix.SetBlueColor(Color_Blue);
//getters
ConcoctionMix.GetRedColor();
ConcoctionMix.GetGreenColor();
ConcoctionMix.GetBlueColor();

    ConcoctionMix.AddColors(ConcoctionMix);
    cout <<" our color palate mix is: " <<
     ConcoctionMix << "\n\n";

cout << " we have succesfully utilized "<< 
    "all instaces of colring"<< "\n\n";
return 0;
//ending  the program
}
