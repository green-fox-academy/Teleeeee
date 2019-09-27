#ifndef FRACTALS_FRACTALGENERATOR_H
#define FRACTALS_FRACTALGENERATOR_H

#include <SDL_render.h>


class FractalGenerator {
public:
    FractalGenerator(SDL_Renderer* renderer, int maxDepth);
    void draw(int x0, int y0, int xm, int ym);
    void drawFractal(int x0, int y0, int xm, int ym, int depth);
    void TriangleFractal(int x0, int y0, int xm, int ym, int depth);
    void drawHexagonFractal(SDL_Renderer* gRenderer, int height , int shiftingPoint, int  shiftingPoint2, int depth);
    void drawlinePlay(SDL_Renderer* gRenderer, int height , int shiftingPoint, int  shiftingPoint2, int depth );
    void drawTriangle(SDL_Renderer* gRenderer , int height, int shiftingPoint, int  shiftingPoint2,  int depth );
    void drawACarpet(SDL_Renderer* gRenderer, int height , int shiftingPoint, int  shiftingPoint2, int depth);
    void drawTreee(SDL_Renderer* gRenderer, int x1, int y1, int y2, int y3, int depth);

private:
    SDL_Renderer* _renderer;
    int maxDepth;
};


#endif //FRACTALS_FRACTALGENERATOR_H