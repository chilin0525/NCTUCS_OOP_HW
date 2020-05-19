#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
using namespace std;

double aa;
typedef struct
{
    BYTE b;
    BYTE g;
    BYTE r;
}RGB;

int main(int argc, char* argv[])
{
	aa=atof(argv[3]);
	//cout<<"argv[3]"<<aa<<endl;
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    FILE* pfin =fopen(argv[1],"rb");
    FILE* pfout = fopen( argv[2],"wb");
    fread(&fileHeader,sizeof(BITMAPFILEHEADER),1,pfin);
    fread(&infoHeader,sizeof(BITMAPINFOHEADER),1,pfin);
	int height,weight;
	height=0;
	weight=0;
	height=infoHeader.biHeight;
	weight=infoHeader.biWidth;
    if( infoHeader.biBitCount >= 1)
    {
        int size = height * weight;
        RGB img[height][weight];
        RGB img2[weight][height];
        fread( img , sizeof(RGB) , size , pfin );
        
  
        
 //----------------------------------
 
		int i, j;  
      for (i=0; i<height; i++){
			for (j=0 ; j < weight ; j++ )
			{ 
			
			int temp=0;
			try{

					if(img[i][j].b*aa>255){
						img2[i][j].b=255;
						temp++;
					}
					else{
						img2[i][j].b=img[i][j].b*aa;
					}
					
				
					if(img[i][j].g*aa>255){
						img2[i][j].g=255;
						temp++;
					}
					else{
						img2[i][j].g=img[i][j].g*aa;	
					}
					
				
					if(img[i][j].r*aa>255){
						img2[i][j].r=255;
						temp++;
					}
					else{
						img2[i][j].r=img[i][j].r*aa;	
					}
					
				if(temp>0){
					throw j;
				}	
			}
				
				catch(int jj){
     				cout<<"Pixel("<<i<<","<<jj<<") is overflow."<<endl; 
	  			}	
			}
		}
		
//-----------------------------------
     
        fwrite( &fileHeader , sizeof(fileHeader) , 1 , pfout );
        fwrite( &infoHeader , sizeof(infoHeader) , 1 , pfout );
        fwrite( img2 , sizeof(RGB) , size , pfout );
    }
    fclose(pfin);
    fclose(pfout);

	return 0;
}
