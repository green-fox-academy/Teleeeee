#include "FractalGenerator.h"
#include "algorithm"


FractalGenerator::FractalGenerator(SDL_Renderer* renderer, int maxDepth) : _renderer(renderer),
                                                                           maxDepth(maxDepth) {}

void FractalGenerator::draw(int x0, int y0, int xm, int ym) {
}

void FractalGenerator::drawFractal(int x0, int y0, int xm, int ym, int depth) {
    int yh = (ym+y0)/2;
    int xh = (xm+x0)/2;

    SDL_RenderDrawLine(_renderer, xh, y0, xh, ym); //vertical
    SDL_RenderDrawLine(_renderer, x0, yh, xm, yh); //horizontal

    if(depth < maxDepth){
        //drawFractal(x0, y0, xh, yh, depth+1);
        drawFractal(xh, y0, xm, yh, depth+1);
        drawFractal(xh, yh, xm, ym, depth+1);
    }
}

void FractalGenerator::drawTriangle(SDL_Renderer* gRenderer , int height, int shiftingPoint, int  shiftingPoint2,  int depth )
{
    double upperLine = height * 0.6;
    double triangleHeight = upperLine / 2;



    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0 /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint + triangleHeight *2,
                       shiftingPoint2 + height / 2 ,
                       shiftingPoint + triangleHeight,
                       shiftingPoint2 );
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0 /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint + triangleHeight,
                           shiftingPoint2 ,
                           shiftingPoint ,
                       shiftingPoint2 + height/2);

//side triangle
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0 /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint  + triangleHeight,
                       shiftingPoint2 ,
                       shiftingPoint ,
                       shiftingPoint2  + height / 2);

    if(depth < maxDepth){
        drawTriangle(gRenderer , height/2,  shiftingPoint - shiftingPoint*2/3,   shiftingPoint2 ,  depth+1 );
        drawTriangle(gRenderer , height/2,  shiftingPoint + height,   shiftingPoint2 - height/2 ,  depth+1 );
        drawTriangle(gRenderer , height/2,  shiftingPoint + height/2,   shiftingPoint2 + height ,  depth+1 );


    }


} //doesnt work

void FractalGenerator::drawHexagonFractal(SDL_Renderer* gRenderer, int height , int shiftingPoint, int  shiftingPoint2, int depth)
{


    double upperLine = height * 0.6;
    double triangleHeight = upperLine / 2;



    SDL_SetRenderDrawColor(gRenderer, 255/*R*/, 0x00 /*G*/, 255 /*B*/, 0 /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint + triangleHeight + upperLine,
                       shiftingPoint2 ,
                       shiftingPoint + triangleHeight,
                       shiftingPoint2 );
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 255 /*G*/, 255/*B*/, 0 /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint + triangleHeight + upperLine,
                       shiftingPoint2  + height,
                       shiftingPoint  +triangleHeight,
                       shiftingPoint2 + height);

//side triangle
    SDL_SetRenderDrawColor(gRenderer, 255/*R*/, 255 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint  + triangleHeight,
                       shiftingPoint2 ,
                       shiftingPoint ,
                       shiftingPoint2  + height / 2);
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 255 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint ,
                       shiftingPoint2  + height / 2,
                       shiftingPoint  + triangleHeight,
                       shiftingPoint2  +height);

// other side triangle
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 255 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint  + upperLine + triangleHeight,
                       shiftingPoint2 ,
                       shiftingPoint  + 2 * upperLine,
                       shiftingPoint2  + height / 2);
    SDL_SetRenderDrawColor(gRenderer, 255 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint  + 2 * upperLine,
                       shiftingPoint2  + height / 2,
                       shiftingPoint  + upperLine + triangleHeight,
                       shiftingPoint2 + height);

    if(depth < maxDepth){
       drawHexagonFractal( gRenderer, height/3, shiftingPoint + height/5, shiftingPoint2,  depth +1);
       drawHexagonFractal( gRenderer, height/3, shiftingPoint + height/5, shiftingPoint2 + height*2/3,  depth +1);
       drawHexagonFractal( gRenderer, height/3, shiftingPoint + height* 3/5, shiftingPoint2 + height*2/3,  depth +1);
       drawHexagonFractal( gRenderer, height/3, shiftingPoint + height* 4/5, shiftingPoint2 + height /3,  depth +1);
       drawHexagonFractal( gRenderer, height/3, shiftingPoint + height* 3/5, shiftingPoint2,  depth +1);
       drawHexagonFractal( gRenderer, height/3, shiftingPoint , shiftingPoint2 + height/3,  depth +1);


    }

}

void FractalGenerator::drawlinePlay(SDL_Renderer* gRenderer, int height , int shiftingPoint, int  shiftingPoint2 ,int depth){
    int a = shiftingPoint;
    int b = shiftingPoint2;
    int a1 = shiftingPoint + height;
    int b1 = shiftingPoint2 + height;
    for (int i = 0; i <=shiftingPoint2 + height ; i = i + 4) {

        SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer,  shiftingPoint + i, shiftingPoint2,   shiftingPoint + b1, shiftingPoint2 + i);

    }
    for (int i = 0; i <= shiftingPoint + height; i = i + 4) {

        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0xff /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer,  shiftingPoint, shiftingPoint2 + i,  shiftingPoint + i, shiftingPoint2+  b1);

    }

    if(depth< maxDepth){
        drawlinePlay(gRenderer,  height/8 ,  shiftingPoint - height/8 ,  shiftingPoint2 - height/8   , depth + 1);
        drawlinePlay(gRenderer,  height/8 ,  shiftingPoint + height/4  ,  shiftingPoint2 - height/8   , depth + 1);

    }



}

void FractalGenerator::drawACarpet(SDL_Renderer* gRenderer, int height , int shiftingPoint, int  shiftingPoint2, int depth){

    SDL_Rect r;
    r.x = shiftingPoint;
    r.y = shiftingPoint2;
    r.w = height;
    r.h = height;

    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );
    SDL_RenderFillRect(gRenderer, &r );

    if(depth < maxDepth){
        drawACarpet( gRenderer, height/2 , shiftingPoint- height/ 2 - shiftingPoint/4 , shiftingPoint2 + shiftingPoint/8  , depth + 1);


    }

}

void FractalGenerator::drawTreee(SDL_Renderer* gRenderer, int x1, int y1, int x2, int y2, int depth){

    int start1 = x1;
    int start2 = y1;
    int start3 = x2;
    int start4 = y2;
    int start5 = start1 + start1/20 ;
    int start6 = start2 + start2/20;
    int start7 = start3;
    int start8 = start4;




    SDL_RenderDrawLine(_renderer, start1 + start1/20,  start2 + start2/20 ,start3, start4 );
    SDL_RenderDrawLine(_renderer, start1,  start2,start3, start4 );
    SDL_RenderDrawLine(_renderer, start1 - start1/20,  start2 + start2/20,start3, start4 );
    if(depth < maxDepth){
        SDL_RenderDrawLine(_renderer, start1 + start1/20,  start2 + start2/20 ,start3, start4 );
        SDL_RenderDrawLine(_renderer, start1,  start2,start3, start4 );
        SDL_RenderDrawLine(_renderer, start1 - start1/20,  start2 + start2/20,start3, start4 );

        start1 = start3  ;
        start2 = start4  ;
        start3 = start1 - start1/3.14  ;
        start4 = start2 + start2/20 ;
        start5 = start7 ;
        start6 = start8 ;
        start7 = start7 + start7/3.14 ;
        start8 = start8 + start8/20 ;
        drawTreee( gRenderer, start1, start2 ,  start3, start4 ,  depth + 1);
        drawTreee( gRenderer, start5, start6 ,  start7, start8 ,  depth + 1);

    }




}
