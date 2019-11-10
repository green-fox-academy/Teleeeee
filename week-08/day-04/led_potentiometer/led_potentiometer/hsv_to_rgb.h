#include <math.h>

//radians = atan2(y, x);
//
//degrees = radians * 180.0 / M_PI;
//
//max = sqrt(xmax*xmax + ymax*ymax);
//distance = sqrt(x*x + y*y) / max;
//
//
//hue = degrees;
//sat = distance;
//
//
//RGB <-  HSV(hue, sat, 1.0);
//

unsigned int rgbColor(unsigned int red, unsigned int green, unsigned int blue)
{
    red   = (red   & 0xFF) << 16;
    green = (green & 0xFF) << 8;
    blue  = (blue  & 0xFF) << 0;

    return (red | green | blue);
}

double crop(double value, double min, double max){
    if(value < min) return min;
    if(value > max) return max;
    return value;
}


unsigned int hsvColor(double hue, double saturation, double value)
{
/*
HSV to RGB conversion formula
When 0 ? H < 360, 0 ? S ? 1 and 0 ? V ? 1:
C = V * S
X = C * (1 - |(H / 60°) mod 2 - 1|)
m = V - C
R', G', B' -> depending on which 60deg section hue is in
(R,G,B) = ((R'+m)*255, (G'+m)*255, (B'+m)*255)
*/
    double H, S, V;
    double C, X, m;
    double R_, G_, B_;
    double R, G, B;

    H = fmod(hue, 360.0);
    S = crop(saturation, 0.0, 1.0);
    V = crop(value, 0.0, 1.0);

    C = V * S;
    X = C * (1 - fabs( fmod( (H/60.0), 2.0 ) - 1 ) );
    m = V - C;

    if( H >= 0.0 && H < 60.0 )
    {
        R_ = C;
        G_ = X;
        B_ = 0.0;
    }
    else if( H >= 60.0 && H < 120.0 )
    {
        R_ = X;
        G_ = C;
        B_ = 0.0;
    }
    else if( H >= 120.0 && H < 180.0 )
    {
        R_ = 0.0;
        G_ = C;
        B_ = X;
    }
    else if( H >= 180.0 && H < 240.0 )
    {
        R_ = 0.0;
        G_ = X;
        B_ = C;
    }
    else if( H >= 240.0 && H < 300.0 )
    {
        R_ = X;
        G_ = 0.0;
        B_ = C;
    }
    else
    {
        R_ = C;
        G_ = 0.0;
        B_ = X;
    }

    R = (R_ + m) * 255;
    G = (G_ + m) * 255;
    B = (B_ + m) * 255;

    return rgbColor( (unsigned int)R, (unsigned int)G, (unsigned int)B );
}