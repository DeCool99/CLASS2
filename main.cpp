#include "raylib.h"
#include <cstdio>

#include "raylib.h"

struct Gator {
    Rectangle rect;
    Vector2 speed;
    Color color;
};

int main(){
 const int windowWidth{1000};
 const int windowHeight{800};
 const int width{100};
 const int height{100};
 const int gravity{1};

int posY{windowHeight - height};
int velocity{-10};
velocity += gravity;

InitWindow(windowWidth, windowHeight, "Mr. Gator!");
InitAudioDevice();

Gator gator;
gator.rect.height = 50;
gator.rect.width = 50;
gator.color = GREEN;
gator.rect.x = windowWidth/8;
gator.rect.y = windowHeight-gator.rect.height;

//Music music = LoadMusicStream("resources/sound.wav");//
//Sound sound = LoadSound("resources/pickUp.wav");//
//PlayMusicStream(music);//

SetTargetFPS(60);  
	while(!WindowShouldClose()){

//UpdateMusicStream(music); 

BeginDrawing();
DrawRectangleRec(gator.rect, gator.color);
if(posY >= windowHeight - height) {
	velocity = 0;
} else {
	velocity += gravity;
}

if(IsKeyPressed(KEY_SPACE))
{
	velocity -= 10;
}

posY += velocity;

ClearBackground(WHITE); 
EndDrawing();
}	
CloseAudioDevice(); 
CloseWindow();
}