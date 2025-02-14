/**The MIT License (MIT)
Copyright (c) 2017 by Radim Keseg
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "EfxSpike.h"

//public 
void EfxSpike::Show(boolean clear_background, boolean mix_colors){
  if(matrix==NULL) return;

  if( j>=(matrix->numPixelsInRow()) && incr>0 || j<=0 && incr<0  ) incr*=-1;
  j+=incr; if(j<0) j=0;
  for(int y=0;y<matrix->numRows();y++){
    for(int x=0;x<matrix->numPixelsInRow();x++){
         matrix->setPixel(x, y, x<(int)j ? Adafruit_NeoPixel::Color(255, 0, 0): (x==(int)j ? Adafruit_NeoPixel::Color(255*(j-x), 0, 0) : Adafruit_NeoPixel::Color(0, 0, 0)) ); 
    }
  }
  
}

